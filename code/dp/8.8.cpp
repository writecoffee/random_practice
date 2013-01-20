#include <iostream>
#include <cmath>
using namespace std;

static const int n = 8;
static int columns[n + 1];
static int cnt = 0;

static bool check(int row) {
    int rdiff, cdiff;
    for (int ri = 1; ri < row; ++ri) {
        if (columns[ri] != 0) {
            cdiff = abs(columns[ri] - columns[row]);
            rdiff = row - ri;
            if (cdiff == 0 || cdiff == rdiff) {
                return false;
            }
        }
    }

    return true;
}

static void print_grid() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            columns[i] == j ? (cout << "1 ") : (cout << "0 ");
        }

        cout << endl;
    }

    cout << endl;
}

static void find_space(int row) {
    if (row > n) {
//		print_grid();
        cnt++;
        return;
    }

    for (int ci = 1; ci <= n; ++ci) {
        columns[row] = ci;
        if (check(row)) {
            find_space(row + 1);
        }
    }
}

int main() {
    find_space(1);
    cout << cnt << endl;
    return 0;
}
