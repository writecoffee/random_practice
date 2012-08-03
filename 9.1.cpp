#include <iostream>
using namespace std;

typedef int array_a[10];
typedef int array_b[3];
int exact_len = 5;

static int *merge(int a[], int &len_a, const int b[]) {
	int i = len_a - 1, j = sizeof(array_b) / sizeof(int) - 1, k = sizeof(array_a) / sizeof(int) - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] < b[j]) { a[k--] = b[j--]; }
		else { a[k--] = a[i--]; }
	}

	if (i < 0) { while (j >= 0) { a[k--] = b[j--]; } }
	if (j < 0) { while (i >= 0) { a[k--] = a[i--]; } }
	k++;

	len_a = sizeof(array_a) / sizeof(int) - k;
	int *a_start = a;
	a_start += k;
	return a_start;
}

static int test() {
	array_a a = {1, 3, 5, 7, 9};
	array_b b = {2, 4, 6};
	int len_a = exact_len;
	int len_b = sizeof(array_b) / sizeof(int);
	int len_t = sizeof(array_a) / sizeof(int);
	int *new_a = merge(a, len_a, b);
	for (int i = 0; i < len_a; ++i) {
		cout << new_a[i] << endl;
	}
}

int main() {
	test();
	return 0;
}
