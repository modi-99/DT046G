#pragma once
#include <vector>
#include"reader.h"
#include "Matrix.h"
#include<queue>
class Dijkstras
{
private:
	std::vector<int> treatedNodes;
	std::vector<double> treateddNodesWeight;
public:

	Dijkstras(int fromNode, int toNode, Matrix adjMatrix);

	

};

