///////////////////////////////////////////////////////////////////////////////////////
// -- 	procedure is like the string matching function, which "iterates" all nodes in 
// 	the source tree (bigger tree) while doing comparisons till the end of the target 
//	tree (smaller tree). 
// -- 	the target tree should be regarded as a very big leaf in the source tree; if 
// 	not so, the matching procedure fails
// --	in the worst case, each node in bigger tree is visited at least once and the 
//	comparison times is at most N * M, namely O(N * M) or O(N + k * M) where k 
//	denotes the occurrence of the root of the smaller tree in the bigger tree
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define _N(t) 	t == NULL

template <typename T>
struct Node {
	Node<T> *left, *right; T val; int depth;

	Node(T v, int d, bool e = false) : val(v), left(NULL), right(NULL), depth(d) { }

	Node(const Node<T> &cp) : left(NULL), right(NULL), val(cp.val), depth(cp.depth) {
		if (cp.left) { this->left = new Node<T>(*cp.left); }
		if (cp.right) { this->right = new Node<T>(*cp.right); }
	}

	~Node() {
		if (left) { left->~Node(); }
		if (right) { right->~Node(); }
	}
};

template <typename T>
bool sub(const Node<T> *p, const Node<T> *q) {
	if (_N(p)) { return false; }		// source tree ends, matching job finish
	else if (p->val == q->val) { if (match(p, q)) { return true; } }
	else { return (sub(p->left, q) || sub(p->right, q)); }
}

template <typename T>
bool match(const Node<T> *p, const Node<T> *q) {
	if (_N(p) && _N(q)) { return true; }			// both end, finish match
	else if (_N(p) || _N(q)) { return false; }		// one side end
	else if (p->val != q->val) { return false; } 		// data mismatch
	else { return (match(p->left, q->left) && match(p->right, q->right)); }
}

template <typename T>
void print_tree(const Node<T> *cr, int cd) {
	assert(cr && cd >= 0);

	int i = cd + 1; while (i--) { printf("  "); } printf("%d\n", cr->val);

	if (cr->left) { print_tree(cr->left, cd + 1); }

	if (cr->right) {
		if (!cr->left) { printf("\n"); }
		print_tree(cr->right, cd + 1); 
	}
}

template <typename T>
Node<T> *build_tree(const int height, Node<T> **sub_t) {
	assert(height > 0);
	assert(sub_t);

	queue<Node<T> *> r, s, *p = &r, *q = &s; int h = 1;
	Node<T> *root = new Node<T>(rand() % 100, 0); q->push(root);

	bool 	sub_t_f = false;
	int 	sub_t_i = -1;
	int	sub_t_d = rand() % height;

	while (1) {
		if (sub_t_d == 0 || sub_t_d == h) { 
			sub_t_f = true; sub_t_i = rand() % q->size(); 
		} else { 
			sub_t_f = false; 
		}

		while (!q->empty()) {
			Node<T> *t = q->front(); q->pop();

			// set the targets
			if (sub_t_f && sub_t_i == q->size()) { *sub_t = t; }

			// left child fixed
			if (rand() % 2) { 
				t->left = new Node<T>(rand() % 100, h); 
				p->push(t->left); 
			}

			// right child fixed
			else { 
				t->right = new Node<T>(rand() % 100, h); 
				p->push(t->right); 
			}

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

	// dedicated treatment for the last level
	if (sub_t_d == height - 1) {
		sub_t_f = true; sub_t_i = rand() % p->size();

		while (!p->empty()) {
			Node<T> *t = p->front(); p->pop();
			if (sub_t_f && sub_t_i == p->size()) { *sub_t = t; }
		}
	}

	return root;
}

template <typename T>
bool tree_trunc(Node<T> *t, const int d) {
	assert(d >= t->depth);
	
	if (t->depth == d) {
		bool ret = false;

		if (t->left) { delete t->left; t->left = NULL; ret = true; }
		if (t->right) { delete t->right; t->right = NULL; ret = true; }

		return ret;
	}
	
	bool ret = false;
	if (t->left) { if (tree_trunc(t->left, d)) { ret = true; } }
	if (t->right) { if (tree_trunc(t->right, d)) { ret = true; } }

	return ret;
}

void test_case_trunc() {
	int depth = 5; Node<int> *sub_t, *root, *cprt;

	root = build_tree<int>(depth, &sub_t);
	cprt = new Node<int>(*root);

	print_tree<int>(root, 0);
	cout << (tree_trunc(sub_t, sub_t->depth + 1 + rand() % (depth - sub_t->depth))
			? "truncated" : "not truncated") << endl;
	cout << (sub(cprt, sub_t) ? "sub-tree" : "not sub-tree") << endl;
	print_tree<int>(sub_t, sub_t->depth);

	delete root;
	delete cprt;
}

int main() {
	srand(time(0));
	test_case_trunc();
	return 0;
}
