#pragma once
#include "API.h"
#include "Graph.h"
class BFSalgorithm : public Strategy
{
public:
	BFSalgorithm(Graph& _graph, Vertex& _startingVertex): graph(_graph), startingVertex(_startingVertex) {};

	void initAlgorithm() override;

protected:
	Vertex& start() override;
	void end() override;
	void vertexVisiting(Vertex&) override;
	void edgeVisiting(Edge&) override;
	Graph& graph;
	Vertex& startingVertex;
};