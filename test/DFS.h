#pragma once
#include "reader.h"
#include <stack>
#include "Matrix.h"
class DFS {
private: 
	std::stack<int>neighbourStack;
	std::vector<int> visited;

public:
	DFS(Matrix adjMatrix, int startingNode);
	void findAndAddNeighbours(Matrix &adjMatrix, std::stack<int> &nStack,std::vector<int> &vVector, int node);
	//void printNeihgbourStack(std::stack<int>neighbourStack);

	
	


};

