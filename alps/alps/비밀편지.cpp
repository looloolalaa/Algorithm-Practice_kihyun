#include <iostream>
#include <string>
using namespace std;

struct Code {
	char ch;
	string str;
};

void init(Code* table) {
	table[0].ch = 'A';
	table[0].str = "000000";
	table[1].ch = 'B';
	table[1].str = "001111";
	table[2].ch = 'C';
	table[2].str = "010011";
	table[3].ch = 'D';
	table[3].str = "011100";
	table[4].ch = 'E';
	table[4].str = "100110";
	table[5].ch = 'F';
	table[5].str = "101001";
	table[6].ch = 'G';
	table[6].str = "110101";
	table[7].ch = 'H';
	table[7].str = "111010";
}

char change(Code* t, string s) {
	char ch = 'z';
	for (int i = 0; i < 8; i++) {
		int wrong_count = 0;
		for (int j = 0; j < 6; j++) {
			if (t[i].str[j] != s[j])
				wrong_count++;
		}
		if (wrong_count <= 1) {
			ch = t[i].ch;
			break;
		}
	}
	return ch;
}

int main() {

	Code table[8];
	init(table);

	int n;
	char now;
	string* secret;
	string answer;
	cin >> n;

	if (1 <= n && n < 10)
		secret = new string[n];
	for (int i = 0, j = 0; i < 6 * n; i++) {
		if (i % 6 == 0 && i > 0)
			j++;
		cin >> now;
		secret[j] += now;
	}



	int i;

	for (i = 0; i < n; i++) {
		now = change(table, secret[i]);
		if (now == 'z')  //틀릴때 
			break;
		else  //맞으면
			answer += now;
	}
	if (i == n)
		cout << answer;
	else
		cout << i + 1;
}