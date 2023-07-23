#include "BFS.h"
#include <iostream>

void BFS::findAndAddNeighbour(Matrix adjMatrix, std::deque<int>& nQueue, std::vector<int>& vVector, int node)
{
	for (size_t i = 0; i < adjMatrix.adjMatrix.size(); i++) {
		if (adjMatrix.adjMatrix[node][i] != 0 
			&& std::find(vVector.begin(), vVector.end(), i) == vVector.end()) {
			nQueue.push_back(i);
		}
	}
}


BFS::BFS(Matrix adjMatrix, int startingNode)
{
	visited.push_back(startingNode);
	findAndAddNeighbour(adjMatrix, neighbourQueue, visited, startingNode);

	while (!neighbourQueue.empty()) 
	{
		int currentNode = neighbourQueue.front();
		neighbourQueue.pop_front();
		if (std::find(visited.begin(), visited.end(), currentNode) == visited.end()) {
			visited.push_back(currentNode);
		}
		findAndAddNeighbour(adjMatrix, neighbourQueue, visited, currentNode);
	}
	if (visited.size() == adjMatrix.adjMatrix.size()) {
		std::cout << "Connected\n";
	}
	else std::cout << "Not connected\n" << adjMatrix.adjMatrix.size() << " " << visited.size();
	
}


