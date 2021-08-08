#include "SrchAMGraph.h"

int main() {
	SrchAMGraph g;
	g.load("graph.txt");
	cout << "bridge Count: " << g.findBridge();

}