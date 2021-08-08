#include "TopoSortGraph.h"
#include "SrchAMGraph.h"

int main() {
	TopoSortGraph g;
	g.load("graph3.txt");
	g.topoSort();

}