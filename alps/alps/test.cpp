#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Stack {

public:

	string* sArray; // 스택배열
	int size; // 스택배열 사이즈
	int top; // 스택 탑

	void makeStack(int s) {
		size = s;
		sArray = new string[size];
		top = 0;
	}

	void deleteStack() {
		delete[] sArray;
	}

	void Push(char data) {
		sArray[top++] = data;
	}

	void Pop() {
		sArray[--top].clear();
	}

	string Top() {
		return sArray[top - 1];
	}

	void show() {
		cout << "***************************" << endl;
		for (int i = 0; i < size; i++) {
			cout << sArray[i] << endl;
		}
		cout << "***************************" << endl;
	}
};

int main() {

	string input; // 입력 문자열 저장
	string change; // 바꾼 문자열 저장
	Stack s;
	regex reg("[a-zA-Z]");
	string result;
	string answer="";

	while (true) {
		result = "yes\n";
		getline(cin, input, '.');

		if (input.empty()) {
			break;
		}
		else {
			change = regex_replace(input, reg, "");
		}

		s.makeStack(change.length());
		for (int i = 0; i < s.size; i++) {
			char input = change.at(i);
			if (s.top == 0) { // 스택 비어있으면
				if (input == '(' || input == '[') {
					s.Push(input);
				}
				else if (input == ')' || input == ']') {
					result = "no\n";
					break;
				}
			}
			else { // 스택 비어있지 않으면
				if (input == '(' || input == '[') {
					s.Push(input);
				}
				else if (input == ')') {
					if (s.Top() == "(") {
						s.Pop();
					}
					else {
						result = "no\n";
						break;
					}
				}
				else if (input == ']') {
					if (s.Top() == "[") {
						s.Pop();
					}
					else {
						result = "no\n";
						break;
					}
				}
			}
		}

		s.deleteStack();
		answer += result;
		while (getchar() != '\n') {} // 입력 버퍼 초기화
	}
	cout << answer;

	return 0;
}