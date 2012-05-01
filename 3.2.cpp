///////////////////////////////////////////////////////////////////
// use two stacks to store 'common' values and min respectively
// 	-- 'replace' min value every step of push and pop
//	-- O(1) time for each operation
///////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstdio>
#include <stack>
using namespace std;

#define MAX_VALUE 99999

template <typename T>
class MinStack {
private:
	stack<T> _min_s;
	stack<T> _s;

public:
	MinStack() { _min_s.push(MAX_VALUE); }

	void push(T val) {
		if (val < _min_s.top()) { _min_s.push(val); }
		_s.push(val);
	}

	bool pop(T &val) {
		if (empty()) return false;
		else {
			val = _s.top(); _s.pop(); 
			if (val == _min_s.top()) { _min_s.pop(); }
			return true;
		}
	}

	bool empty() { return _s.empty(); }

	bool min(T &retr) { 
		if (empty()) return false; 
		retr = _min_s.top(); return true; 
	}
};

int main() {
	int size = 10, pv, mv; MinStack<int> ms;

	for (int i = 0; i < size; ++i) { 
		ms.push(pv = rand() % 100); 
		ms.min(mv); printf("push %d, min: %d\n", pv, mv); 
	}

	while (ms.pop(pv)) { ms.min(mv); printf("pop %d, min: %d\n", pv, mv); }

	return 0;
}
