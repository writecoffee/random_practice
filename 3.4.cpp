/////////////////////////////////////////////////////////////////////////////
// -- 	we know that any disk(s) with level-2 could be moved to any tower by 
// 	using a temporary buffer tower; 
// --	if disks with level-n could be moved to any tower, it requires that 
// 	its level-(n-1) sub-disks could also be moved to any tower;
// --	QED!
/////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <stack>
using namespace std;

static int STT_I = 0;

template <typename T>
class Tower {
private:
	stack<T> _s; int _height, _index;

public:
	Tower() : _height(0), _index(STT_I++) { }

	int height() { return _height; }

	bool push(T val) {
		if (!_s.empty() && val > _s.top()) { return false; }
		else { _s.push(val); ++_height; return true; }
	}
	
	bool move_top_to(Tower<T> *dest) {
		if (dest->push(_s.top())) { _s.pop(); --_height; return true; }
		else { return false; }
	}

	void move_disks(Tower<T> *dest, Tower<T> *buff, int lev) {
		if (lev < 0) { return; }
		
		move_disks(buff, dest, lev - 1);
		move_top_to(dest);
		buff->move_disks(dest, this, lev - 1);
	}

	void print() {
		if (_height == 0) { return; }

		stack<T> ts;
		printf("Tower %d\n", _index);

		// print values from top to bottom and store the popped to temp stack
		for (int i = 1; !_s.empty(); ++i) { 
			printf("lev %d weigh: %d\n", i, _s.top()); 
			ts.push(_s.top()); 
			_s.pop(); 
		}

		while (!ts.empty()) { _s.push(ts.top()); ts.pop(); }
	}
};


int main() {
	Tower<int> towers[3]; int size = 10;
	
	for (int i = 0; i < size; ++i) { towers[0].push(size - i); }
	towers[0].print();
	towers[0].move_disks(&towers[2], &towers[1], towers[0].height() - 1);
	towers[2].print();

	return  0;
}
