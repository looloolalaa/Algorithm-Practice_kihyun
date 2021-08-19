#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_SIZE 200

class HeapNode {
private:
	int key;
	int i, j;
public:
	HeapNode(int val = 0, int i = -1, int j = -1) :key(val), i(i), j(j) {}
	void setKey(int val) { key = val; }
	int getKey() { return key; }
	int getStart() { return i; }
	int getEnd() { return j; }
	void display() { printf("%d%d\n%d\n", i, j, key); }
};

class MaxHeap {
protected:
	HeapNode node[MAX_SIZE];
	int size;
public:
	MaxHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size+1 >= MAX_SIZE; }

	HeapNode getParent(int i) { return node[i / 2]; }
	HeapNode getLeft(int i) { return (i * 2 > size) ? -1 : node[i * 2]; }
	HeapNode getRight(int i) { return (i * 2 + 1 > size) ? -1 : node[i * 2 + 1]; }

	void insert(HeapNode n) {
		if (isFull()) return;
		else {
			int child = ++size;
			while (child != 1 && getParent(child).getKey() < n.getKey()) {
				node[child] = getParent(child);
				child = child / 2;
			}
			node[child] = n;
		}
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;
		else {
			HeapNode removed = node[1];
			int key = node[size--].getKey();

			int parent = 1;
			int child = 2;
			while (child <= size) { // 자식이 둘 다 없을때 까지
				int left_key = getLeft(parent).getKey();
				int right_key = getRight(parent).getKey();

				if (child == size) { //왼쪽 자식만 있으면
					if (left_key <= key) break;
					else {
						node[parent] = getLeft(parent);
						parent = parent * 2;
						child = parent * 2;
					}
				}

				else { //자식이 둘 다 있으면
					if (left_key < right_key) child++;
					if (node[child].getKey() <= key) break;
					else {
						node[parent] = node[child];
						parent = child;
						child = parent * 2;
					}
				}
			}
			node[parent].setKey(key);

			return removed;
		}
	}

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				printf("\n");
				level = level * 2;
			}
			node[i].display();
		}
		printf("\n");
	}

};

class MinHeap : public MaxHeap {
public:
	void insert(int weight, int start, int end) {
		HeapNode n(weight, start, end);
		if (isFull()) return;
		else {
			int child = ++size;
			while (child != 1 && getParent(child).getKey() > n.getKey()) {
				node[child] = getParent(child);
				child = child / 2;
			}
			node[child] = n;
		}
	}
	void insert(HeapNode n) {
		if (isFull()) return;
		else {
			int child = ++size;
			while (child != 1 && getParent(child).getKey() > n.getKey()) {
				node[child] = getParent(child);
				child = child / 2;
			}
			node[child] = n;
		}
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;
		else {
			HeapNode removed = node[1];
			HeapNode key_node = node[size--];
			int key = key_node.getKey();

			int parent = 1;
			int child = 2;
			while (child <= size) { // 자식이 둘 다 없을때 까지
				int left_key = getLeft(parent).getKey();
				int right_key = getRight(parent).getKey();

				if (child == size) { //왼쪽 자식만 있으면
					if (left_key >= key) break;
					else {
						node[parent] = getLeft(parent);
						parent = parent * 2;
						child = parent * 2;
					}
				}

				else { //자식이 둘 다 있으면
					if (left_key > right_key) child++;
					if (node[child].getKey() >= key) break;
					else {
						node[parent] = node[child];
						parent = child;
						child = parent * 2;
					}
				}
			}
			node[parent]=key_node;

			return removed;
		}
	}
};

//void heapSort(int data[], int size) {
//	MaxHeap heap;
//	for (int i = 0; i < size; i++)
//		heap.insert(HeapNode(data[i]));
//
//	for (int i = size - 1; i >= 0; i--) 
//		data[i] = heap.remove().getKey();
//}
//
//int main() {
//	MinHeap heap;
//	heap.insert(HeapNode(10));
//	heap.insert(HeapNode(5));
//	heap.insert(HeapNode(30));
//	heap.insert(HeapNode(8));
//	heap.insert(HeapNode(9));
//	heap.insert(HeapNode(3));
//	heap.insert(HeapNode(7));
//	heap.display();
//
//	heap.remove(); heap.display();
//	heap.remove(); heap.display();
//
//
//	printf("\n--Heap Sort--\n");
//	int numbers[10] = {};
//	for (int i = 0; i < 10; i++)
//		numbers[i] = rand() % 100;
//
//	cout << "before\n";
//	for (int i = 0; i < 10; i++)
//		cout << numbers[i] << " ";
//	printf("\n");
//
//	heapSort(numbers, 10);
//	cout << "after\n";
//	for (int i = 0; i < 10; i++)
//		cout<<numbers[i]<<" ";
//	printf("\n");
//}