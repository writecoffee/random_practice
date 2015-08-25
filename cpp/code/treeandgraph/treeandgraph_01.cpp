///////////////////////////////////////////////////////////////////////////////////
// difference between max-depth and min-depth shoudn't exceed 1 -- maximum distance
// 	-- bear in mind that the terminology of "depth" and "height"
// 	-- episode:
//		build tree with pre-order array and in-order array and we have:
//			inord:	(L)rt(R)
//			preord:	rt(L)(R)
//		provding that rt in inorder array could be found
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

template <typename T>
struct Node {
    Node(T val) {
        this->val = val;
    } Node<T> *left, *right;
    T val;
};

template <typename T>
class Tree {
private:
    Node<T> *_root;

public:
    Node<T> *root() {
        return _root;
    }

    Tree(const int inorder[], int leni, const int preorder[], int lenp) {
        if (leni != lenp) {
            return;
        }
        _root = build(inorder, preorder, 0, lenp - 1, 0, leni - 1);
    }

    Node<T> *build(const int inorder[], const int preorder[], int pl, int pr, int il, int ir) {
        int len = pr - pl + 1;
        if (len <= 0) return NULL;

        int i = il;
        Node<T> *rt = new Node<T>(preorder[pl]);

        // recurrence ends
        if (len == 1) {
            return rt;
        }

        // find sub-tree's root in inorder array
        while (inorder[i] != preorder[pl]) {
            ++i;
        }

        rt->left = build(inorder, preorder, pl + 1, pl + i - il, il, i - 1);
        rt->right = build(inorder, preorder, pl + i - il + 1, pr, i + 1, ir);

        return rt;
    }

    void inord_traverse(Node<T> *cr) {
        if (cr == NULL) {
            return;
        }
        inord_traverse(cr->left);
        printf("%c ", cr->val + 'A');
        inord_traverse(cr->right);
    }

    void preord_traverse(Node<T> *cr) {
        if (cr == NULL) {
            return;
        }
        printf("%c ", cr->val + 'A');
        preord_traverse(cr->left);
        preord_traverse(cr->right);
    }
};

template <typename T>
int count_min(Node<T> *root) {
    if (root == NULL) {
        return 0;
    }
    return min(count_min(root->left), count_min(root->right)) + 1;
}

template <typename T>
int count_max(Node<T> *root) {
    if (root == NULL) {
        return 0;
    }
    return max(count_max(root->left), count_max(root->right)) + 1;
}

template <typename T>
bool is_balance(Node<T> *root) {
    return (count_max<T>(root) - count_min<T>(root)) <= 1;
}


int main() {
    string pro("ABDECG"), ino("DBEAGC");

    int *preorder = new int[pro.length()], *inorder = new int[ino.length()];
    for (int i = 0; i < pro.length(); ++i) {
        preorder[i] = pro[i] - 'A';
        inorder[i] = ino[i] - 'A';
    }

    Tree<int> *tr = new Tree<int>(inorder, ino.length(), preorder, pro.length());
    tr->inord_traverse(tr->root());
    printf("\n");
    tr->preord_traverse(tr->root());
    printf("\n");

    cout << (is_balance<int>(tr->root())? "true" : "false") << endl;

    return 0;
}
