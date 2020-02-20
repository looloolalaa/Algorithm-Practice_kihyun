#include <iostream>
using namespace std;

struct Range {
	double left = 0.5;  //첫번째
	double right = 1;   //두번째 부등식
	int count = 4;
};

double fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 2) + fib(n - 1);
}


Range get_range(int n) {  //부등식을 만족하는 정수 k의 개수가 점점 작아지는데
	Range k;              //그 개수가 0 이 되기 직전의 부등식 범위를 구하는 함수
	if (n == 1)
		return k;

	double now_left, now_right;
	double before = 0;


	int i;
	int count = 1;   //부등식을 만족하는 정수k의 개수

	for (i = 2; count > 0; i++) {  //i번째 조건
		if (i % 2) {       //홀수번일때 오른쪽에서 범위제한
			before = k.right;
			k.right = fib(i) / fib(i + 1);
		}
		else {  //짝수번일때 왼쪽 범위 제한
			before = k.left;
			k.left = fib(i) / fib(i + 1);
		}

		now_left = k.left*n;              //@@@@@@@@@@ k범위 @@@@@@@@@@@
		now_right = k.right*n;           //현재 now_left <= k <= now_right


		//부등식을 만족하는 k 개수 업데이트
		if (now_left - (int)now_left == 0)  //정수일때
			count = (int)now_right - now_left + 1;
		else  //소수일때
			count = (int)now_right - ((int)now_left + 1) + 1;
	}
	if (i % 2)
		k.left = before;
	else
		k.right = before;

	k.count = i;
	return k;
}


int main() {
	int n;
	cin >> n;
	if (!(0 < n&&n <= 30000))  //조건검사
		return 0;

	Range r = get_range(n);         //n=100 이면         61.5385 <= k <= 62.5
	//cout <<n*r.left << " <= k <= " << n*r.right << endl;

	int answer;
	if (n*r.left - (int)(n*r.left) == 0) //부등식을 만족하는 정수 k중 가장 작은 놈
		answer = n * r.left;
	else
		answer = ((int)n*r.left) + 1;


	//출력
	cout << r.count << endl;
	cout << n << " " << answer << " ";
	while (n - answer >= 0) {
		cout << n - answer << " ";
		int temp = answer;
		answer = n - answer;
		n = temp;
	}
	cout << endl;
}