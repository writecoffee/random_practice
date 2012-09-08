#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

template <typename T>
struct pq_pair {
	pq_pair(const T &element, int position) : elem(element), pos(position) { }
	const T &elem; int pos;
};

template <typename T>
bool operator>(const pq_pair<T> &left, const pq_pair<T> &right) {
	return left.elem > right.elem;
}

template <typename T>
T *n_merge_sort(T *data, int elem_cnt, int disk_size, int mem_size, int chunk_sz, int elem_sz, int chunk_cnt) {
	assert(mem_size >= chunk_cnt * elem_sz);
	assert(mem_size < disk_size);
	assert(data);
	
	T *new_space = new T[elem_cnt];
	int si = 0;
	// NOTE: just for simulation
	memset(new_space, 0, elem_cnt);
	priority_queue<pq_pair<T>/**, vector<pq_pair<T> >, greater<pq_pair<T> > **/> heap();
	int pos_arr[chunk_cnt];
	memset(pos_arr, 0, chunk_cnt * sizeof(int));
	for (int i = 0; i < chunk_cnt; ++i) {
		heap.push(pq_pair<T>(data[i * chunk_sz], i));
	}

	while (si != elem_cnt) {
		pq_pair<T> min = heap.top(); heap.pop();
		new_space[si++] = min.elem;
		pos_arr[min.pos]++;
		if (pos_arr[min.pos] + 1 != chunk_sz) {
			heap.push(pq_pair<T>(data[chunk_sz * min.pos + pos_arr[min.pos]], min.pos));
		}
	}
	
	return new_space;
}

template <typename T>
void chunk_sort(int disk_size, int mem_size, T *data, int elem_cnt) {
	assert(data);
	assert(disk_size > mem_size);

	int elem_sz		= sizeof(*data);
	int mem_chk_capacity	= ceil(mem_size / elem_sz);
	int chunk_sz		= mem_chk_capacity;
	int dsk_chk_capacity	= ceil(disk_size / elem_sz);
	int chunk_cnt		= ceil(dsk_chk_capacity / mem_chk_capacity);

	for (int i = 0; i < chunk_cnt; ++i) {
		for (int j = 0; j < chunk_sz - 1; ++j) {
			sort(data + j * chunk_sz, data + (j + 1) * chunk_sz);
		}
	}

	n_merge_sort<T>(data, elem_cnt, disk_size, mem_size, chunk_sz, elem_sz, chunk_cnt);
}



int test() {
	string *disk = new string[3];
	disk[0] = string("Line 2: Right! I'll be there.");
	disk[1] = string("Line 1: Is this a test?");
	disk[2] = string("Line 3: COME ON!");

	const int elem_cnt	= 3;
	int disk_sz 		= sizeof(disk) * elem_cnt;
	int mem_sz 		= sizeof(disk);

	chunk_sort<string>(disk_sz, mem_sz, disk, elem_cnt);
	cout << "done" << endl;
	
}

int main() {
	test();
 	return 0;
}
