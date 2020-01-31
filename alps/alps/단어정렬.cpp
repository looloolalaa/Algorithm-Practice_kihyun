#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void show(string* arr, int len) {
	for (int i = 1; i < len + 1; i++) {
		if (arr[i] == arr[i - 1]) {
			continue;
		}
		else {
			cout << arr[i - 1] << endl;
		}
	}
}
bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	int n;
	string arr[20001];
	cin >> n;

	if (1 <= n && n <= 20000) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];

		}
	}
	sort(arr, arr + n, cmp);
	show(arr, n);

}