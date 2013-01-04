////////////////////////////////////////////////////////////////////////////////////////
// let V(nd_t) = 2V(nd_r), so S(nd_t) = 2S(nd_r) = 2s
// the point where nd_r and nd_t meet is as follows: 
// 	2s = s + nr 	...(1)
// 	d + x = s 	...(2)
// in the meanwhile, if assume nd_r and nd_t depart at the loop start, we have:
// 	s = nr		...(3)
// substitute 's' in (3) with (2), then we have:
// 	d = nr - x
//	  = (n - 1)r + (r - x) 
// 	  = (n - 1)r + (l - d - x)
// QED!
////////////////////////////////////////////////////////////////////////////////////////

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
	Node *_tail, *_curr, _head, _end; int _len;

public:
	LinkedList() : _len(0) { _head.next = _end.next = NULL; _tail = _curr = &_head; }

	int length() { return _len; }

	Node *head() { return &_head; }

	Node *end() { return &_end; }

	bool empty() { return _head.next == NULL; }

	void push_back(int value) {
		Node *newNode	= new Node();
		newNode->value	= value;
		newNode->next	= &_end;		
		
		if (empty()) { _head.next = _tail = newNode; }
		else { _tail->next = newNode; _tail = newNode; } 
		++_len;
	}

	Node *iterate(Node *iter) { return iter->next; }
};

void print(LinkedList<int> *ll) {
	if (ll == NULL || ll->empty()) return;
	Node *iter = ll->head();
	while ((iter = ll->iterate(iter)) != ll->end()) { printf("%d ", iter->value); }
	printf("\n");
}

Node *find_loop_start(LinkedList<int> *ll) {
	if (ll->length() < 3) return NULL;

	Node *t = ll->iterate(ll->head()), *r = ll->iterate(ll->iterate(ll->head()));
	while (t != ll->end() && r != ll->end() && r->next != ll->end() && t != r) {
		t = ll->iterate(t); r = ll->iterate(ll->iterate(r));
	} 

	if (t == ll->end() || r == ll->end()) return NULL;

	t = ll->head();
	while (t != r) { t = ll->iterate(t); r = ll->iterate(r); }

	return t; 
}

void set_loop(LinkedList<int> *ll, int lp_beg) {
	Node *iter = ll->head(), *lp = ll->head();

	while ((iter = ll->iterate(iter))->next != ll->end());
	for (int i = 0; i <= lp_beg; ++i) { lp = ll->iterate(lp); }

	iter->next = lp;
	printf("designated lp: %d\n", lp->value);
}

int main() {
	int len = 10, lp_beg = 2; LinkedList<int> ll; Node *lp = NULL;

	for (int i = 0; i < len; ++i) { ll.push_back(rand() % 100); }
	print(&ll);

	set_loop(&ll, lp_beg);
	if (lp = find_loop_start(&ll)) { printf("loop start is: %d\n", lp->value); }
	else { printf("loop not found!"); }
}
