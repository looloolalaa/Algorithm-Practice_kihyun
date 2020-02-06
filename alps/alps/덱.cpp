#include <iostream>
#include <string>
using namespace std;
#define SIZE 10001

class Deq {
private:
	int front, back;
	int data[SIZE];
public:
	Deq() { front = 0; back = 0; }
	~Deq(){}
	bool isEmpty() { return front == back; }
	void push_front(int val) {
		data[front] = val;
		front = (front - 1 + SIZE) % SIZE;
	}
	void push_back(int val) {
		back = (back + 1) % SIZE;
		data[back] = val;
	}
	int pop_front() {
		if (isEmpty())
			return -1;
		else {
			front = (front + 1) % SIZE;
			return data[front];
		}
	}
	int pop_back() {
		if (isEmpty())
			return -1;
		else {
			int b = back;
			back = (back - 1 + SIZE) % SIZE;
			return data[b];
		}
	}
	int get_size() { return (back - front + SIZE) % SIZE; }
	int get_front() {
		if (isEmpty())
			return -1;
		else
			return data[(front + 1) % SIZE];
	}
	int get_back() { 
		if (isEmpty())
			return -1;
		else
			return data[back];
	}
};

int main() {
	Deq d;
	string cmd,answer="";
	int n,x;
	cin >> n;
	if (1 <= n && n <= 10000) {
		for (int i = 0; i < n; i++) {
			cin >> cmd;
			if (cmd == "push_front") {
				cin >> x;
				d.push_front(x);
			}
			if (cmd == "push_back") {
				cin >> x;
				d.push_back(x);
			}
			if (cmd == "pop_front") {
				answer += to_string(d.pop_front())+'\n';
			}
			if (cmd == "pop_back") {
				answer += to_string(d.pop_back()) + '\n';
			}
			if (cmd == "size") {
				answer += to_string(d.get_size()) + '\n';
			}
			if (cmd == "empty") {
				answer += to_string(d.isEmpty()) + '\n';
			}
			if (cmd == "front") {
				answer += to_string(d.get_front()) + '\n';
			}
			if (cmd == "back") {
				answer += to_string(d.get_back()) + '\n';
			}
		}
		cout << answer;
	}
}