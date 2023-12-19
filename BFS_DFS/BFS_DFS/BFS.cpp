#include "BFS.h"
#include <deque>
void BFSalgorithm::initAlgorithm()
{
	Vertex& startingVertex = start();

	std::deque<Vertex&> waitingVertex;
	waitingVertex.push_back(startingVertex);

	while (waitingVertex.size() != 0)
	{
		Vertex& consideringVertex = waitingVertex.front();
		waitingVertex.pop_front();
		vertexVisiting(consideringVertex);
		
		std::pair<Graph::iterator, Graph::iterator> neighbors = graph.getNeighbor(consideringVertex);
		Graph::iterator neighbor = neighbors.first;
		do 
		{
			edgeVisiting(neighbor->second);
			waitingVertex.push_back((neighbor->second).getSecondVertex());
		} while (neighbor != neighbors.second);
	}

	end();
}