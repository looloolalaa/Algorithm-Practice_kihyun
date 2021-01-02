//이런 어이없는 문제를 보았나 구글링입니다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	double x, y;
	vector<int> ans;

	cin >> t;

	while (t--) {
		cin >> x >> y;
		double i = 1, cnt = 0;

		// y-x보다 큰 제곱수i 구하기
		for (;; i++) {
			if (i * i > y - x)
				break;
		}

		// y-x가 i-1의 제곱수일 경우 
		if ((i - 1) * (i - 1) == y - x)
			cnt = 2 * (i - 1) - 1;
		// i-1의 제곱수 < y-x <= 중간지점 인 경우
		else if ((i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2) >= y - x)
			cnt = 2 * i - 2;
		// 중간지점 < y-x < i의 제곱수 인 경우
		else
			cnt = 2 * i - 1;

		ans.push_back(cnt);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		printf("%d\n", *i);

	return 0;
}