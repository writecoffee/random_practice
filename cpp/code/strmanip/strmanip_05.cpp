#include <iostream>
#include <cstring>
using namespace std;

void replaceAllSpaces(char **_str) {
	char *cstring = *_str;
	unsigned int length = strlen(cstring);
	if (length == 0) return;
	
	// count all spaces in O(n) time
	int i, j, cnt = 0;
	while (i != length) {
		if (cstring[i] == ' ') ++cnt;
		++i;
	}

	int new_length = length + cnt * 2;
	char *new_string = new char[new_length + 1];
	
	// replace all the spaces in a new string
 	for (i = 0; i < length; ++i) { 
		if (cstring[i] == ' ') {
			new_string[j++] = '%';
			new_string[j++] = '2';
			new_string[j++] = '0';	
		} else {
			new_string[j++] = cstring[i];
		}
	} 

	new_string[j] = 0;
	*_str = new_string;
}

int main() {
	char *str = "this is a test!";
	cout << str << endl;
	replaceAllSpaces(&str);
	cout << str << endl;

	return 0;
}
