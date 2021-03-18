#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 10000

class Stack {

private:
	int top;
	int data[MAX_SIZE];

public:
	Stack() { top = -1; }
	~Stack(){}
	
	void push(int x) {
		data[++top] = x;
	}

	int pop() {
		if (isEmpty())
			return -1;
		return data[top--];
	}

	int size() {
		return top + 1;
	}

	bool isEmpty() {
		return top < 0;
	}

	int peek() {
		if (isEmpty())
			return -1;
		return data[top];
	}

};

int main() {
	Stack s;
	string inst;
	string answer = "";

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inst;
		if (inst == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (inst == "pop") {
			answer += to_string(s.pop()) + "\n";
		}
		else if (inst == "size") {
			answer += to_string(s.size()) + "\n";
		}
		else if (inst == "empty") {
			if (s.isEmpty())
				answer += "1\n";
			else
				answer += "0\n";
		}
		else if (inst == "top") {
			answer += to_string(s.peek()) + "\n";
		}
		else {
			answer += "ERROR INSTRUCTION\n";
		}
	}

	cout << answer;

}