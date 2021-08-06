#include <iostream>
using namespace std;

#define MAX_SIZE 200

class Node {
private:
	int key;
	Node* link;
public:
	Node(int k, Node* l = NULL) : key(k), link(l) {}
	~Node() { delete link; }
	int getKey() { return key; }
	void setKey(int val) { key = val; }
	Node* getLink() { return link; }
	void setLink(Node* n) { link = n; }
	void display() { printf("%4d", key); }
};

class AdjListGraph {
private:
	int size;
	char vertex[MAX_SIZE];
	Node* adj[MAX_SIZE];
public:
	AdjListGraph(): size(0) {}
	~AdjListGraph() {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL) delete adj[i];
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_SIZE; }
	
	char getVertex(int i) { return vertex[i]; }
	void insertVertex(char ch){
		if (!isFull()) {
			vertex[size] = ch;
			adj[size++] = NULL;
		}
		else printf("Graph is Full!\n");
	}

	void insertEdge(int i, int j) {
		adj[i] = new Node(j, adj[i]);
		adj[j] = new Node(i, adj[j]);
	}

	void display() {
		printf("%d\n", size);
		for (int i = 0; i < size; i++) {
			printf("%c", vertex[i]);
			for (Node* p = adj[i]; p != NULL; p = p->getLink())
				printf("%4c", getVertex(p->getKey()));
			printf("\n");
		}
	}

};

int main() {
	AdjListGraph graph;
	for (int i = 0; i < 4; i++)
		graph.insertVertex('A' + i);
	graph.insertEdge(0, 1);
	graph.insertEdge(0, 3);
	graph.insertEdge(1, 2);
	graph.insertEdge(1, 3);
	graph.insertEdge(2, 3);

	graph.display();
}