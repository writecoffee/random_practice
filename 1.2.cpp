#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void swap(char &a, char &b) {
	a = a ^ b;
	b = a ^ b;
	a = b ^ a;	
}

void reverse(char *cstring) {
	int i = 0;	
	unsigned int end = strlen(cstring) - 1;	

	while (i != (end + 1) / 2) {
		swap(cstring[i], cstring[end - i]);	
		++i;
	}
}

int main() {
	int length = 6;
	char *cstring = new char[length];
	for (int i = 0; i < length - 1; ++i) {
		cstring[i] = 'a' + rand() % 26;
	}

	cstring[length - 1] = 0;	

	cout << cstring << endl;
	reverse(cstring);
	cout << cstring << endl;
	
	return 0;
}
