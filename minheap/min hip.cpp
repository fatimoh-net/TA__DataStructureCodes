#include <iostream> #include <algorithm>
class MinHeap {
private:
	int* heap; int capacity; int size;
	void heapify_up(int index) {
		int parent = (index - 1) / 2;
		if (index > 0 && heap[index] <
			heap[parent]) {
			std::swap(heap[index],
				heap[parent]); heapify_up(parent);
		}
	}
	void heapify_down(int index) {
		int smallest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left < size && heap[left] < heap[smallest]) {
			smallest = left;
		}
		if (right < size && heap[right] < heap[smallest]) {
			smallest = right;
		}
		if (smallest != index) {
			std::swap(heap[index],
				heap[smallest]); heapify_down(smallest);

		}
	}
public:
	MinHeap(int cap) : capacity(cap),
		size(0) {
		heap = new int[capacity];
	}
	~MinHeap() {
		delete[] heap;
	}
	void insert(int value) {
		if (size == capacity) {
			std::cout << "Heap is full" << std::endl;
			return;
		}
		heap[size] = value; heapify_up(size); size++;
	}
	void delete_root() {
		if (size == 0) {
			std::cout << "Heap is empty" << std::endl;
			return;
		}
		heap[0] = heap[size - 1]; size--;
		heapify_down(0);
	}
	void print_heap() {

		for (int i = 0; i < size; ++i) {
			std::cout << heap[i] << " ";
		}
		std::cout << std::endl;
	}
};
int main() {
	MinHeap min_heap(10);
	min_heap.insert(3); min_heap.insert(2); min_heap.insert(1);
	min_heap.print_heap(); min_heap.delete_root(); min_heap.print_heap(); return 0;
}

