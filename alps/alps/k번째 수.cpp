#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	int k; cin >> k;

	int left = 1, right = k;
	int mid;
	int answer;

	while (left <= right) {
		int cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt < k)
			left = mid + 1;
		else {
			right = mid - 1;
			answer = mid;
		}

	}
	cout << answer << endl;
}