#include <iostream>
#include <string>
#include <vector>
#define SIZE 51
using namespace std;


int main() {
	vector<int> num;
	string s = "";
	char ch;
	int ans = 0;
	int first = 0;   //첫번째로 -가 나오는 인덱스
	bool tof = true;
	for (int i = 0; i < SIZE; i++) {  //입력
		ch = getchar();
		if (ch == '\n') {
			num.push_back(stoi(s));
			break;
		}
		else if (ch == '+' || ch == '-') {
			num.push_back(stoi(s));
			if (ch == '-' && tof) {
				first = num.size();
				tof = false;
			}
			s = "";
		}
		else
			s += ch;
	}



	if (first == 0) {   //모두 +면
		for (int i = 0; i < num.size(); i++) {
			ans += num[i];
		}
	}
	else {  //하나라도 -가 있으면
		for (int i = 0; i < num.size(); i++) {
			if (i < first)
				ans += num[i];
			else
				ans -= num[i];
		}
	}
	cout << ans << endl;
}