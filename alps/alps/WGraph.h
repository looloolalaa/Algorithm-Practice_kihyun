#include "AdjMatGraph.h"
#include "Heap.h"

#define INF 9999

class VertexSets {
	int parent[MAX_SIZE];
	int size;
public:
	VertexSets(int s) {
		size = s;
		for (int i = 0; i < size; i++)
			parent[i] = -1;
	}
	int find_root(int i) {
		if (!(0 <= i && i < size)) return -1;
		while (parent[i] != -1)
			i = parent[i];
		return i;
	}
	void union_set(int i, int j) {
		parent[find_root(i)] = find_root(j);
	}

};

class WGraph : public AdjMatGraph {
private:
	bool visited[MAX_SIZE];
	int min_dist[MAX_SIZE];
public:
	void setEdge(int i, int j, int val) {
		if (val > INF) adj[i][j] = INF;
		else adj[i][j] = val;
	}

	bool hasEdge(int i, int j) {
		return 0 < getEdge(i,j) && getEdge(i, j) < INF;
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


	void Kruskal() {
		MinHeap heap;
		VertexSets set(size);

		printf("Kruskal MST\n");

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j > i && hasEdge(i, j)) {
					heap.insert(getEdge(i, j), i, j);
				}
			}
		}
		
		while (!heap.isEmpty()) {
			HeapNode now = heap.remove();
			int i = now.getStart();
			int j = now.getEnd();
			if (set.find_root(i) != set.find_root(j)) {
				set.union_set(i, j);
				printf("간선 추가 %c-%c: %d\n", getVertex(i), getVertex(j), now.getKey());
			}
		}
	}

	int get_min_index() {
		int min_index = 0;
		int min = INF;
		for(int i=0;i<size;i++){
			if (!visited[i]) {
				if (min > min_dist[i]) {
					min = min_dist[i];
					min_index = i;
				}
			}
		}
		return min_index;
	}

	void Prim(int start) {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
			min_dist[i] = INF;
		}


		for (int i = 0; i < size; i++) {
			visited[start] = true;
			min_dist[start] = 0;
			printf("정점 추가 %c\n", getVertex(start));
			for (int j = 0; j < size; j++)
				if (hasEdge(start, j) && !visited[j] && getEdge(start, j) < min_dist[j])
					min_dist[j] = getEdge(start, j);

			int end = get_min_index();
			if (getEdge(start, end) != INF)
				printf("(%d)\n", getEdge(start, end));
			start = end;
		}
		
				
	}

};



int main() {
	WGraph g;
	g.load("graph.txt");
	//g.display();

	//g.Kruskal();
	g.Prim(0);
}