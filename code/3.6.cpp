////////////////////////////////////////////////////////////////////////////
// "only push | pop | peek | isempty allowed"
//
// --	use a temp stack to "filter out" out-of-order values every time  
// 	before pushing the highest order stuff
// -- 	O(n^2) time
////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

template <typename T>
void sort_stack(stack<T> **s) {
	stack<T> *tmp = new stack<T>(); stack<T> *tar = *s;

	while (!tar->empty()) {
		T tv = tar->top(); tar->pop();

		// find right place for tar.top in tmp stack
		while (!tmp->empty() && v < tmp->top()) {
			tar->push(tmp->top()); tmp->pop();
		}
		
		tmp->push(tv);
	}

	delete *s;
	*s = tmp;
}

int main() {
	stack<int> *s = new stack<int>(); int size = 10;

	for (int i = 0; i < size; ++i) { s->push(rand() % 100); }

	sort_stack(&s);

	while (!s->empty()) { printf("pop %d\n", s->top()); s->pop(); }

	return 0;
}
