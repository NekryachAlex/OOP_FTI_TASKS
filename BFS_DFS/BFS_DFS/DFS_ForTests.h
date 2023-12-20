#pragma once
#include "DFS.h"
class DFS_ForTests : public DFSalgorithm
{
public:
	DFS_ForTests() = default;
	DFS_ForTests(Graph& _graph, Vertex& _startingVertex) : DFSalgorithm(_graph, _startingVertex), graph(_graph), startingVertex(_startingVertex) {};
	std::pair<long long int, long long int> getAmountOfVertexes();
protected:

	void vertexVisiting(Vertex&) override;
	void edgeVisiting(Edge&) override;
	Graph& graph;
	Vertex& startingVertex;
	long long int vertexCount = 0;
	long long int edgeCount = 0;
};