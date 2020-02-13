#include <iostream>
#include <string>
#define SIZE 100001
using namespace std;

class Histogram {
private:
	int n;
	int data[SIZE];
	int max_area;
	string answer = "";
public:
	int init() {
		cin >> n;
		if (n != 0)
			for (int i = 0; i < n; i++)
				cin >> data[i];
		return n;
	}
	void calc() {
		int width, height, area;
		int s, e;
		for (int i = 0; i < n; i++) {
			height = data[i];
			s = i;
			e = i;
			while (s >= 0 && data[s] >= height)s--;
			while (e < n && data[e] >= height)e++;
			width = e - s - 1;
			area = width * height;

			if (i == 0)
				max_area = area;
			else if (max_area < area)
				max_area = area;
		}
	}

	void play() {
		while (init() != 0) {
			calc();
			answer += to_string(max_area) + '\n';
		}
		show();

	}

	void show() {
		cout << answer;
	}
};

int main() {
	Histogram h;
	h.play();
}