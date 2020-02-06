#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int point=0;
	char box[51];
	bool TOF=true;
public:
	void init() {
		point = 0;
		TOF = true;
	}
	void add(char ch) {
		box[point++]=ch;
	}
	void pop() {
		if (point > 0)
			point--;
		else
			TOF = false;
	}
	bool isEmpty() {
		return point == 0;
	}
	bool get_isRight() {
		return TOF;
	}
};

int main() {
	Stack s;
	string answer="";
	string now;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> now;
		for (int j = 0;j< now.length(); j++) {
			if (now[j] == '(')
				s.add(now[j]);
			else if (now[j] == ')')
				s.pop();
		}
		if (s.isEmpty()&&s.get_isRight())
			answer += "YES\n";
		else
			answer += "NO\n";
		s.init();
	}
	cout << answer;
}