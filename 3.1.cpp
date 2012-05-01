////////////////////////////////////////////////////////////////////////////////
// use a linked list to record free slot in the sequence table
// the randomized test case's result is like:
//	push 1 with 1
//	push 1 with 1
//	push 0 with 0
//	push 1 with 1
//	push 2 with 2
//	push 1 with 1
//	push 1 with 1
//	push 0 with 0
//	push 0 with 0
//	push 1 with 1
//	S0 pop: 0
//	S0 pop: 0
//	S0 pop: 0
//	S1 pop: 1
//	S1 pop: 1
//	S1 pop: 1
//	S1 pop: 1
//	S1 pop: 1
//	S1 pop: 1
//	S2 pop: 2
// which print the stacks values one by one
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define S1 0
#define S2 1
#define S3 2

template <typename T>
struct Node { T value; int prev; };

template <typename T> 
class Stack {
private:
	Node<T> **_table; int _top[3]; int _size; int _num_of_used; list<int> _fl;

public:
	Stack(int size) : _size(size), _num_of_used(0) {
		_table = new Node<T> *[size]; 
		memset(_table, 0, sizeof(_table));
		memset(_top, -1, sizeof(_top));
		for (int i = 0; i < size; ++i) _fl.push_back(i);
	}

	bool push(T val, int stack_no) {
		if (stack_no > 2 || stack_no < 0) return false;
		if (full()) return false;

		Node<T> *nn	= new Node<T>(); 
		nn->value	= val; 
		nn->prev	= _top[stack_no];

		// maintain the free slots (we consume 1 slot here!)
		{ _top[stack_no] = _fl.front(); _fl.pop_front(); }

		_table[_top[stack_no]] = nn; ++_num_of_used;
		return true;
	}

	bool pop(T &val, int stack_no) {
		if (stack_no > 2 || stack_no < 0) return false;
		if (empty(stack_no)) return false;
		
		Node<T> *retr = _table[_top[stack_no]];

		// maintain the free slots (we restore 1 slot here!)
		{ _fl.push_back(_top[stack_no]); }

		_table[_top[stack_no]]	= NULL;
		_top[stack_no]		= retr->prev;
		val			= retr->value;

		--_num_of_used;
		return true;
	}
	
	bool empty(int stack_no) { return _top[stack_no] == -1; }

	bool full() { return _num_of_used >= _size; }
};

void print(Stack<int> *sk, int stack_no) {
	int val; while (sk->pop(val, stack_no)) { printf("S%d pop: %d\n", stack_no, val); }
}

int main() {
	int size = 10, sn, val; Stack<int> s(size); 
	while (s.push((sn = val = rand() % 3), sn)) { printf("push %d with %d\n", sn, val); }
	print(&s, S1); print(&s, S2); print(&s, S3);

	return 0;
}
