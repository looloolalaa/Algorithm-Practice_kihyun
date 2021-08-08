#include "AdjMatGraph.h"
#include <queue>

class SrchAMGraph : public AdjMatGraph {
protected:
	bool visited[MAX_SIZE];
public:
	SrchAMGraph() { resetVisited(); }
	void resetVisited() {
		for (int i = 0; i < MAX_SIZE; i++)
			visited[i] = false;
	}

	void DFS(int i) {
		//printf("%c ", getVertex(i));
		visited[i] = true;

		for (int j = 0; j < size; j++) {
			if (adj[i][j] != 0 && !visited[j]) 
				DFS(j);
		}
	}

	void spanningTreeByDFS(int i) {
		visited[i] = true;

		for (int j = 0; j < size; j++) {
			if (adj[i][j] != 0 && !visited[j]) {
				printf("%c-%c\n", getVertex(i), getVertex(j));
				spanningTreeByDFS(j);
			}
		}

	}

	void BFS(int i) {
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			printf("%c ", getVertex(now));
			visited[now] = true;

			for (int j = 0; j < size; j++) {
				if (adj[now][j] != 0 && !visited[j]) {
					q.push(j);
					visited[j] = true;
				}
			}
			
		}
	}

	int componentCount() {
		resetVisited();
		int color = 0;
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				color++;
				DFS(i);
			}
		}
		return color;
	}

	int findBridge() {
		int bridge = 0;
		int before = componentCount();
		int after, temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (adj[i][j] != 0) {
					temp = adj[i][j];
					adj[i][j] = 0;
					adj[j][i] = 0;
					after = componentCount();
					if (before < after) {
						bridge++;
						if (i < j)
							printf("bridge %c-%c\n", getVertex(i), getVertex(j));
					}
					adj[i][j] = temp;
					adj[j][i] = temp;
				}
			}
		}

		return bridge/2;
	}
};