#include "ConnectedComponentGraph.h"

int main() {
	ConnectedComponentGraph g;
	g.load("graph.txt");
	g.connected();

	printf("spanning Tree Edges\n");
	g.resetVisited();
	g.spanningTreeByDFS(0);
}