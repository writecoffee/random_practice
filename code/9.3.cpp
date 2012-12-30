//////////////////////////////////////////////////////////////////////////////////////
//  modify binary search -- seperate it into two situations
//////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int search(int array[], int tar, int left, int right) {
	if (right - left == 1) {
		if (tar == array[left]) { return left; }
		else { return -1; }
	}

	int mid = left + (right - left) / 2;
	// in case left half ascending and left shifted
	if (array[left] < array[mid]) 
	{
		// ordered ascending half
		if (tar >= array[left] && tar < array[mid]) { 
			search(array, tar, left, mid); 
		}
		// disordered half
		else if (tar < array[left] || tar > array[mid]) { 
			search(array, tar, mid + 1, right); 
		}
		// binary search ends
		else { 
			return mid; 
		}
	} 
	// in case original array right shifted
	else if (array[left] >= array[mid]) 
	{
		// disordered half
		if (tar >= array[left] || tar < array[mid]) { 
			search(array, tar, left, mid); 
		}
		// ordered ascending half
		else if (tar < array[left] && tar > array[mid]) { 
			search(array, tar, mid + 1, right); 
		}
		// binary search ends
		else { 
			return mid; 
		}
	}
}

void tc_right_shifted() {
	int array[] = {96, 97, 98, 99, 1, 2, 3, 4, 5};
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
		int index = search(array, array[i], 0, sizeof(array) / sizeof(int));
		cout << "target value: " << array[i] << " lies at position - " << index << endl;
	}

	cout << search(array, 100, 0, 9) << endl;
}

void tc_left_shifted() {
	int array[] = {4, 5, 96, 97, 98, 99, 1, 2, 3};
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
		int index = search(array, array[i], 0, sizeof(array) / sizeof(int));
		cout << "target value: " << array[i] << " lies at position - " << index << endl;
	}

	cout << search(array, 100, 0, 9) << endl;
}

void tc_dup() {
	int array[] = {96, 96, 96, 96, 1, 1, 1, 1, 1};
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
		int index = search(array, array[i], 0, sizeof(array) / sizeof(int));
		cout << "target value: " << array[i] << " lies at position - " << index << endl;
	}

	cout << search(array, 100, 0, 9) << endl;
}

int main() {
	tc_right_shifted();
	tc_left_shifted();
	tc_dup();
	return 0;
}
