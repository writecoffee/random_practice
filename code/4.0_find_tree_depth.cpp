#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;


int ld = 0;
int rd = 0;


template <typename T>
struct Node {
	Node(T val) : left(NULL), right(NULL), val(val) {}
	Node<T> *left, *right;
	int val;
};

template <typename T>
int find_depth(Node<T> *curr) {
	return curr ? 1 + ((ld = find_depth<T>(curr->left)) > (rd = find_depth<T>(curr->right)) ? ld : rd) : 0;
}

template <typename T>
int find_height(Node<T> *curr) {
	return curr ? 1 + ((ld = find_height<T>(curr->left)) > (rd = find_height<T>(curr->right)) ? ld : rd) : -1;
}

template <typename T>
Node<T> *build_tree(T *sorted, int beg, int end) {
	assert(sorted);
	assert(beg >= 0);
	assert(end >= 0);
	assert(end >= beg);

	int mid = beg + (end - beg) / 2, len = end - beg + 1;
	Node<T> *mid_elem = new Node<T>(sorted[mid]);

	// encounter length-2 sub-array, then left child has been dealt with
	if (len > 2) {
		mid_elem->left = build_tree(sorted, beg, mid - 1);
		mid_elem->right = build_tree(sorted, mid + 1, end);
	} else if (len == 2) {
		mid_elem->right = build_tree(sorted, mid + 1, end);
	}

	return mid_elem;
}

int main() {
	const int SIZE = 10; int sorted[SIZE]; srand(time(0));
	typedef vector<int>::iterator v_it; int i; v_it it;

	for (int i = 0; i < SIZE; ++i) { sorted[i] = rand() % 100; }

	// sort and re-build array
	vector<int> vs(sorted, sorted + SIZE); sort(vs.begin(), vs.end());
	for (it = vs.begin(), i = 0; it != vs.end(); ++i, ++it) { 
		sorted[i] = *it; printf("%d ", sorted[i]);
	}

	printf("\n"); 
	Node<int> *rt = build_tree<int>(sorted, 0, SIZE - 1);

	cout << find_height<int>(rt) << endl;
	cout << find_depth<int>(rt) << endl;

	return 0;
}
