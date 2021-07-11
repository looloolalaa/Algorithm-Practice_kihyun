#include <iostream>
using namespace std;

int a(int m, int n) {
	if (m == 0) { cout << "return 1" << endl; return 1; }
	if (m == 1 && n == 0) { cout << "return 2" << endl; return 2; }
	if (m > 1 && n == 0) {
		cout << "return m+2" << endl; return m + 2;
	}
	if (m > 0 && n > 0) {
		cout << "return a(a(m - 1, n), n - 1)" << endl; return a(a(m - 1, n), n - 1);
	}
}

int main() {
	cout << a(3, 3) << endl;
}