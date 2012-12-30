///////////////////////////////////////////////////////////////////
// tricks on the simply copy
// 	tar->value = tar->next->value;
// 	tar->next = tar->next->next;
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
	int value;
	Node *next;
};

template <typename T>
class LinkedList {
private:
	Node _head, _end, *_curr, *_last;

public:
	LinkedList() { 
		_head.next = NULL;
		_end.next = NULL;
		_curr = &_head;
		_last = NULL;
	}

	Node *head() { return &_head; }

	Node *end() { return &_end; }

	bool empty() { return _head.next == NULL; }

	Node *iterate(Node *curr) {
		Node *retVal;
		(retVal = curr->next) == &_end ? curr = &_head : curr = retVal;
		return retVal;
	}

	void push_back(T value) {
		Node *newNode = new Node();
		newNode->value = value;
		newNode->next = &_end;
		if (_head.next == NULL) _head.next = _last = newNode;
		else { _last->next = newNode; _last = _last->next; }
	}
};

void print(LinkedList<int> *ll) {
	if (ll->empty()) return;

	Node *iter = ll->head();
	while ((iter = ll->iterate(iter)) != ll->end()) { cout << iter->value << " "; }

	cout << endl;
}

void remove_middle(LinkedList<int> *ll, Node *tar) {
	Node *next 	= tar->next;
	tar->value	= next->value;
	tar->next	= next->next;
	delete next;
}

int main() {
	srand(time(0)); int size = 20, mid = 10; LinkedList<int> ll;

	for (int i = 0; i < size; ++i) { ll.push_back(rand() % size); }
	print(&ll);

	Node *iter = ll.head();
	for (int i = 0; i < mid; ++i) { iter = ll.iterate(iter); }
	remove_middle(&ll, iter);
	print(&ll);
	
	return 0;
}
