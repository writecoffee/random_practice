#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cmath>
using namespace std;



template <typename T>
void chunk_sort(int disk_size, int mem_size, T *data, int elem_cnt) {
	assert(data);
	assert(disk_size > mem_size);

	int elem_sz	= sizeof(*data);
	int chunk_sz	= ceil(mem_size / elem_sz);
	int chunk_cnt	= ceil(disk_size / chunk_sz);
	for (int i = 0; i < chunk_cnt; ++i) {
		for (int j = 0; j < chunk_sz - 1; ++j) {
			sort(data + j * chunk_sz, data + (j + 1) * chunk_sz);
		}
	}
}

template <typename T>
T *n_merge_sort(T *data, int elem_cnt, int disk_size, int mem_size, int chunk_sz, int elem_sz, int chunk_cnt) {
	assert(mem_size >= chunk_cnt * elem_sz);
	assert(mem_size < disk_size);
	assert(data);
	
	T *new_space = new T[elem_cnt];
	int si = 0;
	// NOTE: just for simulation
	mem_set(new_space, 0, elem_cnt);
	c_heap heap();
	int pos_arr[chunk_cnt];
	memset(pos_arr, 0, chunk_cnt * sizeof(int));
	for (int i = 0; i < chunk_cnt; ++i) {
		heap.heappush(make_pair<T, int>(data[i * chunk_sz], i));
	}

	while (si != elem_cnt) {
		pair<T, int> min = heap.heappop();
		new_space[si++] = min.first;
		pos_arr[min.second]++;
		if (pos_arr[min.second] + 1 != chunk_sz) {
			heap.heappush(make_pair<T, int>(data[chunk_sz * min.second + pos_arr[min.second]], min.second));
		}
	}
	
	return new_space;
}

int test() {

}

int main() {

 	return 0;
}
