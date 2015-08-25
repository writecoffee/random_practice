#include <iostream>
#include <sstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

static void swap(string *array[], int (*ana_rcd)[26], int ap, int bp) {
	string *tmp = array[ap];
	array[ap] = array[bp];
	array[bp] = tmp;
	int arr_tmp[26];
	memcpy(arr_tmp, ana_rcd + ap, sizeof(ana_rcd[ap]));
	memcpy(ana_rcd + ap, ana_rcd + bp, sizeof(ana_rcd[ap]));
	memcpy(ana_rcd + bp, arr_tmp, sizeof(ana_rcd[bp]));
}

struct AnaRcd {
	AnaRcd(const int (&ana_rcd)[26]) : value(ana_rcd) { }
	const int (&value)[26];
};

int operator<(const AnaRcd &p1, const AnaRcd &p2) {
	for (int i = 0; i < 26; ++i) { 
		if (p1.value[i] < p2.value[i]) return true; 
		else if (p1.value[i] > p2.value[i]) return false;
	}

	return false;
}

int operator>(const AnaRcd &p1, const AnaRcd &p2) {
	for (int i = 0; i < 26; ++i) { 
		if (p1.value[i] > p2.value[i]) return true; 
		else if (p1.value[i] < p2.value[i]) return false; 
	}

	return false;
}

#define P make_pair
#define A AnaRcd
static void partition(string *array[], int (*ana_rcd)[26], int lp, int rp) {
	if (rp - lp == 1 || lp >= rp) { return; }

	int i = lp, j = rp - 1, pivot = lp + rand() % (rp - lp);

	while (A(ana_rcd[i]) < A(ana_rcd[pivot])) { ++i; }
	while (A(ana_rcd[j]) > A(ana_rcd[pivot])) { --j; }
	while (i != pivot || j != pivot) {
		if (i == pivot) {
			swap(array, ana_rcd, j, pivot + 1);
			swap(array, ana_rcd, pivot + 1, pivot);
			pivot = i + 1;
			i++;
		} else if (j == pivot) {
			swap(array, ana_rcd, i, pivot - 1);
			swap(array, ana_rcd, pivot - 1, pivot);
			pivot = j - 1;
			j--;
		} else {
			// swap the value of <pivot and >pivot
			if (A(ana_rcd[j]) < A(ana_rcd[pivot]) && 
				A(ana_rcd[i]) > A(ana_rcd[pivot])) {
				swap(array, ana_rcd, i, j);
			} 
			// equivalent value, skip over
			else { i++; j++; }
		}

		while (A(ana_rcd[i]) < A(ana_rcd[pivot])) { ++i; }
		while (A(ana_rcd[j]) > A(ana_rcd[pivot])) { --j; }
	}

	partition(array, ana_rcd, lp, pivot);
	partition(array, ana_rcd, pivot, rp);
}

static void quick_sort(string *array[], int (*ana_rcd)[26], const int cnt) {
	partition(array, ana_rcd, 0, cnt);
}

static void record_anagram(int (&ana_rcd)[26], const string &str) {
	for (int i = 0; i < str.length(); ++i) {
		ana_rcd[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i) { cout << ana_rcd[i]; }
	cout << endl;
}

static void sort_anagrams(string *array[], const int cnt) {
	int ana_rcd[cnt][26];
	memset(ana_rcd, 0, sizeof(ana_rcd));
	for (int i = 0; i < cnt; ++i) {
		record_anagram(ana_rcd[i], *array[i]);
	}
	
	quick_sort(array, ana_rcd, cnt);
}

static void test() {
	string *array[] = {
		new string("god"), 
		new string("cinema"), 
		new string("iceman"), 
		new string("amenci"), 
		new string("dog")
	};

	sort_anagrams(array, sizeof(array) / sizeof(string *));

	for (int i = 0; i < sizeof(array) / sizeof(string *); ++i) {
		cout << *array[i] << endl;
	}
}

int main() {
	srand(time(0));
	test();
	return 0;
}
