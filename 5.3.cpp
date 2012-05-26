//////////////////////////////////////////////////////////////////////////////////
// GET_NEXT
// 	from the least significant digit find the first bit-1 (pos: i), and then 
//	the bit-0 (pos: j), exchange w(j) and w(j-1), finally right shifting the 
//	bit-1 to the rightmost positions
//
// GET_PREV
//	similar to GET_NEXT, return the "next smallest number that have the same
//	number of 1 bits in binary expression"
//
// PROOF-OF-NEXT-SMALLEST
// 1.	once we find the 'first bit-0 (pos: j)', and the modified number is 
//	2^j - 2^(j-1) bigger than the original one
// 2.	restricted to the rule -- the next largest number have the same number of
//	1 bits in their binary representation, right shifting all the bit-1 to the
//	corner helps remain the "smallest" attribute
// 3.	finally, the result is up to 2^j - 2^(j-1) bigger than the original number
//////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

#define ON 	true
#define OFF	false

template <typename T>
static void set_bit(T &num, int index, bool sign) {
	assert(index < sizeof(num) * 8);
	T mask;
	switch (sign) {
		case ON:
			mask = 1 << index; num |= mask; break;
		case OFF:
			mask = (1 << index) ^ ~0; num &= mask; break;
		default:
			break;
	}
}

template <typename T>
static bool get_bit(const T &num, int index) {
	assert(index < sizeof(num) * 8);
	return (num & (1 << index)) > 0;
}

template <typename T>
static int get_next(T num) {
	int index = 0, cnt_1 = 0;

	// find the first bit-1 from the LS-bit
	while (!get_bit<T>(num, index)) { index++; }

	// turn on the nexxxxxxt bit-0
	while (get_bit<T>(num, index)) { index++; cnt_1++; }
	set_bit<T>(num, index, ON);

	// then turn off the previous bit-1
	set_bit<T>(num, --index, OFF); cnt_1--;

	// shifting the ones to the rightmost positions 
	for (int i = index - 1; i >= cnt_1; --i) { set_bit<T>(num, i, OFF); }
	for (int i = cnt_1 - 1; i >= 0; --i) { set_bit<T>(num, i, ON); }

	return num;
}

template <typename T>
static int get_prev(T num) {
	int index = 0, cnt_0 = 0;

	// find the first bit-0 from the LS-bit
	while (get_bit<T>(num, index)) { index++; }

	// turn off the nexxxxxt bit-1
	while (!get_bit<T>(num, index)) { index++; cnt_0++; }
	set_bit<T>(num, index, OFF);

	// then turn on the previous bit-0
	set_bit<T>(num, --index, ON); cnt_0--;
	
	// shifting the zeros to the rightmost positions
	for (int i = index - 1; i >= cnt_0; --i) { set_bit<T>(num, i, ON); }
	for (int i = cnt_0 - 1; i >= 0; --i) { set_bit<T>(num, i, OFF); }

	return num;
}

template <typename T>
void print_bin(const T &num) {
	int len =  sizeof(num) * 8;
	for (int i = len - 1; i >= 0; --i) { 
		printf("%d", ((num & (1 << i)) > 0 ? 1 : 0)); 
	}
	printf("\n");
}

int main() {
	srand(time(0));
	int num = rand();
	print_bin<int>(num);
	print_bin<int>(get_next<int>(num));
	print_bin<int>(get_prev<int>(num));
	return 0;
}
