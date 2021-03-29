#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int id;
	string name;
	string dept;
public:
	Student(int i = 0, string n = "", string d = "") { set(i, n, d); }
	~Student() {}
	void set(int i, string n, string d) {
		id = i;
		name = n;
		dept = d;
	}
	void display() {
		printf(" 학번: %-15d 이름: %-10s 학과: %-10s\n", id, name.c_str(), dept.c_str());
	}
};

class Node : public Student {
private:
	Node* link;
public:
	Node(int i = 0, string n = "", string d = "")
		:Student(i, n, d) { link = NULL; }
	~Node(){}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};

class LinkedStack {
	Node* top;
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (!isEmpty()) delete pop(); }
	bool isEmpty() { return top == NULL; }
	void push(Node* p) {
		if (isEmpty())
			top = p;
		else {
			p->setLink(top);
			top = p;
		}
	}
	Node* pop() {
		if (isEmpty())
			return NULL;
		else {
			Node* p = top;
			top = p->getLink();
			return p;
		}
	}
	Node* peek() { return top; }
	void display() {
		if (isEmpty())
			cout << "is Empty!\n";
		else {
			Node* p = top;
			while (p != NULL) {
				p->display();
				p = p->getLink();
			}
			/*for (Node* p = top; p != NULL; p = p->getLink())
				p->display();*/
		}
	}
};

int main() {
	LinkedStack stack;
	stack.push(new Node(201611218, "이기현", "컴퓨터공학부"));
	stack.push(new Node(201611218, "김율", "예디대"));
	stack.push(new Node(201611218, "김승환", "컴퓨터공학부"));
	stack.display();


	Node* node = stack.pop();
	cout << "pop: ";
	node->display();

	node = stack.peek();
	cout << "peek: ";
	node->display();

	stack.display();
	delete node;
}