#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int P[1001];
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	sort(P, P + n);
	for (int i = 0; i < n; i++) {
		sum += P[i] * (n - i);
	}
	cout << sum << endl;
}