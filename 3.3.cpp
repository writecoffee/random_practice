///////////////////////////////////////////////////////////////////////
// store stacks in a list; if we need to pop values at a designated 
// stack, 'double-ended' stack is requested
///////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define MAX_SIZE 5

//*****************************************************************/
// Two-way stack, which stores the value in a double-ended queue,
// and with the same attributes with single-way stack
// 	-- see @remove_bottom 
//	-- see @SingleStacke
//*****************************************************************/
template <typename T>
class TwoWayStack {
private:
	deque<T> _q; int _mx;

public:
	TwoWayStack(int max_size) : _mx(max_size) { }

	bool push(T val) { 
		if (full()) { return false; } 
		else { _q.push_back(val); return true; } 
	}

	bool pop(T &val) {
		if (empty()) { return false; }	
		else { val = _q.back(); _q.pop_back(); return true; }
	}

	bool empty() { return _q.size() == 0; }

	bool full() { return _q.size() >= _mx; }

	bool remove_bottom(T &val) {
		if (empty()) { return false; }
		else { val = _q.front(); _q.pop_front(); return true; }
	}
};

template <typename T>
class SingleStack {
private:
	stack<T> _s; int _ms;

public:
	SingleStack(int max_size) : _ms(max_size) { }

	bool push(T val) { 
		if (full()) { return false; }
		else { _s.push(val); return true; }
	}

	bool pop(T &val) { 
		if (empty()) { return false; } 
		else { val = _s.top(); _s.pop(); return true; }
	}

	bool empty() { return _s.size() == 0; }

	bool full() { return _s.size() >= _ms; }
};

template < typename T, typename stack_type = SingleStack<T> >
class SetOfStacks {
private:
	vector<stack_type *> _sl;
	
public:
	void push(T val) { 
		if (_sl.empty() || _sl.back()->full()) {
			stack_type *ns = new stack_type(MAX_SIZE);
			ns->push(val); _sl.push_back(ns); 
		} else { _sl.back()->push(val); }
	}

	bool pop(T &val) {
		if (_sl.empty()) return false;
		else {
			_sl.back()->pop(val);
			if (_sl.back()->empty()) { _sl.pop_back(); }
			return true;
		}
	}

	bool empty() { return _sl.empty(); }

	unsigned int stack_cnt() { return _sl.size(); }

	bool pop_at(T &val, int sn) {
		typedef typename vector<stack_type *>::iterator iter; T bv;

		if (sn > stack_cnt() - 1) { return false; }
		else if (_sl[sn]->pop(val)) 
		{
			for (iter i = _sl.begin() + sn, j = i + 1; j != _sl.end(); ++i, ++j) 
			{
				if ((*j)->remove_bottom(bv)) { 
					(*i)->push(bv); 

					// exhaust the last stack
					if ((*j)->empty()) { _sl.pop_back(); break; }

				} else { return false; }
			}

			return true;
		}
	}
};

int main() {
	SetOfStacks<int> sgls; SetOfStacks< int, TwoWayStack<int> > tws; int rv, pv, tn = 16;

	for (int i = 0; i < tn; ++i) { 
		sgls.push(pv = rand() % 100); 
		printf("single stack push: %d\n", pv); 
	}

	while (sgls.pop(rv)) { printf("single stack pop: %d\n", rv); }

	for (int i = 0; i < tn /** 2*/; ++i) {
		tws.push(pv = rand() % 100);
		printf("two-way stack push: %d\n", pv);
	}

	while (tws.pop_at(rv, 0)) { printf("two-way stack pop: %d\n", rv); }
	
	return 0;
}
