#include <iostream>
using namespace std;

int main() {
	int N;
	int start;
	cin >> N;
	start = N / 5 + 1;
	int kg3;
	while (start-- >= 0) {
		int rest = N - start * 5;
		if (rest % 3 == 0) {
			kg3 = rest / 3;
			break;
		}
	}
	if (start < 0)
		cout << "-1" << endl;
	else
		cout << start + kg3 << endl;
}