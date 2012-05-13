///////////////////////////////////////////////////////////////////////////////////////////
// divide into several conditions:
//	case-1:		s has right child 	
//				-> return right child's leftmost child or itself otherwise
//
//	case-2: 	s has father
//	case-2-1: 	s itself is the left child of its father 
//				-> return father
//
//	case-2-2: 	s itself is the right child 
//	case-2-2(i)	s can be traced back to case-2-1 until <s == s->f->l> found
//
//	case-2-2(e)	s cannot be traced back to case-2-1
//				-> no successor
//
//	case-3: 	s is a root node without right child 
//				-> no successor
//
// test cases (might be informal):
//	ts-1:		s is a root node
//				-> case-1 or case-3
//
//	ts-2:		s is the left-most child
//				-> case-2-1
//
//	ts-3:		s is the right-most child
//				-> case-2-2(e)
//
// 	all conditions covered? (Y)
//	all branches covered? (Y)
//	all lines covered? (Y)
//////////////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
using namespace std;

template <typename T>
struct Node {
	Node<T> *left, *right, *father; int val;
	Node(int v, Node<T> *f) : val(v), left(NULL), right(NULL), father(f) { }
};

template <typename T>
Node<T> *find_next(Node<T> *s) {
	assert(s);

	Node<T> *n = NULL, *p = NULL;

	// has right child? find its left-most child!
	if (s->right) { s = s->right; while (n = s->left) { s = n; } return s; }

	// has father?
	else if (s->father) {

		// itself is a left child?
		if (s == s->father->left) { return s->father; }

		// itself is a right child? go up till itself is a left child
		else if (s == s->father->right) {
			while (p = s->father) {
				if (p->left == s) { return p; } 
				else { s = p; }
			}

			// right-most node
			return NULL;
		}
	
	// no father, no right child? finish in-order traversal
	} else { return NULL; }
}

template <typename T>
Node<T> *build_tree(int height) {
	assert(height > 0);

	queue<Node<T> *> r, s, *p = &r, *q = &s; int h = 1;
	Node<T> *root = new Node<T>(rand() % 100, NULL); q->push(root);

	while (1) {
		while (!q->empty()) {
			Node<T> *t = q->front(); q->pop();
	
			// left child fixed
			if (rand() % 2) { t->left = new Node<T>(rand() % 100, t); p->push(t->left); }

			// right child fixed
			else { t->right = new Node<T>(rand() % 100, t); p->push(t->right); }

			// randomize the other child
			if (rand() % 2) {
				if (t->left) { 
					t->right = new Node<T>(rand() % 100, t); 
					p->push(t->right); 

				} else { 
					t->left = new Node<T>(rand() % 100, t); 
					p->push(t->left); 
				}
			}
		}
	
		if (++h == height) { break; }

		if (q == &s) { q = &r; p = &s; } else if (q == &r) { q = &s; p = &r; }
	}

	return root;
}

template <typename T>
void print_tree(Node<T> *cr, int depth) {
	assert(cr && depth >= 0);

	int i = depth + 1; while (i--) { printf("  "); } printf("%d\n", cr->val);

	if (cr->left) { print_tree(cr->left, depth + 1); }

	if (cr->right) { 
		if (!cr->left) { printf("\n"); }
		print_tree(cr->right, depth + 1); 
	}
}

template <typename T>
void test_cases(Node<T> *root, int height) {
	assert(root && height > 0);

	Node<T> *result, *t = root, *s = root, *p, *q; int i = 0, j = 0;

	result = find_next<T>(root);
	if (result) { printf("f(root) == %d\n", result->val); }

	while (p = s->left) { s = p; i++; }
	if (s && i) { 
		if (result = find_next<T>(s)) {
			printf("lev-%d::f(%d) == %d\n", i, s->val, result->val); 
		}
	} 

	while (q = t->right) { t = q; j++; }
	if (t && j) {
		if (result = find_next<T>(t)) {
			printf("lev-%d::f(%d) == %d\n", j, t->val, result->val);
		}
	}
}

int main() {
	srand(time(0));
	int height = 5; 
	Node<int> *root = build_tree<int>(height);

	print_tree<int>(root, 0);
	test_cases<int>(root, height);

	return 0;
}
