#include "API.h"

std::deque<Vertex> Strategy::getAllVertexes() const
{
	return std::deque<Vertex>();
}


void API::set_strategy(Strategy* strategy)
{
	strategyType = std::make_shared<Strategy*>(strategy);
}

void API::run() {
	(*strategyType)->initAlgorithm();
}

std::deque<Vertex> API::getAllVertexes() const
{
	return (*strategyType)->getAllVertexes();
}
