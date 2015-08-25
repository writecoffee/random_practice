//////////////////////////////////////////////////////////////////////////////////
// don't need to dynamically build the tree (since input array is sorted),
// so binarily search mid-element recursively
// 	-- each mid-find is deterministic, so O(N) time complexity
//
// (consider AVL tree if the input array is not sorted and sortion is now allowed)
//	-- O(log(N)) time complexity for each insertion
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node *left, *right;
    Node(T v) : val(v), left(NULL), right(NULL) { }
};

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

template <typename T>
void inorder_traverse(Node<T> *rt) {
    assert(rt);

    if (rt->left) {
        inorder_traverse(rt->left);
    }
    printf("%d ", rt->val);
    if (rt->right) {
        inorder_traverse(rt->right);
    }
}

int main() {
    const int SIZE = 10;
    int sorted[SIZE];
    srand(time(0));
    typedef vector<int>::iterator v_it;
    int i;
    v_it it;

    for (int i = 0; i < SIZE; ++i) {
        sorted[i] = rand() % 100;
    }

    // sort and re-build array
    vector<int> vs(sorted, sorted + SIZE);
    sort(vs.begin(), vs.end());
    for (it = vs.begin(), i = 0; it != vs.end(); ++i, ++it) {
        sorted[i] = *it;
        printf("%d ", sorted[i]);
    }

    printf("\n");
    Node<int> *rt = build_tree<int>(sorted, 0, SIZE - 1);
    inorder_traverse<int>(rt);
    printf("\n");

    return  0;
}
