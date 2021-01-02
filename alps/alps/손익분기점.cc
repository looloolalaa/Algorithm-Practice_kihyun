#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	double y;
	cin >> a >> b >> c;
	if (c <= b)
		cout << "-1" << endl;
	else {
		y = (double)a / ((double)c - b);
		cout << (int)y + 1 << endl;
	}
}