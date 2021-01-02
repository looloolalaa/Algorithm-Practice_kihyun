#include <iostream>
using namespace std;
#define MAX 20000

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << "1" << endl;
		return 0;

	}

	int size[MAX];
	size[0] = 1;
	int i = 1;
	for (; i < MAX; i++) {
		size[i] = size[i - 1] + i * 6;
		if (size[i - 1] < N && N <= size[i])
			break;
	}
	cout << i + 1 << endl;
}