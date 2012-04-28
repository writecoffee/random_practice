///////////////////////////////////////////////////////////////////
// concatenate s1, s2 into a new string s3 and look for s2's pos in 
// s3; if NULL returned then false
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

bool is_rotation(char *str1, char *str2) {
	unsigned int len1 = strlen(str1);	
	unsigned int len2 = strlen(str2);
	if (len1 != len2) return false;
	char *cat = new char[len1 + len2];
	strcpy(cat, str1);
	strcat(cat, str1);
	
	return (strstr(cat, str2) == NULL ? false : true);
}

int main() {
	char *str1 = "this";	
	char *str2 = "this";
	cout << (is_rotation(str1, str2) ? "true" : "false") << endl;
	return 0;
}
