#include <iostream>
using namespace std;

#define MAX_SIZE 200

class AdjMatGraph {
protected:
	int size;
	char vertex[MAX_SIZE];
	int adj[MAX_SIZE][MAX_SIZE];

public:
	AdjMatGraph() { reset(); }

	void reset() {
		size = 0;
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				setEdge(i, j, 0);
	}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_SIZE; }

	char getVertex(int i) { return vertex[i]; }
	int getEdge(int u, int v) { return adj[u][v]; }
	void setEdge(int u, int v, int val) { adj[u][v] = val; }

	void insertVertex(char ch) {
		if (isFull()) return;
		vertex[size++] = ch;
	}

	void insertEdge(int u, int v) {
		if (isFull()) return;
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c", vertex[i]);
			for (int j = 0; j < size; j++) {
				fprintf(fp, "%4d", adj[i][j]);
			}
			fprintf(fp, "\n");
		}
	}

	void store(const char filename[]) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}

	void load(const char filename[]) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			reset();
			fscanf(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					fscanf(fp, "%d", &val);
					if (val != 0) setEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}

};

//int main() {
//	AdjMatGraph graph;
//	for(int i=0;i<4;i++)
//		graph.insertVertex('A'+i);
//	graph.insertEdge(0, 1);
//	graph.insertEdge(0, 3);
//	graph.insertEdge(1, 2);
//	graph.insertEdge(1, 3);
//	graph.insertEdge(2, 3);
//	
//	graph.store("graph.txt");
//	graph.load("graph.txt");
//	graph.display();
//}