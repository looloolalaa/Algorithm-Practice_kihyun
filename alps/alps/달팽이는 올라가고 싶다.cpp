#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	if ((V - A) % (A - B) != 0)
		cout << 1 + (V - A) / (A - B) + 1 << endl;
	else
		cout << 1 + (V - A) / (A - B) << endl;
}