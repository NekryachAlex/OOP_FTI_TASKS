#include "BFS.h"
#include <deque>
#include <unordered_set>

const Vertex& BFSalgorithm::start()
{
	return startingVertex;
}
void BFSalgorithm::end()
{
}
void BFSalgorithm::vertexVisiting(const Vertex& visitedVertex)
{
	allVertexes.push_back(visitedVertex);
}
void BFSalgorithm::edgeVisiting(const Edge& visitedEdge)
{
}
void BFSalgorithm::initAlgorithm()
{
	const Vertex& startingVertex = start();

	std::deque<Vertex> waitingVertex; 
	waitingVertex.push_back(startingVertex);
	std::unordered_set<Vertex, Vertex::VertexHashFunction> visitedVertexes;
	
	while (waitingVertex.size() != 0)
	{
		const Vertex consideringVertex = waitingVertex.front();
		waitingVertex.pop_front();
		vertexVisiting(consideringVertex);
		visitedVertexes.insert(consideringVertex);

		std::pair<Graph::iterator, Graph::iterator> neighbors = graph.getNeighbor(consideringVertex);
		if (neighbors.first == neighbors.second)
		{
			continue;
		}
		Graph::iterator neighbor = neighbors.first;
		do 
		{
			const Vertex& addingVertex = ((neighbor->second).getSecondVertex());
			if (visitedVertexes.count(addingVertex) != 0)
			{
				continue;
			}
			edgeVisiting(neighbor->second);
			
			waitingVertex.push_back(addingVertex);
			visitedVertexes.insert(addingVertex);
			neighbor++;
		} while (neighbor != neighbors.second);
	}

	end();
}

