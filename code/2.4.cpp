///////////////////////////////////////////////////////////////////////////////
// the problem may just want to test the testee's recursion intuition; so 
// an onsite test I think I might just need to write the recursive code rather
// than implementing a customized LinkedList plus an operator overload
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node {
	int value;
	Node *next;
};

template <typename T>
class LinkedList {
private:
	Node *_tail, *_curr, _head, _end;

public:
	LinkedList() { _head.next = _end.next = NULL; _tail = _curr = &_head; }

	Node *head() { return &_head; }

	Node *end() { return &_end; }

	bool empty() { return _head.next == NULL; }

	Node *push_back(int value) {
		Node *newNode	= new Node();
		newNode->value	= value;
		newNode->next	= &_end;		
		
		if (empty()) { _head.next = _tail = newNode; }
		else { _tail->next = newNode; _tail = newNode; } 
	}

	Node *iterate(Node *iter) { return iter->next; }

	LinkedList operator+(LinkedList &ll2) {
		Node *iter1 = this->head();
		Node *iter2 = ll2.head();	
		int val, carr = 0;
		LinkedList r;

		while ((iter1 = this->iterate(iter1)) != this->end() &&
			(iter2 = ll2.iterate(iter2)) != ll2.end()) {
			if ((val = iter1->value + iter2->value + carr) >= 10) { val -= 10; carr = 1; }
			else carr = 0;
			r.push_back(val);
		}

		if (iter2 != ll2.end()) { 
			while ((iter2 = ll2.iterate(iter2)) != ll2.end()) {
				if ((val = iter2->value + carr) >= 10) { val -= 10; carr = 1; }
				else carr = 0;
				r.push_back(val);
			}

		} else if (iter1 != this->end()) {
			while ((iter1 = this->iterate(iter1)) != this->end()) {
				if ((val = iter1->value + carr) >= 10) { val -= 10; carr = 1; }
				else carr = 0;
				r.push_back(val);
			}
		} 

		if (carr == 1) r.push_back(carr);
		return r;
	}
};

void print(LinkedList<int> *ll) {
	if (ll == NULL || ll->empty()) return;
	Node *iter = ll->head();
	while ((iter = ll->iterate(iter)) != ll->end()) { printf("%d ", iter->value); }
	printf("\n");
}

int main() {
	int len1 = 5, len2 = 10; LinkedList<int> ll1, ll2;
	for (int i = 0; i < len1; ++i) ll1.push_back(rand() % 10); 
	for (int i = 0; i < len2; ++i) ll2.push_back(rand() % 10);
	print(&ll1); print(&ll2);

	LinkedList<int> ll3 = ll1 + ll2;
	print(&ll3);
}
