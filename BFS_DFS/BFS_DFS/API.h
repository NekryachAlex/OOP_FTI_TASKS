#pragma once
#include "Vertex.h"
#include "Edge.h"
class Strategy
{
public:
	virtual void initAlgorithm() = 0;
protected:
	virtual Vertex& start() = 0;
	virtual void end() = 0;
	virtual void vertexVisiting(Vertex&) = 0;
	virtual void edgeVisiting(Edge&) = 0;
};