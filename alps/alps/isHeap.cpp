#include <stdio.h>

int arr[] = { 0, 2, 5, 6, 8, 9, 10 };
int length = sizeof(arr) / sizeof(arr[0]);

bool isValid(int a[], int parent) {
	return a[parent] <= a[2 * parent] && a[parent] <= a[2 * parent + 1];
}

bool isHeapRecur(int a[], int size) {
	int parent = length - size + 1;
	if (2 * parent >= length) return true;
	return isValid(a, parent) && isHeapRecur(a, size - 1);
}

bool isHeapIter(int a[], int size) {
	for (int i = 1; i < size; i++) {
		if (2 * i < size) {
			if (a[i] > a[i * 2]) return false;
		}
		if (2 * i + 1 < size) {
			if (a[i] > a[i * 2 + 1]) return false;
		}
	}
	return true;
}

int main() {
	
	printf("%d\n", isHeapRecur(arr,length));
}