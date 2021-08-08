#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph {
public:
	void connected() {
		int color = 1;
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				printf("%d\n", color++);
				DFS(i);
				printf("\n");
			}
		}
	}
};
