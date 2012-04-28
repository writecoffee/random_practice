///////////////////////////////////////////////////////////////////////
// Write a method to determine if two strings are anagram or not.
// 1. cnt num of uniq chars in s1
// 2. detect whether s2 has other chars
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

// O(n)
bool is_anagram_On(char *s1, char *s2) {
	if (s1 == NULL || s2 == NULL) return false;

	unsigned int length1 = strlen(s1);
	unsigned int length2 = strlen(s2);
	if (length1 != length2) return false;

	int uniq_cnt[256];
	memset(uniq_cnt, 0, sizeof(uniq_cnt));
	for (int i = 0; i < length1; ++i) {
		uniq_cnt[s1[i]]++;
	} 

	for (int j = 0; j < length2; ++j) {
		if (uniq_cnt[s2[j]] == 0) return false;
		uniq_cnt[s2[j]]--;
	}

	return true;
}

// O(n)
bool is_anagram_On2(char *s1, char *s2) {
	if (s1 == NULL || s2 == NULL) return false;

	unsigned int length1 = strlen(s1);
	unsigned int length2 = strlen(s2);
	int s1_uniq_chars = 0;
	int complete_uniq_cnt = 0;

	if (length1 != length2) return false;

	int uniq_cnt[256];
	memset(uniq_cnt, 0, sizeof(uniq_cnt));
	for (int i = 0; i < length1; ++i) {
		if (uniq_cnt[s1[i]] == 0) ++s1_uniq_chars;
		++uniq_cnt[s1[i]];
	} 

	for (int j = 0; j < length2; ++j) {
		if (uniq_cnt[s2[j]] == 0) return false;
		uniq_cnt[s2[j]]--;

		// add one branch to judge complete count
		if (uniq_cnt[s2[j]] == 0) {
			++complete_uniq_cnt;

			if (s1_uniq_chars == complete_uniq_cnt)
				return j == length2 - 1;
		}
	}

	return false;
}

int main() {
	char *s1 = "aebbccmm";
	char *s2 = "bbaccmmb";

	cout << (is_anagram_On(s1, s2) ? "true" : "false") << endl;
	cout << (is_anagram_On2(s1, s2) ? "true" : "false") << endl;
	return 0;
}
