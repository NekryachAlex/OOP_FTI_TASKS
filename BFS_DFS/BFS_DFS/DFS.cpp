#include "DFS.h"
#include <stack>
#include <unordered_set>


Vertex& DFSalgorithm::start()
{
	return startingVertex;
}
void DFSalgorithm::end()
{
}
void DFSalgorithm::vertexVisiting(Vertex&)
{
}
void DFSalgorithm::edgeVisiting(Edge&)
{
}
void DFSalgorithm::initAlgorithm()
{
	Vertex& startingVertex = start();
	
	std::stack<Vertex*> waitingVertex;
	waitingVertex.push(&startingVertex);
	std::unordered_set<Vertex, Vertex::VertexHashFunction> visitedVertexes;

	while (waitingVertex.size() != 0)
	{
		Vertex* consideringVertex = waitingVertex.top();
		waitingVertex.pop();
		vertexVisiting(*consideringVertex);
		visitedVertexes.insert(*consideringVertex);

		std::pair<Graph::iterator, Graph::iterator> neighbors = graph.getNeighbor(*consideringVertex);
		Graph::iterator neighbor = neighbors.first;
		do
		{

			Vertex& addingVertex = (neighbor->second).getSecondVertex();
			if (visitedVertexes.count(addingVertex) != 0) //c++20 contains function exists
			{
				continue;
			}
			edgeVisiting(neighbor->second);

			waitingVertex.push(&(neighbor->second).getSecondVertex());
			visitedVertexes.insert(addingVertex);
			neighbor++;
		} while (neighbor != neighbors.second);
	}

	end();
}