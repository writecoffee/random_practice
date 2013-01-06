//////////////////////////////////////////////////////////////////////////
// use two stack a, b to store "newest" values and "oldest" values
// respectively. the trick is that prepare "oldest" values for b when
// necessary; otherwise, b is just a lazy stack
//////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

template <typename T>
class Queue {
private:
	stack<T> _a, _b;

public:
	void push_back(T val) {
		_a.push(val);
	}

	bool remove_front(T &val) {
		// remove front value from _b
		if (!_b.empty()) { val = _b.top(); _b.pop(); return true; }

		// no value could be retrieved from this "queue"
		if (_a.empty()) { return false; }

		// prepare _b before retrieving its "front" value
		while (!_a.empty()) { _b.push(_a.top()); _a.pop(); }

		val = _b.top(); _b.pop(); return true;
	}

	bool front(T &val) {
		// peek front value from _b
		if (!_b.empty()) { val = _b.top(); return true; }

		// no value could be retrieved from this "queue"
		if (_a.empty()) { return false; }

		// prepare _b before retrieving its "front" value
		while (!_a.empty()) { _b.push(_a.top()); _a.pop(); }

		val = _b.top(); return true;
	}

	bool empty() { return _a.empty() && _b.empty(); }
};



int main() {
	Queue<int> q; int length = 10, pv, rv;

	for (int i = 0; i < length; ++i) { 
		q.push_back(pv = rand() % 100); printf("push %d\n", pv); 

		if (rand() % 2) { 
			q.remove_front(rv); 
			printf("remove front: %d\n", rv); 
		}
	}

	while (!q.empty()) { q.remove_front(rv); printf("remove front: %d\n", rv); }

	return 0;
}
