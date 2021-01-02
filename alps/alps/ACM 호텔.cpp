#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int T;
	int H, W, N;
	cin >> T;
	int* answer = new int[T];
	int front, back;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		if (N % H == 0) {
			back = N / H;
			front = H;
		}
		else {
			back = N / H + 1;
			front = N % H;
		}
		answer[i] = front * 100 + back;
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << endl;
}