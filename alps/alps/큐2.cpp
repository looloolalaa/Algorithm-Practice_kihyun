#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX_SIZE 1000


class MyQueue {

private:
	int front;
	int rear;
	int data[MAX_SIZE];

public:
	MyQueue() {
		front = 0;
		rear = -1;
	}
	~MyQueue() {}
	void push(int x) {
		if (++rear == MAX_SIZE)
			rear = 0;
		data[rear] = x;
	}
	int pop() { 
		if (isEmpty())
			return -1;

		int value = data[front];
		if (++front == MAX_SIZE)
			front = 0;
		return value;
	}
	int size() { 
		if (isEmpty())
			return 0;
		int distance = rear - front;
		if (distance < 0)
			return MAX_SIZE + distance + 1;
		return distance + 1;
	}
	bool isEmpty() { return front == (rear + 1) % MAX_SIZE; }
	int get_front() { 
		if (isEmpty())
			return -1;
		return data[front]; 
	}
	int get_rear() { 
		if (isEmpty())
			return -1; 
		return data[rear];
	}
	bool isFull() { return rear + 2 == front; }

};

class CircularQueue {
private:
	int front;
	int rear;
	int data[MAX_SIZE];
	int size=0;
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_SIZE == front; }
	void push(int val) {
		if (isFull()) {
			//cout << "Full\n";
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = val;
			size++;
		}
	}
	int pop() {
		if (isEmpty())
			return -1;
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
			size--;
		}
	}
	int get_front() {
		if (isEmpty())
			return -1;
		return data[(front + 1) % MAX_SIZE];
	}
	int get_rear() {
		if (isEmpty())
			return -1;
		return data[rear];
	}
	int get_size() {
		return size;

		if (isEmpty())
			return 0;
		int distance = rear - front;
		if (distance < 0)
			return MAX_SIZE + distance;
		return distance;
	}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	queue<int> q;
	string inst;
	string answer = "";

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inst;
		if (inst == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (inst == "pop") {
			if (q.empty())
				answer += "-1\n";
			else {
				answer += to_string(q.front()) + "\n";
				q.pop();
			}
		}
		else if (inst == "size") {
			answer += to_string(q.size()) + "\n";
		}
		else if (inst == "empty") {
			if (q.empty())
				answer += "1\n";
			else
				answer += "0\n";
		}
		else if (inst == "front") {
			if (q.empty())
				answer += "-1\n";
			else {
				answer += to_string(q.front()) + "\n";
			}
		}
		else if (inst == "back") {
			if (q.empty())
				answer += "-1\n";
			else {
				answer += to_string(q.back()) + "\n";
			}
		}
		else {
			answer += "ERROR INSTRUCTION\n";
		}
	}

	cout << answer;
}