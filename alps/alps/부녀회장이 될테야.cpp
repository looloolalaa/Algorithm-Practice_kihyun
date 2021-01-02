#include <iostream>
using namespace std;
int table[15][15];

int sum(int x,int y) {
	int res = 0;
	for (int i = 0; i <= y; i++) {
		res += table[x][i];
	}
	return res;
}

int main() {
	
	int T;
	int n, k;
	cin >> T;
	int* answer = new int[T];
	

	for (int i = 0; i < 15; i++) {
		table[0][i] = i + 1;
	}
	
	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			table[i][j] = sum(i - 1, j); //00
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> n >> k;
		answer[i] = table[n][k - 1];
	}

	for (int i = 0; i < T; i++) {
		cout << answer[i] << endl;
	}

	delete[] answer;
}