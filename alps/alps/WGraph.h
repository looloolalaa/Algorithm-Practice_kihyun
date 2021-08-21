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


	void Dijkstra(int start) {
		int temp = start;
		for (int i = 0; i < size; i++) {
			visited[i] = false;
			min_dist[i] = INF;
		}

		min_dist[start] = 0;
		for (int i = 0; i < size; i++) {
			visited[start] = true;
			for (int j = 0; j < size; j++) {
				if (hasEdge(start, j) && !visited[j]) {
					int old_dist = min_dist[j];
					int new_dist = min_dist[start] + getEdge(start, j);
					if (old_dist > new_dist)
						min_dist[j] = new_dist;
				}
			}
			start = get_min_index();
		}

		printf("%c 에서 부터 각 노드까지의 최단거리\n", getVertex(temp));
		for (int i = 0; i < size; i++)
			printf("%c: %d  ", getVertex(i), min_dist[i]);
		printf("\n");
	}


	void show_path(int go[][MAX_SIZE], int i, int j) {
		int start = i, end = j;
		int point = start;
		while (point != end) {
			printf("%c->", getVertex(point));
			point = go[point][end];
		}
		printf("%c", getVertex(end));
	}

	void Floyd() {


		int D[MAX_SIZE][MAX_SIZE];  //최단 거리
		int go[MAX_SIZE][MAX_SIZE];  //최단 경로

		//초기화
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				D[i][j] = adj[i][j];
				go[i][j] = -1;
				if (hasEdge(i, j))
					go[i][j] = j;
			}
		}

		//Floyd
		for (int k = 0; k < size; k++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					int old_dist = D[i][j];
					int new_dist = D[i][k] + D[k][j];
					if (new_dist < old_dist) {
						D[i][j] = new_dist;
						go[i][j] = go[i][k];
					}
				}
			}
		}


		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%c => %c 의 최단 경로와 비용: ", getVertex(i), getVertex(j));
				show_path(go, i, j);
				printf(" (%d)\n", D[i][j]);
			}
			printf("\n");
		}


	}

};



int main() {
	WGraph g;
	g.load("wgraph_shortest.txt");
	//g.display();

	//g.Kruskal();
	//g.Prim(0);

	//g.Dijkstra(0);
	g.Floyd();
}