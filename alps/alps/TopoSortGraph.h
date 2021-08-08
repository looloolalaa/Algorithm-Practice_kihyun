#include "AdjMatGraph.h"
#include <stack>

class TopoSortGraph : public AdjMatGraph {
	int inDeg[MAX_SIZE] = { 0, };
public:

	void resetInDeg() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (adj[j][i] != 0) inDeg[i]++;
			}
		}
	}

	void topoSort() {
		resetInDeg();
		stack<int> s;

		for (int i = 0; i < size; i++)
			if (inDeg[i] == 0) s.push(i);
		
		while (!s.empty()) {
			int now = s.top();
			s.pop();
			printf("%c  ", getVertex(now));
			for (int j = 0; j < size; j++)
				if (adj[now][j] != 0)
					if (--inDeg[j] == 0)
						s.push(j);
		}
	}

};