#include "BFS_ForTests.h"

std::pair<long long int, long long int> BFS_ForTests::getAmountOfVertexes()
{
	initAlgorithm();
	return std::make_pair(vertexCount, edgeCount);
}

void BFS_ForTests::vertexVisiting(Vertex&)
{
	vertexCount++;
}

void BFS_ForTests::edgeVisiting(Edge&)
{
	edgeCount++;
}
