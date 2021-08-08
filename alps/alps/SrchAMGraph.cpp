#include "SrchAMGraph.h"

int main() {
	SrchAMGraph g;
	g.load("graph.txt");

	printf("DFS == ");
	g.DFS(0);
	//g.DFS(5);
	printf("\n");

	g.resetVisited();
	printf("BFS == ");
	g.BFS(0);
	//g.BFS(5);
}