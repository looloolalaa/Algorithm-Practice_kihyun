#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, k, n;
	vector<int> v;
	vector<int> answer;
	int len = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		v.push_back(N);
		n = N;
		k = i;
		v.push_back(k);
		while (n - k >= 0) {
			v.push_back(n - k);
			int temp = k;
			k = n - k;
			n = temp;
		}
		if (len < v.size()) {
			len = v.size();
			answer = v;
		}
		v.clear();
	}

	cout << len << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << endl;
}