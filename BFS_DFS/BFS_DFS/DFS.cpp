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

	std::stack<Vertex*> waitingVertex; //problem with reference storage (but pointers can be storaged)
	waitingVertex.push(&startingVertex);
	std::unordered_set<Vertex, Vertex::VertexHashFunction> visitedVertexes; //trouble with storage of reference to Vertex (insert and count will be broken).
	//I think  problem is usage not constant variables (not const Vertex), but i couln't solve this problem.
	while (waitingVertex.size() != 0)
	{
		Vertex* consideringVertex = waitingVertex.top();
		waitingVertex.pop();
		vertexVisiting(*consideringVertex);
		visitedVertexes.insert(*consideringVertex);

		std::pair<Graph::iterator, Graph::iterator> neighbors = graph.getNeighbor(*consideringVertex);
		if (neighbors.first == graph.end())
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

			waitingVertex.push(addingVertex);
			visitedVertexes.insert(*addingVertex);
			neighbor++;
		} while (neighbor != neighbors.second);
	}

	end();
}