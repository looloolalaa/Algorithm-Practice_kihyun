#include <iostream>
#include <math.h>
#define SIZE 129
using namespace std;

class ColorPaper {
private:
	char data[SIZE][SIZE];
	int blue = 0, white = 0;
	int n;
	double k;
public:
	bool init() {
		cin >> n;
		k = log2(n);

		if (!(1 <= k && k <= 7 && k - (int)k == 0))  //조건검사
			return false;

		for (int i = 0; i < n; i++)  //입력
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		return true;
	}
	bool check(int i, int j, int len) {
		bool tof = true;
		char now = data[i][j];
		for (int x = i; x < i + len; x++) {  //하나라도 다르면 fasle 대입
			for (int y = j; y < j + len; y++) {
				if (now != data[x][y]) {
					tof = false;
					break;
				}
			}
		}
		return tof;
	}
	void divide_and_conquer(int i, int j, int len) {  //시작점과 변 길이
		if (!check(i, j, len)) {  //틀리면
			divide_and_conquer(i, j, len / 2);
			divide_and_conquer(i, j + len / 2, len / 2);
			divide_and_conquer(i + len / 2, j, len / 2);
			divide_and_conquer(i + len / 2, j + len / 2, len / 2);
		}
		else {  //맞으면
			if (data[i][j] == '1')
				blue++;
			else if (data[i][j] == '0')
				white++;
		}
	}

	void play() {
		if (init()) {
			divide_and_conquer(0, 0, n);
			show();
		}
	}
	void show() {
		cout << white << endl;
		cout << blue << endl;
	}
};


int main() {

	ColorPaper p;
	p.play();
}