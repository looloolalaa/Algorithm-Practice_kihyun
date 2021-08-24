#include <iostream>
using namespace std;

#define MAX_SIZE 200
inline int ascend(int x, int y) { return x - y; }
inline int descend(int x, int y) { return y - x; }

void show_list(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%3d", list[i]);
	printf("\n");
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//¼±ÅÃ
void selectionSort(int list[], int n, int (*f)(int, int)) {
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (f(list[j], list[least]) < 0) {
				least = j;
			}
		}
		swap(list[i], list[least]);
	}
}

//»ğÀÔ
void insertionSort(int list[], int n) {
	for (int i = 1; i < n; i++) {
		int card = list[i];
		int j;
		for (j=i-1; card < list[j] && j>=0; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = card;
	}
}

//¹öºí
void bubbleSort(int list[], int n) {
	for (int i = n-1; i >= 0; i--) {
		printf("%d ½ºÄµ\n", n - i);
		int count = 0;
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				count++;
			}
		}
		if (count == 0) break;
	}
}

int main() {
	int list[MAX_SIZE];
	int n = 16;

	int test[6] = { 5,3,8,1,2,7 };
	int m = 6;

	for (int i = 0; i < n; i++)
		list[i] = rand() % 100;

	printf("Before\n");
	show_list(list, n);
	
	//selectionSort(list, n, ascend);
	//insertionSort(list, n);
	bubbleSort(list, n);

	printf("After\n");
	show_list(list, n);
}