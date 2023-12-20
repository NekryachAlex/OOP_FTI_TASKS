#include "BFS.h"
#include <deque>
#include <unordered_set>

Vertex& BFSalgorithm::start()
{
	return startingVertex;
}
void BFSalgorithm::end()
{
}
void BFSalgorithm::vertexVisiting(Vertex&)
{
}
void BFSalgorithm::edgeVisiting(Edge&)
{
}
void BFSalgorithm::initAlgorithm()
{
	Vertex& startingVertex = start();

	std::deque<Vertex*> waitingVertex; //problem with reference storage (but pointers can be storaged)
	waitingVertex.push_back(&startingVertex);
	std::unordered_set<Vertex, Vertex::VertexHashFunction> visitedVertexes; //trouble with storage of reference to Vertex (insert and count will be broken).
	//I think  problem is usage not constant variables (not const Vertex), but i couln't solve this problem.
	while (waitingVertex.size() != 0)
	{
		Vertex* consideringVertex = waitingVertex.front();
		waitingVertex.pop_front();
		vertexVisiting(*consideringVertex);
		visitedVertexes.insert(*consideringVertex);

		std::pair<Graph::iterator, Graph::iterator> neighbors = graph.getNeighbor(*consideringVertex);
		if (neighbors.first == neighbors.second)
		{
			continue;
		}
		Graph::iterator neighbor = neighbors.first;
		do 
		{
			Vertex* addingVertex = &((neighbor->second).getSecondVertex());
			if (visitedVertexes.count(*addingVertex) != 0) //c++20 contains function exists
			{
				continue;
			}
			edgeVisiting(neighbor->second);
			
			waitingVertex.push_back(addingVertex);
			visitedVertexes.insert(*addingVertex);
			neighbor++;
		} while (neighbor != neighbors.second);
	}

	end();
}

