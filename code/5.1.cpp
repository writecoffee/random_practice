////////////////////////////////////////////////////////////////////////////
// GENERATE LEFT MASK
// 	lm = max - ((1 << j + 1) - 1)
//
// GENERATE RIGHT MASK
// 	rm = (1 << i) - 1
//
// MOLD CASTING
//	m = (m & (lm | rm)) | (n << i)
////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <ctime>

#define N_BITS	5

void print_binary(int val) {
	int w = sizeof(val) * 8;
	int i = w;
	while (i-- > 0) {
		if (val & (1 << (w - 1))) { printf("1"); }
		else { printf("0"); }
		val <<= 1;
	}

	printf("\n");
}

void combine(int &m, int &n, int i, int j) {
	assert(j - i + 1 == N_BITS);
	int max = ~0;
	int lm = max - ((1 << j + 1) - 1);
	int rm = (1 << i) - 1;
	int mask = lm | rm;

	m = (m & mask) | (n << i);
}

int main() {
	srand(time(0));

	int m = ~0;
	int n = rand() % (1 << N_BITS);
	print_binary(m); print_binary(n);

	int i = rand() % (32 - N_BITS);
	int j = i + N_BITS - 1;

	combine(m, n, i, j);
	print_binary(m);
	return 0;
}
