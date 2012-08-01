#include <iostream>
#include <cassert>
using namespace std;

static int make_change(int n, int denomin) {
	int nxt_de = 0;
	switch (denomin) {
	case 50:
		nxt_de = 25;
		break;
	case 25:
		nxt_de = 10;
		break;
	case 10:
		nxt_de = 5;
		break;
	case 5:
		nxt_de = 1;
		break;
	case 1:
		return 1;
	}

	int ways = 0;
	for (int i = 0; i * denomin <= n; ++i) {
		ways += make_change(n - i * denomin, nxt_de);
	}

	return ways;
}

static void test() {
	int denominations[] = {1, 5, 10, 25, 50};
	int expected[] = {2, 10, 11};
	int asserts[] = {1, 4, 4};

	for (int i = 0; i < sizeof(expected) / sizeof(int); ++i) {
		int smallest = 0;
		int ways = 0;
		for (int j = sizeof(denominations) / sizeof(int) - 1; j >= 0; --j) {
			if (denominations[j] <= expected[i]) {
				smallest = denominations[j];
				break;
			}
		}

		if (smallest) { 
			ways = make_change(expected[i], smallest); 
			cout << ways << endl;
			assert(ways == asserts[i]);
		}
	}

	cout << "Test case passed!" << endl;
}

int main() {
	test();
	return 0;
}
