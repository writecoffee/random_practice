//////////////////////////////////////////////////////////////////////////////////////
// GIST
// 1.	since the array starts from zero, in the LSB, originally bit-0 amount should 
//	be at least equivalent to that of bit-1
// 2.	based on the above statement, every time 'imbalence' occurs (i.e. when one of
//	the 0-bits was removed, bit-1 amount would be bigger or equals to that of the
//	bit-0; on the opposite, when one of the 1-bits was removed, bit-0 amount just
//	naturally bigger than that of the bit-1) we can get the missing bit and 
//	eliminate half the array elements where the opposite bit exists
// 3. 	recurse step-2 from LSB to MSB repeatedly
// (4.)	when array becomes empty, fill up 0-bit in the front of the binary result
//
// TIME_COMPLEXITY
// 	at each level, we need (N-1) / 2^lev operations, 'width' levels combined is 
//	2N, namely O(N)
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

static const int N 	= 100;
static const char ON 	= '1';
static const char OFF 	= '0';
static int MISS;

char fetch(const pair<char *, int> &val, const int col) {
	assert(col < val.second);
	assert(col >= 0);
	return val.first[col];
}

int find_miss(vector<pair<char *, int> > &array, const int col, int lev) {
	if (col < 0) { return 0; }
	assert((int)abs(array.size() - (unsigned int)((N - 1) / pow(2, lev))) <= 1);

	vector<pair<char *, int> > cnt_offs, cnt_ons;
	typedef vector<pair<char *, int> >::iterator vec_iter;
	for (vec_iter vit = array.begin(); vit != array.end(); ++vit) {
		(fetch(*vit, col) == ON)? cnt_ons.push_back(*vit) : cnt_offs.push_back(*vit);
	}

	if (cnt_offs.size() > cnt_ons.size()) {
		return find_miss(cnt_ons, col - 1, lev + 1) << 1 | 1;
	} else if (cnt_offs.size() <= cnt_ons.size()) {
		return find_miss(cnt_offs, col - 1, lev + 1) << 1 | 0;
	}
}

template <typename T>
char *itoa(T val) {
	int width = sizeof(T) * 8;
	char *buffer = new char[width + 1];
	for (int i = 0; i < width; ++i) {
		(val & ((T)1 << (width - 1 - i)))?  buffer[i] = '1' : buffer[i] = '0';
	}

	buffer[width] = 0;
	return buffer;
}

template <typename T>
void test_case() {
	vector<pair<char *, T> > array; int width = sizeof(T) * 8;

	cout << "missing value: " << MISS << endl;
	for (int i = 0; i < N; ++i) {
		if (i != MISS) array.push_back(make_pair(itoa<T>(i), width));
	}
	cout << "value found: " << find_miss(array, width - 1, 0) << endl;
}

int main() {
	srand(time(0)); MISS = rand() % N; test_case<int>();
	return 0;
}
