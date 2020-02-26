#include <iostream>
using namespace std;

struct Set {
	int way;
	int len;
};

Set s[6];
int max_size, min_size; //큰 사각형에서 작은 사각형을 뺀 넓이가 육각형 전체 넓이!

void get_size(int way1, int way2) {
	int M_width, M_height;
	int m_width, m_height;

	for (int i = 0; i < 6; i++) {
		if (s[i].way == way1)
			M_height = s[i].len;
		else if (s[i].way == way2) {
			M_width = s[i].len;
			m_width = s[(i + 2) % 6].len;
			m_height = s[(i + 3) % 6].len;
		}

	}
	max_size = M_width * M_height;
	min_size = m_width * m_height;
}

int main() {
	int K; cin >> K;

	int right_count = 0, down_count = 0;  //방향으로 육각형의 모양 확인!!!

	for (int i = 0; i < 6; i++) {
		cin >> s[i].way >> s[i].len;
		if (s[i].way == 1)
			right_count++;
		if (s[i].way == 3)
			down_count++;
	}

	if (right_count == 1 && down_count == 1) { //오른쪽 위가 빈
		get_size(3, 1);
	}
	else if (right_count == 1 && down_count == 2) { //왼쪽 위가 빈
		get_size(1, 4);
	}
	else if (right_count == 2 && down_count == 1) { //오른쪽 아래가 빈
		get_size(2, 3);
	}
	else if (right_count == 2 && down_count == 2) { //왼쪽 아래가 빈
		get_size(4, 2);
	}

	cout << K * (max_size - min_size) << endl;
}