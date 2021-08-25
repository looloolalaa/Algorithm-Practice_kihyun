#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 200

#define BUCKETS 10
#define DIGITS 4

void shell_sort(int arr[], int n) {

	for (int gap = n / 2; gap >= 1; gap = gap / 2) {

		if (gap % 2 == 0) gap++;

		for (int k = 0; k < gap; k++) {

			for (int i = k + gap; i < n; i = i + gap) {
				int card = arr[i];
				int j;
				for (j = i - gap; j >= 0 && arr[j] > card; j = j - gap) {
					arr[j + gap] = arr[j];
				}
				arr[j + gap] = card;
			}

		}

	}

}

void radix_sort(int arr[], int n) {
	queue<int> bucket[BUCKETS];
	for (int digit = 1; digit <= DIGITS; digit++) {
		int factor = pow(10, (digit - 1));
		for (int i = 0; i < n; i++) {
			bucket[(arr[i] / factor) % 10].push(arr[i]);
		}

		for (int i = 0, j = 0; i < BUCKETS; i++) {
			while (!bucket[i].empty()) {
				arr[j++] = bucket[i].front();
				bucket[i].pop();
			}
		}
	}
}




void show_list(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%5d", list[i]);
	printf("\n");
}

void merge(int arr[], int start, int mid, int end) {
	static int sorted[MAX_SIZE];
	int k = start;
	int i, j;
	for (i = start, j = mid + 1; i <= mid && j <= end; k++) {
		sorted[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}

	int s = (j > end) ? i : j;
	int e = (j > end) ? mid : end;
	for (int r = s; r <= e; r++)
		sorted[k++] = arr[r];

	for (int i = start; i <= end; i++)
		arr[i] = sorted[i];
}

void merge_sort(int arr[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void mergeSort(int arr[], int n) {
	merge_sort(arr, 0, n - 1);
}


int main() {
	int list[MAX_SIZE];
	int n = 16;

	for (int i = 0; i < n; i++)
		list[i] = rand() % 10000;

	printf("Before\n");
	show_list(list, n);

	radix_sort(list, n);

	printf("After\n");
	show_list(list, n);

}