#include <iostream>
using namespace std;
#define K 27    //최대사람수
#define N 1001   //최대 사다리수

struct Point {
	int i, j;
};

class Ladder {
private:
	char data[N + 2][K + 1];             //사다리
	int k, n;                       //사람,사다리 수
	char end[K + 1];                  //도착 문자열 
	Point s, e;                     //시작, 끝 포인터
	int line;                       //찾고자하는 물음표 라인의 인덱스
public:
	Ladder();
	~Ladder();
	void play();

	bool init();         //사다리 초기화
	void show();
	void ready(char ch);  //s,e포인터 초기화
	void go();              //?까지 s,e포인터를 이동
	bool isValid();         //?에 도착한 s,e 의 유효성 검사
	bool check_and_add(Point a, Point b);  //추가하거나 검사
	void show_answer();
	void show_x();
	void test();
	int min(int x, int y);
	int abs(int num);
};

Ladder::Ladder() {
}

Ladder::~Ladder() {

}

bool Ladder::init() {
	cin >> k;
	cin >> n;   //[n+2][k+1]개의 배열 필요

	if (!(3 <= k && k <= K && 3 <= n && n <= N)) //최대값 확인
		return false;

	for (int i = 0; i < n + 2; i++) {  //사다리 *로 초기화
		for (int j = 0; j < k + 1; j++)
			data[i][j] = '*';
	}

	cin >> end;
	for (int i = 1; i < k + 1; i++) {
		data[0][i] = 'A' + i - 1;     //시작 문자열 초기화
		data[n + 1][i] = end[i - 1];  //도착 문자열 초기화
	}

	for (int i = 0; i < n; i++) {  //사다리 입력
		cin >> end; //end재활용
		if (end[0] == '?')
			line = i + 1;
		for (int j = 0; j < k - 1; j++)
			data[i + 1][j + 1] = end[j];
	}

	return true;
}

void Ladder::show() {
	cout << endl;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < k + 1; j++)
			cout << data[i][j];
		cout << endl;
	}
}

void Ladder::ready(char ch) {       //s,e 준비완료
	for (int i = 0; i < k; i++) {
		if (ch == data[0][i + 1]) {
			s.i = 0;
			s.j = i + 1;
		}
		if (ch == data[n + 1][i + 1]) {
			e.i = n + 1;
			e.j = i + 1;
		}
	}
}

void Ladder::go() {    //자신과 왼쪽놈을 같이 비교 "**"면 아무것도 "-*"면 왼쪽으로 "*-"면 오른쪽으로
	while (s.i != line) {        //물음표라인 까지
		if (data[s.i][s.j - 1] == '-'&& data[s.i][s.j] == '*') {  //왼쪽
			s.j--;
		}
		else if (data[s.i][s.j - 1] == '*'&& data[s.i][s.j] == '-') {  //오른쪽
			s.j++;
		}
		s.i++;  //아래로 움직이는 s포인터
	}
	while (e.i != line) {
		if (data[e.i][e.j - 1] == '-'&& data[e.i][e.j] == '*') {
			e.j--;
		}
		else if (data[e.i][e.j - 1] == '*'&& data[e.i][e.j] == '-') {
			e.j++;
		}
		e.i--;  //위로 움직이는 e포인터
	}
}

bool Ladder::isValid() { //j 차이가 -1,0,1 만 유효
	return abs(s.j - e.j) <= 1;
}

bool Ladder::check_and_add(Point a, Point b) {
	char same_answer[5] = "**";          //s,e 포인터가 같으면 ??는 "**"
	char dif_answer[5] = "*-*";        //s,e 포인터가 다르면 ???는 "*-*"

	if (a.j == b.j) {  //s==e
		for (int i = 0; i < 2; i++) {      //"**"
			if (data[line][a.j - 1 + i] == '?')         //?면 추가
				data[line][a.j - 1 + i] = same_answer[i];
			else if (data[line][a.j - 1 + i] != same_answer[i])  //?가 아니고 정답과 다르다면
				return false; //무효한 사다리
		}
	}
	else {  //s!=e
		int val = min(a.j, b.j);
		for (int i = 0; i < 3; i++) {   //"*-*"
			if (data[line][val - 1 + i] == '?')
				data[line][val - 1 + i] = dif_answer[i];
			else if (data[line][val - 1 + i] != dif_answer[i])
				return false;
		}
	}
	return true;
}

void Ladder::show_answer() {
	for (int i = 0; i < k - 1; i++)
		cout << data[line][i + 1];
	cout << endl;
}

void Ladder::show_x() {
	for (int i = 0; i < k - 1; i++)
		cout << 'x';
	cout << endl;
}

void Ladder::test() {
	cout << s.i << "," << s.j << endl;
	cout << e.i << "," << e.j << endl << endl;
}

int Ladder::min(int x, int y) {
	if (x > y)
		return y;
	else
		return x;
}

int Ladder::abs(int num) {
	if (num < 0)
		return -num;
	else
		return num;
}

void Ladder::play() {
	if (init()) {                  //초기화 성공시
		int i;
		for (i = 0; i < k; i++) { //사람수 만큼
			ready('A' + i);       //s,e 포인터 초기화
			go();                 //?까지 s,e포인터 출발
			if (!isValid())       //?까지 도달한 s,e포인터가 유효한지 검사
				break;
			else if (!check_and_add(s, e)) //추가하거나 검사하거나
				break;

		}

		if (i == k)  //반복문이 break하지않고 끝까지 왔다면
			show_answer();
		else        //중간에 break 했다면 무효한 사다리
			show_x();

	}
}

int main() {

	Ladder l;
	l.play();
}