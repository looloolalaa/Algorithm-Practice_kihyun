#include <iostream>
#include <queue>
using namespace std;

class Que {
private:
	int front, rear;
	int arr[1001];
public:
	Que() {
		front = 0;
		rear = 0;
	}
	~Que() {};
	void push(int x) { arr[(rear++) % 1001] = x; }
	int pop() { return arr[(front++) % 1001]; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % 1001 == front; }
	void show() {
		for (int i = front; i % 1001 < rear; i++)
			cout << arr[i % 1001] << endl;
	}
};

int main() {
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		q.push(i + 1);

	cout << "<";
	while (q.size()) {

		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() <<", ";
		q.pop();
	}
	cout << "\b\b>" << endl;

}