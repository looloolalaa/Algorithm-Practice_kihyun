#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

vector<string> number;
vector<string> oper;
vector<string> equation;
vector<string> infix;

void permutation(string array, int start, int end) {
	if (start == end) {
		number.push_back(array);
	}
	else
	{
		for (int i = start; i <= end; i++) {
			swap(array[start], array[i]);
			permutation(array, start + 1, end);
			swap(array[start], array[i]);
		}
	}
}

char changed(int x) {
	if (x == 1)
		return '+';
	else if (x == 2)
		return '-';
	else if (x == 3)
		return '*';
	else
		return '/';
}

void card() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				string op = "";
				op.push_back(changed(i));
				op.push_back(changed(j));
				op.push_back(changed(k));
				oper.push_back(op);
			}
		}
	}
	

}

void get_equation() {
	for (int i = 0; i < number.size(); i++) {
		for (int j = 0; j < oper.size(); j++) {
			string str = "";
			str.push_back(number[i][0]);
			str.push_back(oper[j][0]);
			str.push_back(number[i][1]);
			str.push_back(oper[j][1]);
			str.push_back(number[i][2]);
			str.push_back(oper[j][2]);
			str.push_back(number[i][3]);
			equation.push_back(str);

		}
	}
}

void get_infix() {
	for (int i = 0; i < 7; i++) {
		vector<string> sample= equation;

		if (i == 0) {
			//
		}
		else if (i == 1) {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(0, "(");
				sample[j].insert(4, ")");
			}
		}
		else if (i == 2) {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(2, "(");
				sample[j].insert(6, ")");
			}
		}
		else if (i == 3) {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(4, "(");
				sample[j].insert(8, ")");
			}
		}
		else if (i == 4) {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(0, "(");
				sample[j].insert(6, ")");
			}
		}
		else if (i == 5) {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(2, "(");
				sample[j].insert(8, ")");
			}
		}
		else {
			for (int j = 0; j < sample.size(); j++) {
				sample[j].insert(0, "(");
				sample[j].insert(4, ")");
				sample[j].insert(6, "(");
				sample[j].insert(10, ")");
			}
		}

		infix.insert(infix.end(), sample.begin(), sample.end());
	}
}



int main() {
	string num="0000";
	int answer;
	cin >> num[0] >> num[1] >> num[2] >> num[3];


	permutation(num, 0, 3);
	//for (int i = 0; i < number.size(); i++) {
	//	cout << number[i] << endl;
	//}

	card();
	//for (int i = 0; i < oper.size(); i++) {
	//	cout << oper[i] << endl;
	//}

	get_equation();
	//for (int i = 0; i < equation.size(); i++) {
	//	cout << equation[i] << endl;
	//}

	get_infix();
	//for (int i = 0; i < infix.size(); i++) {
	//	cout << infix[i] << endl;
	//}
	cout << infix.size() << endl;

	ofstream fout;
	fout.open("24test1.txt");
	for (int i = 0; i < infix.size()/2; i++) {
		fout << infix[i] << endl;
	}
	fout.close();

	ofstream fout2;
	fout2.open("24test2.txt");
	for (int i = infix.size() / 2; i < infix.size(); i++) {
		fout2 << infix[i] << endl;
	}
	fout2.close();

	cout << "입력 완료" << endl;
}