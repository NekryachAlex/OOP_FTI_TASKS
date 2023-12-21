#include "DFS.h"
#include <stack>
#include <unordered_set>


const Vertex& DFSalgorithm::start()
{
	return startingVertex;
}

void DFSalgorithm::end()
{
}

void DFSalgorithm::vertexVisiting(const Vertex& visitedVertex)
{
	allVertexes.push_back(visitedVertex);
}
void DFSalgorithm::edgeVisiting(const Edge& visitedEdge)
{
}

void DFSalgorithm::initAlgorithm()
{
	const Vertex& startingVertex = start();

	std::stack<Vertex> waitingVertex;
	waitingVertex.push(startingVertex);
	std::unordered_set<Vertex, Vertex::VertexHashFunction> visitedVertexes;

	while (waitingVertex.size() != 0)
	{
		const Vertex consideringVertex = waitingVertex.top();
		waitingVertex.pop();
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

			waitingVertex.push(addingVertex);
			visitedVertexes.insert(addingVertex);
			neighbor++;
		} while (neighbor != neighbors.second);
	}

	end();
}

