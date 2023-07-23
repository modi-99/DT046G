#pragma once
#include<vector>
#include <deque>
#include "Matrix.h"
class BFS
{
private:
	std::deque<int> neighbourQueue;
	std::vector<int> visited;
public:

	
	void findAndAddNeighbour(Matrix adjMatrix, std::deque<int>& nQueue, std::vector<int>& vVector, int node);
	BFS(Matrix adjMatrix, int startingNode);
};

