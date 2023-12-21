#pragma once
#include "API.h"
#include "Graph.h"
class DFSalgorithm final : public Strategy
{
public:
	DFSalgorithm(const Graph& _graph, const Vertex& _startingVertex) : graph(_graph), startingVertex(_startingVertex) {};

	void initAlgorithm() override;

protected:
	const Vertex& start() override;
	void end() override;
	void vertexVisiting(const Vertex&);
	void edgeVisiting(const Edge&);

	const Graph graph;
	const Vertex startingVertex;
};