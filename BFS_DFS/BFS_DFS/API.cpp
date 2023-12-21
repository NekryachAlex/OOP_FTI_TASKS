#include "API.h"

std::deque<const Vertex> Strategy::getAllVertexes() const
{
	return std::deque<const Vertex>();
}


void API::set_strategy(Strategy* strategy)
{
	strategyType = std::make_shared<Strategy>(strategy);
}

void API::run() {
	strategyType->initAlgorithm();
}

std::deque<const Vertex> API::getAllVertexes() const
{
	return strategyType->getAllVertexes();
}
