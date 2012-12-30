#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

int bin_empty_str(char **array, int beg, int end, char *tar) {
	assert(array);
	if (beg == end) { return -1; }
	if (end - beg == 1) { return strcmp(array[beg], tar) == 0 ? beg : -1; }

	int mid = beg + (end - beg) / 2;
	int tmid = mid, res = -1;
	if (!strcmp(array[mid], tar)) { return mid; }
	if (!strcmp(array[mid], "")) {
		while (++tmid != end && !strcmp(array[tmid], ""));
		if (tmid == end) { return -1; }
	}

	if ((res = bin_empty_str(array, beg, mid, tar)) != -1) { return res; }
	return bin_empty_str(array, tmid, end, tar);
}

int main() {
	char *teststr[] = {"at", "all", "atl", "", "", "", "bar", "bra", ""};
	cout << bin_empty_str(teststr, 0, sizeof(teststr) / sizeof(char *), "") << endl;
	cout << bin_empty_str(teststr, 0, sizeof(teststr) / sizeof(char *), "bar") << endl;
	cout << bin_empty_str(teststr, 0, sizeof(teststr) / sizeof(char *), "all") << endl;

	return 0;
}
