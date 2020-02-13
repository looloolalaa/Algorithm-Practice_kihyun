/*
#include <iostream>
using namespace std;
int memo[100];

int fib1(int n) {  //Àç±Í
	if (n <= 1)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n) {  //¸Þ¸ð
	if (n <= 1) {
		memo[n] = n;
		return n;
	}
	else if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = fib2(n - 1) + fib2(n - 2);
}


struct Mat {  //Çà·Ä
	long long a1, a2;
	long long b1, b2;
	Mat(long long _a1=0, long long _a2=0, long long _b1=0, long long _b2=0):
		a1(_a1),a2(_a2),b1(_b1),b2(_b2){}
	const Mat operator*(const Mat &A) {
		Mat ret;
		ret.a1 = this->a1*A.a1 + this->a2*A.b1;
		ret.a2 = this->a1*A.a2 + this->a2*A.b2;
		ret.b1 = this->b1*A.a1 + this->b2*A.b1;
		ret.b2 = this->b1*A.a2 + this->b2*A.b2;
		return ret;
	}
};
Mat fib3(int n) {  //Çà·Ä°ö
	if (n == 0)
		return Mat(1,1,1,0);
	return Mat(1,1,1,0)*fib3(n - 1);
}

Mat fib4(int n) {
	if (n <= 1)
		return Mat(1, 1, 1, 0);
	else if (n % 2)
		return fib4(n / 2)*fib4(n / 2 + 1);
	else
		return fib4(n / 2)*fib4(n / 2);
}

int main() {
	int n;
	cin >> n;
	cout <<fib4(n).a2  << endl;
}*/
#include <iostream>
using namespace std;
const int mod = 1000000;
const int p = mod / 10 * 15;
int fibo[p] = { 0,1 };
int main() {
	long long n;
	cin >> n;
	for (int i = 2; i < p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}
	cout << fibo[n%p] << '\n';
	return 0;
}