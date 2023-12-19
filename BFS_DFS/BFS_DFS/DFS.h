#pragma once
#include "API.h"
#include "Graph.h"
class DFSalgorithm final : public Strategy
{
public:
	DFSalgorithm(Graph& _graph, Vertex& _startingVertex): graph(_graph), startingVertex(_startingVertex) {};

	void initAlgorithm() override;

protected:
	Vertex& start() override;
	void end() override;
	void vertexVisiting(Vertex&) override;
	void edgeVisiting(Edge&) override;

private:
	Graph& graph;
	Vertex& startingVertex;
};