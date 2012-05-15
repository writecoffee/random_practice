#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <queue>
using namespace std;

template <typename T>
struct Node { 
	int val, depth; Node<T> *left, *right;
	Node(int v, int d) : val(v), depth(d), left(NULL), right(NULL) { } 
};

enum NODE_FND { ZERO = 0, ONE = 1, TWO };

template <typename T>
int covers(const Node<T> *cr, const Node<T> *p, const Node<T> *q) {
	assert(p); 
	assert(q);

	if (!cr) { return ZERO; }

	int result = ZERO; 

	if (cr == p) { ++result; }
	if (cr == q) { ++result; }

	if ((result += covers(cr->left, p, q)) == TWO) { return result; }
	else { return result + covers(cr->right, p, q); }
}

template <typename T>
Node<T> *find_conjunct(Node<T> *cr, const Node<T> *p, const Node<T> *q) {
	assert(cr && p && q);

	int l_cnt = 0, r_cnt = 0;

	if (cr->left) {
		l_cnt = covers(cr->left, p, q);
	
		if (l_cnt == TWO) {
			// if p/q is the left sub-root, end search
			if (cr->left == p || cr->left == q) { return cr->left; }
	
			// trace down, otherwise
			else { return find_conjunct(cr->left, p, q); }
	
		} else if (l_cnt == ONE) {
			// if p/q is the left sub-root, end search
			if (cr == p || cr == q) { return cr; }
		}
	}

	if (cr->right) {
		r_cnt = covers(cr->right, p, q);
	
		if (r_cnt == TWO) {
			// if p/q is the right sub-root, end search
			if (cr->right == p || cr->right == q) { return cr->right; }
	
			// trace down, otherwise
			else { return find_conjunct(cr->right, p, q); }
	
		} else if (r_cnt == ONE) {
			// if p/q is the right sub-root, end search
			if (cr == p || cr == q) { return cr; }
		}
	}

	// if left sub-tree and the right one cover targets separately 
	if (l_cnt == ONE && r_cnt == ONE) { return cr; }
	else { return NULL; }
}

template <typename T>
void print_tree(const Node<T> *cr, int depth) {
	assert(cr && depth >= 0);

	int i = depth + 1; while (i--) { printf("  "); } printf("%d\n", cr->val);

	if (cr->left) { print_tree(cr->left, depth + 1); }

	if (cr->right) { 
		if (!cr->left) { printf("\n"); }
		print_tree(cr->right, depth + 1); 
	}
}

template <typename T>
Node<T> *build_tree(int height, Node<T> **t1, Node<T> **t2) {
	assert(height > 0);
	assert(t1 && t2);

	queue<Node<T> *> r, s, *p = &r, *q = &s; int h = 1;
	Node<T> *root = new Node<T>(rand() % 100, 0); q->push(root);

	bool 	t1_f = false, 			t2_f = false;
	int 	t1_i = -1,			t2_i = -1;
	int	t1_d = rand() % height,		t2_d = rand() % height;

	while (1) {
		if (t1_d == 0 || t1_d == h) { t1_f = true; t1_i = rand() % q->size(); }
		else { t1_f = false; }

		if (t2_d == 0 || t2_d == h) { t2_f = true; t2_i = rand() % q->size(); }
		else { t2_f = false; }

		while (!q->empty()) {
			Node<T> *t = q->front(); q->pop();

			// set the targets
			if (t1_f && t1_i == q->size()) { *t1 = t; }
			if (t2_f && t2_i == q->size()) { *t2 = t; } 


			// left child fixed
			if (rand() % 2) { t->left = new Node<T>(rand() % 100, h); p->push(t->left); }

			// right child fixed
			else { t->right = new Node<T>(rand() % 100, h); p->push(t->right); }

			// randomize the other child
			if (rand() % 2) {
				if (t->left) { 
					t->right = new Node<T>(rand() % 100, h); 
					p->push(t->right); 

				} else {
					t->left = new Node<T>(rand() % 100, h);
					p->push(t->left); 
				}
			}
		}
	
		if (++h == height) { break; }

		if (q == &s) { q = &r; p = &s; } else if (q == &r) { q = &s; p = &r; }
	}

	// dedicated treatment for the last depth level
	if (t1_d == height - 1) { t1_f = true; t1_i = rand() % p->size(); } else { t1_f = false; }
	if (t2_d == height - 1) { t2_f = true; t2_i = rand() % p->size(); } else { t2_f = false; }

	if (t1_f || t2_f) {
		while (!p->empty()) {
			Node<T> *t = p->front(); p->pop();
			
			if (t1_f && t1_i == p->size()) { *t1 = t; }
			if (t2_f && t2_i == p->size()) { *t2 = t; }
		}
	}

	return root;
}

int main() {
	srand(time(0)); int height = 5; Node<int> *p, *q;

	Node<int> *root		= build_tree<int>(height, &p, &q);
	print_tree(root, 0);
	Node<int> *result	= find_conjunct<int>(root, p, q);

	assert(p && q);
	assert(result->depth <= p->depth && result->depth <= q->depth);

	printf("p: Node<val=%d, depth=%d>\n", p->val, p->depth);
	printf("q: Node<val=%d, depth=%d>\n", q->val, q->depth);
	printf("common ancestor: Node<val=%d, depth=%d>\n", result->val, result->depth);

	return 0;
}
