#include <iostream>
using namespace std;

class Yose {
private:
	int n, k;
	int point = -1;
	int* arr;
	int loop;
public:
	Yose(int n, int k) {
		this->n = n;
		this->k = k;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i + 1;
		loop = n;
	}
	~Yose() { delete[] arr; }
	int plus_point() { return point = (point + 1) % n; }

	void cal() {
		if (loop-- == 0)
			return;
		for (int count = 0; count < k;) {
			if (arr[plus_point()] != 0)
				count++;
		}
		cout << arr[point] << ", ";
		arr[point] = 0;
		cal();
			
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	if (1 <= k && k <= n && n <= 1000) {
		Yose y(n, k);
		cout << "<";
		y.cal();
		cout << "\b\b>" << endl;
	}
}