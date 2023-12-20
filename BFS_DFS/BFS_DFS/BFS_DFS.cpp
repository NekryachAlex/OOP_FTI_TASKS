#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "BFS_ForTests.h"
#include "DFS_ForTests.h"
int main()
{
	Graph testGraph;
	Vertex testVertex1("1");
	Vertex testVertex2("2");
	Vertex testVertex3("3");
	Vertex testVertex4("4");
	Vertex testVertex5("5");
	Edge testEdge12(testVertex1, testVertex2);
	Edge testEdge13(testVertex1, testVertex3);
	Edge testEdge25(testVertex2, testVertex5);
	Edge testEdge34(testVertex3, testVertex4);

	testGraph.AddEdge(testEdge12);
	testGraph.AddEdge(testEdge13);
	testGraph.AddEdge(testEdge25);
	testGraph.AddEdge(testEdge34);

	BFS_ForTests BFS(testGraph, testVertex1);
	std::pair<long long, long long> countBFS = BFS.getAmountOfVertexes();
	DFS_ForTests DFS(testGraph, testVertex1);
	std::pair<long long, long long> countDFS = DFS.getAmountOfVertexes();

	return 0;
}



