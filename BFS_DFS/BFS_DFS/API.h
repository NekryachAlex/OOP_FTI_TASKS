#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include <memory>
#include <deque>

class Strategy
{
public:
	virtual void initAlgorithm() = 0;
	std::deque<Vertex> getAllVertexes() const; 

protected:
	std::deque<Vertex> allVertexes;

	virtual const Vertex& start() = 0;
	virtual void end() = 0;
	virtual void vertexVisiting(const Vertex&) = 0;
	virtual void edgeVisiting(const Edge&) = 0;
};

class API final {
private:
	std::shared_ptr<Strategy*> strategyType;

public:
	API(Strategy* strategy) : strategyType(std::make_shared<Strategy*>(strategy)) {}
	void set_strategy(Strategy*);
	void run();
	std::deque<Vertex> getAllVertexes() const;
};
//
//API;
//API.set_strategy(new BFS());