////////////////////////////////////////////////////////////////////////////////////////
// GIST
// "does this node complete path(s) with the sum?" -- quote from the solution
//
// TIME COMPLEXITY
// there are 2^r nodes at level r (compared to 2^h - 1 given height 'h') and each
// node needs r amount of work. so we have the following equation:
//	K = 0*2^0 + 1*2^1 + 2*2^2 + ... (h-1)*2^(h-1)
// and we can rewrite the equation as follows:
//	2*2^2 - 1*2^1 		= (2+1)2^1
// +	3*2^3 - 2*2^2 		= (3+1)2^2
//	......
// +	h*2^h - (h-1)*2^(h-1)	= (h+1)2^(h-1)
// _____________________________________________
//
// 	h*2^h	= K + 3*2 + [2*2^2 + 3*2^3 + ... + (h-1)2^(h-1)]
// 	h*2^h	= K + 6 + [2*2^2(1 - 2^(h-3)) / (1-2)]
//	K	= (h-1)2^h + 2
//
// so, the time complexity is O(h*2^h) or O(nlogn) (if we use n denotes the total nodes
// amount, n = 2^h - 1); and similarly, the space complexity is also O(nlogn) 
// (or O(h*2^h))
////////////////////////////////////////////////////////////////////////////////////////

#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#define MAX 	10

template <typename T>
struct Node {
	Node<T> *left, *right; T val; int depth;
	Node(T v, int d) : val(v), left(NULL), right(NULL), depth(d) { }
};

template <typename T>
void find_sums(Node<T> *cr, T sum, pair<T *, int> b, vector<pair<T *, int> > &sl, int lev) {
	assert(cr);

	int ts = 0;

	// trace back till the top -- buffer[0]
	for (int i = lev; i >= 0; --i) 
	{
		// mark all possible routes
		if ((ts += (b.first)[i]) == sum) {
			int len = lev + 1 -i;
			T *new_rout = new T[len];
			memcpy(new_rout, b.first + i, sizeof(T) * len);
			sl.push_back(make_pair(new_rout, len));
		}
	}

	if (cr->left) {
		T *bfl = new T[lev + 2];
		memcpy(bfl, b.first, sizeof(T) * b.second);
		bfl[lev + 1] = cr->left->val;
		find_sums(cr->left, sum, make_pair(bfl, b.second + 1), sl, lev + 1);
		delete bfl;
	}

	if (cr->right) {
		T *bfr = new T[lev + 2];
		memcpy(bfr, b.first, sizeof(T) * b.second); 
		bfr[lev + 1] = cr->right->val;
		find_sums(cr->right, sum, make_pair(bfr, b.second + 1), sl, lev + 1);
		delete bfr;
	}
}

template <typename T>
Node<T> *build_tree(const int height) {
	assert(height > 0);

	queue<Node<T> *> r, s, *p = &r, *q = &s; int h = 1;
	Node<T> *root = new Node<T>(rand() % MAX, 0); q->push(root);

	while (1) {
		while (!q->empty()) {
			Node<T> *t = q->front(); q->pop();

			// left child fixed
			if (rand() % 2) { 
				t->left = new Node<T>(rand() % MAX, h); 
				p->push(t->left); 
			}

			// right child fixed
			else { 
				t->right = new Node<T>(rand() % MAX, h); 
				p->push(t->right); 
			}

			// randomize the other child
			if (rand() % 2) {
				if (t->left) {
					t->right = new Node<T>(rand() % MAX, h); 
					p->push(t->right); 
				} else {
					t->left = new Node<T>(rand() % MAX, h);
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
void print_tree(const Node<T> *cr, int cd) {
	assert(cr && cd >= 0);

	int i = cd + 1; while (i--) { printf("  "); } printf("%d\n", cr->val);

	if (cr->left) { print_tree(cr->left, cd + 1); }

	if (cr->right) {
		if (!cr->left) { printf("\n"); }
		print_tree(cr->right, cd + 1); 
	}
}

void test_case() {
	int height = 5;
	Node<int> *root = build_tree<int>(height);
	vector<pair<int *, int> > v;
	print_tree<int>(root, 0);
	int *b = new int[1]; b[0] = root->val;
	find_sums<int>(root, MAX, make_pair(b, 1), v, 0);

	for (vector<pair<int *, int> >::iterator i = v.begin(); i != v.end(); ++i) {
		printf("rout: ");
		for (int j = 0; j < i->second; ++j) { printf("%d ", i->first[j]); }
		printf("\n");
	}
}

int main() {
	srand(time(0));
	test_case();
	return 0;
}
