////////////////////////////////////////////////////////////////////////////////////
// GIST
// 	judge whether n has only one bit flipped on or not
//
// WHY IS THAT
// 1.	n-1 flips the least significant 1 bit (x) and all zero bit lower than that,
//	so excluding the higher bits (for those between bit (x+1) and 31), n&(n-1) 
//	generates 0.
// 2.	after that, we can put sight on bit between (x+1) and 31, for which can
//	influence the final result 
//	
// OBSERVATION
// 	by observation, this expression can only apply to positive interger
//	and the smallest negative number (-2^31), which most significant bit
//	is set to 1; except that, all negtive number has at least 2 bits on
////////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

template <typename T>
bool chk_bit(T val) {
	return (val & (val - 1)) == 0;
}

template <typename T>
void print_bin(T val) {
	int sz = sizeof(T) * 8;
	while (--sz >= 0) { printf("%d", (val & (1 << sz) ? 1 : 0)); }
	printf("\n");
}

void tc_positive() {
	int val = 1 << (rand() % (sizeof(int) * 8));
	printf("val = %d\n", val);
	print_bin<int>(val);
	chk_bit<int>(val) ? printf("true\n") : printf("false\n");
}

void tc_negative() {
	int val = -(1 << (rand() % (sizeof(int) * 8)));
	printf("val = %d\n", val);
	print_bin<int>(val);
	chk_bit<int>(val) ? printf("true\n") : printf("false\n");
}

int main() {
	srand(time(0)); tc_positive(); tc_negative();
	return 0;
}
