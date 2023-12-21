#pragma once
#include "API.h"
#include "Graph.h"
class BFSalgorithm : public Strategy
{
public:
	BFSalgorithm(const Graph& _graph, const Vertex& _startingVertex): graph(_graph), startingVertex(_startingVertex) {};

	void initAlgorithm() override;

protected:
	const Vertex& start() override;
	void end() override;
	void vertexVisiting(const Vertex&) override;
	void edgeVisiting(const Edge&) override;
    const Graph graph;
	const Vertex startingVertex;
};