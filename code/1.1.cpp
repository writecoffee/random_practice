#include <iostream>
#include <cstring>
using namespace std;

bool test_uniq_char(char *testchar) {
	unsigned int length 	= strlen(testchar);	

	// 'a' is 97, 'A' is 65, make sure the mask has enough bit to 
	// store the ('z' - 'A')th -- 57th bit
	unsigned long mask 	= 0;
	unsigned long bit	= 1;

	for (int i = 0; i < length; ++i) {
		// '<<' has higher precedence than '&' operator
		if ((mask & (bit << (testchar[i] - 'A'))) > 0) {
			return true;
		} else {
			mask |= (bit << (testchar[i] - 'A')); 
		}
	 }

	return false;
}

int main() {
	char testchar[] = "zbcdefghz";
	if (test_uniq_char(testchar))
		cout << "has uniq char" << endl;
	else
		cout << "no uniq char" << endl;

	return 0;
}
