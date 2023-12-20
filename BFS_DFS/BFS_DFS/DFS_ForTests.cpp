#include "DFS_ForTests.h"

std::pair<long long int, long long int> DFS_ForTests::getAmountOfVertexes()
{
	initAlgorithm();
	return std::make_pair(vertexCount, edgeCount);
}

void DFS_ForTests::vertexVisiting(Vertex&)
{
	vertexCount++;
}

void DFS_ForTests::edgeVisiting(Edge&)
{
	edgeCount++;
}
