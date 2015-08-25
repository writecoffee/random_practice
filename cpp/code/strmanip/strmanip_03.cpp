#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicate(char *_str) {
	if (_str == NULL) return;
	unsigned int length = strlen(_str);
	if (length < 2) return;

	// divide the array into two sub-sequence where i denotes the beginning of the "unsure" sequence 
	// and tail denotes the end of the sub-array [0, ..., tail - 1] with all uniq characters
	int j = 0, tail = 1;
	for (int i = 1; i < length; ++i) {
		for (j = 0; j < tail; ++j)
			// break iteration when duplicate character found
			if (_str[i] == _str[j]) break;
	
		if (j == tail)
			_str[tail++] = _str[i];
	}

	_str[tail] = 0;
}

int main() {
	char _str1[] = "abcd";	
	char *str1 = new char[strlen(_str1 + 1)];
	for (int i = 0; i < strlen(_str1 + 1); ++i) str1[i] = _str1[i];
	char _str2[] = "aabb";
	char *str2 = new char[strlen(_str2 + 1)];
	for (int i = 0; i < strlen(_str2 + 1); ++i) str2[i] = _str2[i];
	char _str3[] = "aaaa";
	char *str3 = new char[strlen(_str3 + 1)];
	for (int i = 0; i < strlen(_str3 + 1); ++i) str3[i] = _str3[i];
	char _str4[] = "aaabbb";
	char *str4 = new char[strlen(_str4 + 1)];
	for (int i = 0; i < strlen(_str4 + 1); ++i) str4[i] = _str4[i];
	char _str5[] = "ababab";
	char *str5 = new char[strlen(_str5 + 1)];
	for (int i = 0; i < strlen(_str5 + 1); ++i) str5[i] = _str5[i];

	cout << str1 << endl;
	remove_duplicate(str1);
	cout << str1 << endl;
	cout << str2 << endl;
	remove_duplicate(str2);
	cout << str2 << endl;
	cout << str3 << endl;
	remove_duplicate(str3);
	cout << str3 << endl;
	cout << str4 << endl;
	remove_duplicate(str4);
	cout << str4 << endl;	
	cout << str5 << endl;
	remove_duplicate(str5);
	cout << str5 << endl;	

	return 0;
}
