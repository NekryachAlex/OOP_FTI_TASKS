#pragma once
#include "API.h"
#include "Graph.h"
class BFSalgorithm final : public Strategy
{
public:
	BFSalgorithm(Graph& _graph): graph(_graph) {};

	void initAlgorithm() override;

protected:
	Vertex& start() override;
	void end() override;
	void vertexVisiting(Vertex&) override;
	void edgeVisiting(Edge&) override;

private:
	Graph& graph;
};