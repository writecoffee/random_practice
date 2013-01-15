////////////////////////////////////////////////////////////////////////////////////
// XOR a and b esposing the different bits; count the bits by simple iteration with
// linear time
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void print_bin(T num) {
    for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {
        (num & (1 << i))? (cout << 1) : (cout << 0);
    }

    cout << endl;
}

int count_distance(int a, int b) {
    int same = a ^ b, cnt = 0;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        (same & (1 << i))? cnt++ : cnt;
    }

    return cnt;
}

int main() {
    srand(time(0));
    int a = rand(), b = /*rand()*/a - 1;
    print_bin<int>(a);
    print_bin<int>(b);
    cout << count_distance(a, b) << endl;

    return 0;
}
