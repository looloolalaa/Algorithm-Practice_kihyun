#include <iostream>
#define SIZE 11
using namespace std;
int A[SIZE];

/*int find(int len,int val) {
	int index;
	if (len % 2)
		index = (len - 1) / 2;
	else
		index = len / 2;

	int move = len / 4;

	while (1) {

		if (A[index - 1] <= val && val <= A[index])
			break;
		else if (A[index] > val)
			index -= move;
		else
			index += move;
		move /= 2;
	}
	return index-1;

}*/

int find2(int n, int k) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (A[i] <= k && k <= A[i + 1])
			break;
	}
	return i;
}

int main() {
	int n, k;
	int all_count = 0;

	cin >> n >> k;
	if (!(1 <= n && n <= 10 && 1 <= k && k <= 100000000)) //조건검사
		return 0;

	cin >> A[0];
	if (A[0] != 1)
		return 0;

	double mul;
	for (int i = 1; i < n; i++) { //배수확인
		cin >> A[i];
		mul = (double)A[i] / A[i - 1];
		if (mul - (int)mul != 0)
			return 0;
	}

	int max_index = find2(n, k);
	int coin;
	while (k != 0) {
		coin = A[max_index];
		int count = k / coin;
		all_count += count;
		k -= coin * count;

		while (A[max_index] > k)max_index--;
	}
	cout << all_count << endl;

}