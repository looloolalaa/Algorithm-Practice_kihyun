#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Stack {
private:
	int point = 0;
	char box[101];
	bool TOF = true;
public:
	void init() {
		point = 0;
		TOF = true;
	}
	void add(char ch) { box[point++] = ch; }
	void pop() { point--; }
	bool isEmpty() { return point == 0; }
	bool get_TOF() { return TOF; }
	char peek() { return box[point - 1]; }
	void set_wrong() { TOF = false; }
};

bool isMatch(char a, char b) {
	return (a == '('&&b == ')') || (a == '['&&b == ']');
}

int main() {
	Stack s;
	string answer = "";
	string now = "";
	char ch='-';
	
	while (1) {
		ch = '-';
		now = "";
		while (ch != '\n') {
			ch = getchar();
			now += ch;
			if (ch == '(' || ch == '[')
				s.add(ch);
			else if (ch == ')' || ch == ']') {
				if (s.isEmpty())
					s.set_wrong();
				else if (isMatch(s.peek(), ch))
					s.pop();
				else
					s.set_wrong();
			}
		}

		if (now == ".\n"||now.length()>100)
			break;

		if (s.isEmpty() && s.get_TOF())
			answer += "yes\n";
		else
			answer += "no\n";
		s.init();
	}
	cout << answer;
}