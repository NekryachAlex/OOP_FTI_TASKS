#include "Graph.h"


void Graph::AddEdge(Edge& edge)
{
	edges.insert(std::make_pair<const Vertex&, const Edge&>(edge.getFirstVertex(), edge));
	return;
}

std::pair<Graph::iterator, Graph::iterator> Graph::getNeighbor(const Vertex& startingVertex)
{
	return edges.equal_range(startingVertex);
}

Graph::iterator Graph::end()
{
	return edges.end();
}
