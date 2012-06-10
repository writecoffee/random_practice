/////////////////////////////////////////////////////////////////////////////////
// create two masks: odd_mask records all the bits in odd positions and even_mask
// records all the bits in even positions; right shift the even_mask and left
// shift the odd_mask. excluding the odd(even) mask generating procedure, 5 
// operations are taken
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void print_bin(T val) {
	for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {
		(val & (1 << i))? (cout << 1) : (cout << 0);
	}

	cout << endl;
}

template <typename T>
T swap_odd_even(T val) {
	unsigned int len = sizeof(T) * 8; T odd_mask = 0, even_mask = 0;
	for (int i = 0; i < len; i += 8) { odd_mask |= (0x55 << i); }
	for (int i = 0; i < len; i += 8) { even_mask |= (0xaa << i); }
	return ((val & odd_mask) << 1) | ((val & even_mask) >> 1);
}

int main() {
	srand(time(0)); int val = rand();
	print_bin<int>(val);
	print_bin<int>(swap_odd_even<int>(val));

	return 0;
}
