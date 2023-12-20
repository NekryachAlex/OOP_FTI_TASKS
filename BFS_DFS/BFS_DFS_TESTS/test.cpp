#include "pch.h"
#include "../BFS_DFS/Graph.h"
#include "../BFS_DFS/BFS.h"
#include "../BFS_DFS/DFS.h"
#include "../BFS_DFS/BFS_ForTests.h"
#include "../BFS_DFS/DFS_ForTests.h"

TEST(Graph, getOneNeighbor) {
	Graph testGraph;
	Vertex testVertex1("1");
	Vertex testVertex2("2");
	Edge testEdge12(testVertex1, testVertex2);

	testGraph.AddEdge(testEdge12);

	std::pair<Graph::iterator, Graph::iterator> neighbors = testGraph.getNeighbor(testVertex1);
	EXPECT_EQ(testVertex2, neighbors.first->second.getSecondVertex());
}

TEST(Graph, getTwoNeighbors) {
	Graph testGraph;
	Vertex testVertex1("1");
	Vertex testVertex2("2");
	Vertex testVertex3("3");
	Edge testEdge12(testVertex1, testVertex2);
	Edge testEdge13(testVertex1, testVertex3);

	testGraph.AddEdge(testEdge12);
	testGraph.AddEdge(testEdge13);

	std::pair<Graph::iterator, Graph::iterator> neighbors = testGraph.getNeighbor(testVertex1);
	Graph::iterator neigbour = neighbors.first;
	EXPECT_EQ(testVertex2, neigbour->second.getSecondVertex());
	neigbour++;
	EXPECT_EQ(testVertex3, neigbour->second.getSecondVertex());
}

TEST(BFS, allVertexesAreChecked) {
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
  EXPECT_EQ(5, countBFS.first);
}

TEST(BFS, allEdgesAreChecked) {
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
	EXPECT_EQ(4, countBFS.second);
}

TEST(DFS, allVertexesAreChecked) {
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
	BFS_ForTests DFS(testGraph, testVertex1);
	std::pair<long long, long long> countBFS = DFS.getAmountOfVertexes();
	EXPECT_EQ(5, countBFS.first);
}

TEST(DFS, allEdgesAreChecked) {
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
	BFS_ForTests DFS(testGraph, testVertex1);
	std::pair<long long, long long> countBFS = DFS.getAmountOfVertexes();
	EXPECT_EQ(4, countBFS.second);
}

