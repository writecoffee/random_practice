#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

template <typename T>
struct pq_pair {
	pq_pair(T element, int position) : elem(element), pos(position) { }
	T elem; int pos;
};

template <typename T>
bool operator>(const pq_pair<T> &left, const pq_pair<T> &right) {
	return left.elem > right.elem;
}

string *n_merge_sort(string *data, int elem_cnt, int disk_size, int mem_size, int chunk_sz, int elem_sz, int chunk_cnt, int lst_chk, int lst_chk_sz) {
	assert(disk_size >= chunk_cnt * elem_sz);
	assert(mem_size < disk_size);
	assert(data);
	
	string *new_space = new string[elem_cnt];

	// just for simulation
	priority_queue<pq_pair<string>, vector<pq_pair<string> >, greater<vector<pq_pair<string> >::value_type > > heap;

	// array reserved for recording current reading position for each chunk
	int pos_arr[chunk_cnt]; memset(pos_arr, 0, chunk_cnt * sizeof(int));

	// iterate the first element in each chunk
	for (int i = 0; i < chunk_cnt; ++i) { heap.push(pq_pair<string>(data[i * chunk_sz], i)); }

	int si = 0;
	while (si != elem_cnt) {
		pq_pair<string> min = heap.top(); heap.pop();
		new_space[si++].append(min.elem);
		pos_arr[min.pos]++;

		if (min.pos == lst_chk) {
			if (pos_arr[min.pos] < lst_chk_sz) {
				heap.push(pq_pair<string>(data[chunk_sz * min.pos + pos_arr[min.pos]], min.pos));
			}
			continue;
		} else if (pos_arr[min.pos] < chunk_sz) {
			heap.push(pq_pair<string>(data[chunk_sz * min.pos + pos_arr[min.pos]], min.pos));
		}
	}
	
	return new_space;
}

template <typename T>
string *chunk_sort(int disk_size, int mem_sz, T *data, int elem_cnt) {
	assert(data);
	assert(disk_size > mem_sz);

	int elem_sz		= sizeof(*data);
	int mem_chk_capacity	= ceil((double)mem_sz / elem_sz);
	int chunk_sz		= mem_chk_capacity;
	int dsk_chk_capacity	= ceil((double)disk_size / elem_sz);
	int chunk_cnt		= ceil((double)dsk_chk_capacity / mem_chk_capacity);
	int lst_chk_sz		= elem_cnt - dsk_chk_capacity / mem_chk_capacity * chunk_sz;
	int t			= dsk_chk_capacity / mem_chk_capacity;

	for (int i = 0; i < chunk_cnt - 1; ++i) {
		for (int j = 0; j < chunk_sz - 1; ++j) {
			sort(data + i * chunk_sz, data + (i + 1) * chunk_sz);
		}
	}

	if (lst_chk_sz == 0) {
		return n_merge_sort(data, elem_cnt, disk_size, mem_sz, chunk_sz, elem_sz, chunk_cnt, t + 1, chunk_sz);
	} else {
		sort(data + t * chunk_sz, data + t * chunk_sz + lst_chk_sz);
		return n_merge_sort(data, elem_cnt, disk_size, mem_sz, chunk_sz, elem_sz, chunk_cnt, t, lst_chk_sz);
	}
}

int test() {
	const int elem_cnt	= 5;

	string *disk = new string[elem_cnt];
	disk[0] = string("Line 2: Right! I'll be there.");
	disk[1] = string("Line 1: Is this a test?");
	disk[2] = string("Line 3: COME ON!");
	disk[3] = string("Line 4: Baby!");
	disk[4] = string("Line 5: Good purchase");

	int disk_sz 		= sizeof(*disk) * elem_cnt;
	int mem_sz 		= sizeof(*disk) * 2;

	string *result = chunk_sort<string>(disk_sz, mem_sz, disk, elem_cnt);
	for (int i = 0; i < elem_cnt; ++i) { cout << result[i] << endl; }
}

int main() {
	test();
 	return 0;
}
