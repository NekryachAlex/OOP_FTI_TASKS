#include "Graph.h"


void Graph::AddEdge(const Edge& edge)
{
	edges.insert(std::make_pair<const Vertex&, const Edge&>(edge.getFirstVertex(), edge));
	return;
}

std::pair<Graph::iterator, Graph::iterator> Graph::getNeighbor(const Vertex& startingVertex) const
{
	return edges.equal_range(startingVertex);
}
