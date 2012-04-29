///////////////////////////////////////////////////////////////////
// find nth to last element:
// 	set pos(pursuer) + n = pos(pursuee)
//	iterate them till the end
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
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
		Node *retVal = curr->next;
		if (retVal == &_end) _curr = &_head;
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

int find_n_of_tail(LinkedList<int> *ll, int n) {
	Node *pursuer = ll->head();
	Node *pursuee = ll->head();
	
	for (int i = 0; i < n; ++i) { pursuee = ll->iterate(pursuee); }
	while (pursuee != ll->end()) {
		pursuee = ll->iterate(pursuee);
		pursuer = ll->iterate(pursuer);
	} 

	return pursuer->value;
}

int main() {
	int size = 20;
	LinkedList<int> ll;
	for (int i = 0; i < size; ++i) { ll.push_back(rand() % size); }
	print(&ll);
	cout << find_n_of_tail(&ll, 4) << endl;
	
	return 0;
}
