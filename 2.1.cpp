///////////////////////////////////////////////////////////////////
// method1: 	use hash table to record elements
// 		O(n) space; O(n) time
// method2: 	use two iterators: runner's duty is to check dup
//		O(1) space; O(n^2) time
///////////////////////////////////////////////////////////////////
 
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

#define MAX_VALUE 10

// Hash table (with KEY = VALUE)
template <class T>
class HashTable {
private:
	list<T> *table;
	int _m;

public:
	HashTable(int size) {
		table = new list<T>[size];
		_m = size;
	}
	

	void insert(T value) {
		table[hash(value)].push_back(value);
	}

	bool has_value(T value) {
		typedef typename list<T>::iterator l_iter;

		list<T> *l_bucket	= &table[hash(value)];
		l_iter iter		= l_bucket->begin();

		while (iter != l_bucket->end()) {
			if (*iter == value) return true;
			else iter++;
		}

		return false; 
	}

private:
	int hash(T value) {
		return value % _m;
	}
};

void remove_dup_hash(list<int> *ll) {
	HashTable<int> hash_table(MAX_VALUE);
	list<int>::iterator iter = ll->begin();

	while (iter != ll->end()) {
		if (!hash_table.has_value(*iter)) hash_table.insert(*iter++);
		else iter = ll->erase(iter);
	}
}

void remove_dup_no_hash(list<int> *ll) {
	list<int>::iterator iter, checker;
	iter = checker = ll->begin();

	while (iter != ll->end()) { 
		// checker checks iter's previous duplicate elem
		while (checker != iter && *checker != *iter) ++checker;
		if (checker != iter) ll->erase(checker);

		++iter;
		checker = ll->begin();
	}
}

void print_list(list<int> *ll) {
	list<int>::iterator iter = ll->begin();
	while (iter != ll->end()) {
		cout << *iter << " ";
		iter++;
	}

	cout <<endl;
}

int main() {
	int length = 10;
	list<int> ll1; 
	for (int i = 0; i < length; ++i) ll1.push_back(rand() % MAX_VALUE);
	
	print_list(&ll1);
	remove_dup_hash(&ll1);
	print_list(&ll1);

	list<int> ll2; 
	for (int i = 0; i < length; ++i) ll2.push_back(rand() % MAX_VALUE);
	
	print_list(&ll2);
	remove_dup_no_hash(&ll2);
	print_list(&ll2);

	return 0;
}
