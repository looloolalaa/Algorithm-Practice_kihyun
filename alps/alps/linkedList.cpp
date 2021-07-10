#include <iostream>
using namespace std;

class Node {
protected:
	Node* link;
	int data;
public:
	Node(int val = 0): link(NULL), data(val){ }
	~Node() {  }
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
	void display() { printf("[%d]", data); }
	bool hasData(int val) { return data == val; }

	void insertNext(Node* p) { 
		if(p!=NULL){
			p->setLink(link);
			link = p;
		}
	}

	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->getLink();
		}
		return removed;
	}

};

class LinkedList {
private:
	Node org;
public:
	LinkedList(): org(0) {}
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink()) {
			if (n == NULL) break;
		}
		return n;
	}

	void insert(int pos, Node* p) {
		Node* prev = getEntry(pos - 1);
		if (prev == NULL) {
			printf("Index Error \n");
		}
		else {
			prev->insertNext(p);
		}
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	int size() {
		Node* n = getHead();
		int count = 0;
		while (n != NULL) {
			count++;
			n = n->getLink();
		}
		return count;
	}

	Node* find(int item){
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(item))
				return p;
		}
		return NULL;
	}

	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (n != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	void display() {
		printf("Ç×¸ñ ¼ö=%d ", size());
		for (Node* n = getHead(); n!=NULL; n = n->getLink()) {
			n->display();
		}
		cout << "\n";
	}
};

int main() {
	LinkedList list;
	list.display();
	list.insert(0, new Node(4));
	list.insert(0, new Node(5));
	list.insert(0, new Node(6));
	list.insert(2, new Node(100));
	list.display();

	list.remove(1);
	list.display();

	list.clear();
	list.display();
}