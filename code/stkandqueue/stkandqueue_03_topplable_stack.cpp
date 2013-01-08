///////////////////////////////////////////////////////////////////////
// store stacks in a list; if we need to pop values at a designated
// stack, 'double-ended' stack is requested
///////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define MAX_SIZE 5

//*****************************************************************/
// Two-way stack, which stores the value in a double-ended queue,
// and with the same attributes with single-way stack
//  -- see @remove_bottom
//  -- see @SingleStacke
//*****************************************************************/
template <typename T>
class TwoWayStack {
private:
    deque<T> _q;
    int _mx;

public:
    TwoWayStack(int max_size) : _mx(max_size) { }

    bool push(T val) {
        if (full()) {
            return false;
        }
        else {
            _q.push_back(val);
            return true;
        }
    }

    bool pop(T &val) {
        if (empty()) {
            return false;
        }
        else {
            val = _q.back();
            _q.pop_back();
            return true;
        }
    }

    bool empty() {
        return _q.size() == 0;
    }

    bool full() {
        return _q.size() >= _mx;
    }

    bool remove_bottom(T &val) {
        if (empty()) {
            return false;
        }
        else {
            val = _q.front();
            _q.pop_front();
            return true;
        }
    }
};

template <typename T>
class SingleStack {
private:
    stack<T> _s;
    int _ms;

public:
    SingleStack(int max_size) : _ms(max_size) { }

    bool push(T val) {
        if (full()) {
            return false;
        }
        else {
            _s.push(val);
            return true;
        }
    }

    bool pop(T &val) {
        if (empty()) {
            return false;
        }
        else {
            val = _s.top();
            _s.pop();
            return true;
        }
    }

    bool empty() {
        return _s.size() == 0;
    }

    bool full() {
        return _s.size() >= _ms;
    }
};

template < typename T, typename stack_type = SingleStack<T> >
class SetOfStacks {
private:
    vector<stack_type *> stk_vec;

public:
    void push(T val) {
        if (stk_vec.empty() || stk_vec.back()->full()) {
            stack_type *ns = new stack_type(MAX_SIZE);
            ns->push(val);
            stk_vec.push_back(ns);
        } else {
            stk_vec.back()->push(val);
        }
    }

    bool pop(T &val) {
        if (stk_vec.empty()) return false;
        else {
            stk_vec.back()->pop(val);
            if (stk_vec.back()->empty()) {
                stk_vec.pop_back();
            }
            return true;
        }
    }

    bool empty() {
        return stk_vec.empty();
    }

    unsigned int stack_cnt() {
        return stk_vec.size();
    }

    void shift_items(int sn) {
        typedef typename vector<stack_type *>::iterator iter;
        T bv;

        for (iter i = stk_vec.begin() + sn, j = i + 1; j != stk_vec.end(); ++i, ++j) {
            (*j)->remove_bottom(bv);
            (*i)->push(bv);
        }

        if (stk_vec[stack_cnt() - 1]->empty()) {
            stk_vec.pop_back();
        }
    }

    bool pop_at(T &val, int sn) {
        typedef typename vector<stack_type *>::iterator iter;
        T bv;

        if (sn > stack_cnt() - 1) {
            return false;
        }
        else if (stk_vec[sn]->pop(val))
        {
            shift_items(sn);

            return true;
        }
    }
};

int main() {
    SetOfStacks<int> sgls;
    SetOfStacks< int, TwoWayStack<int> > tws;
    int rv, pv, tn = 16;

    for (int i = 0; i < tn; ++i) {
        sgls.push(pv = rand() % 100);
        printf("single stack push: %d\n", pv);
    }

    while (sgls.pop(rv)) {
        printf("single stack pop: %d\n", rv);
    }

    for (int i = 0; i < tn /** 2*/; ++i) {
        tws.push(pv = rand() % 100);
        printf("two-way stack push val(%d) at %d\n", pv, tws.stack_cnt() - 1);
    }

    int stk_rcd;
    while (tws.stack_cnt()) {
        tws.pop_at(rv, (stk_rcd = rand() % tws.stack_cnt()));
        printf("two-way stack pop at %d: value(%d)\n", stk_rcd, rv);
    }

    return 0;
}
