///////////////////////////////////////////////////////////////////////////////////////
// MAKE_LIST:
// use multimap to store <depth-i, Node> pair, filter each pairs and store in the i-th
// list after that; the entire process is like DFS
//	-- let input variable be the height H, then maximum nodes count is N = 2^H - 1
//	-- then make-pair work costs O(N) time complexity
//	-- then "filter" work costs us O(2^H), in linear time proportional to our N
//
// BUILD_TREE
// apply BFS mindset with use two queues to store current level nodes and the next 
// respectively
//	-- O(2^(H+1)) time complexity, as using 2 times the N operations
///////////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
#include <map>
#include <vector>
#include <list>
using namespace std;

template <typename T>
struct Node { T val; Node *l, *r; Node(int v) : val(v), l(NULL), r(NULL) { } };

template <typename T>
void mark_depth(Node<T> *cr, int d, multimap<int, Node<T> *> *mm) {
	assert(cr);
	if (cr) { mm->insert(pair<int, Node<T> *>(d, cr)); }
	if (cr->l) { mark_depth(cr->l, d + 1, mm); }
	if (cr->r) { mark_depth(cr->r, d + 1, mm); }
}

template <typename T>
vector<list<Node<T> *> *> *build_list(Node<T> *tree, int height) {
	assert(tree); assert(height > 0);

	typedef typename multimap<int, Node<T> *>::iterator mmit;
	multimap<int, Node<T> *> *mm = new multimap<int, Node<T> *>();
	vector<list<Node<T> *> *> *v = new vector<list<Node<T> *> *>();
	int h = 0;

	mark_depth(tree, 0, mm);
	assert(mm->size() <= (int)(pow(2, height) - 1));

	// de-map our <depth, Node> pair and build lists
	v->push_back(new list<Node<T> *>());
	for (mmit i = mm->begin(); i != mm->end(); ++i) {
		if (i->first > h) {
			assert(i->first == h + 1);
			v->push_back(new list<Node<T> *>()); 
			++h;
		}

		(*v)[i->first]->push_back(i->second);
	}

	assert(!v->empty());
	delete mm;
	return v;
}

template <typename T>
Node<T> *build_binary_tree(int height) {
	assert(height > 0);

	queue<Node<T> *> r, s, *q = &r, *p = &s; int h = 1;
	Node<T> *root = new Node<T>(rand() % 100); q->push(root);

	while (1) {
		// BFS
		while (!q->empty()) {
			Node<T> *t = q->front(); q->pop();
	
			// left child creates
			{ t->l = new Node<T>(rand() % 100); p->push(t->l); }

			// right child creates
			if (rand() % 2) { t->r = new Node<T>(rand() % 100); p->push(t->r); }
		}
	
		if (++h == height) { break; }

		// swap p's and q's reference
		if (q == &s) { q = &r; p = &s; } else if (q == &r) { q = &s; p = &r; }
	}
	
	return root;
}


int main() {
	srand(time(0)); int height = 5; Node<int> *root; vector<list<Node<int> *> *> *v;

	root 	= build_binary_tree<int>(height);
	v 	= build_list<int>(root, height);

	assert(v->size() == height);

	typedef vector<list<Node<int> *> *>::iterator vit;
	typedef list<Node<int> *>::iterator lit;
	for (vit i = v->begin(); i != v->end(); ++i) {
		for (lit j = (*i)->begin(); j != (*i)->end(); ++j) {
			printf("%d ", (*j)->val);
		}

		printf("\n");
	}

	return 0;
}
