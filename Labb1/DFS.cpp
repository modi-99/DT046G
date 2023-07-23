#include "DFS.h"
#include <iostream>
#include <algorithm>


void DFS::findAndAddNeighbours(Matrix& adjMatrix, std::stack<int> &neighbourStack, std::vector<int> &vVector, int node)
{
	for (size_t i = 0; i < adjMatrix.adjMatrix.size(); i++)
	{// if statement checks if the coordinates given in the matrix is not 0 and if the iterator 
	//returned from find function is equals to last iterator in the visites vector then add node to neighbour stack
		if (adjMatrix.adjMatrix[node][i] != 0 && std::find(vVector.begin(), vVector.end(), i) == vVector.end()){
			neighbourStack.push(i);
			//std::cout << neighbourStack.top() << std::endl;

		}
	}
}


DFS::DFS(Matrix adjMatrix, int startingNode)
{
	visited.push_back(startingNode);
	findAndAddNeighbours(adjMatrix, neighbourStack, visited, startingNode);
	//std::cout << neighbourStack.size()<<std::endl;

	while (!neighbourStack.empty())
	{
		int currentNode = neighbourStack.top();
		neighbourStack.pop();
		//check if currentNode already visited or not
		if (std::find(visited.begin(), visited.end(), currentNode) == visited.end()) {
			visited.push_back(currentNode);
		}
		findAndAddNeighbours(adjMatrix, neighbourStack, visited, currentNode);
	}
	//std::cout << neighbourStack.size() << std::endl;
	/*std::sort(visited.begin(), visited.end());
	for (int value : visited) {
		std::cout << value<<"\n";
		
	}*/
	if (visited.size() == adjMatrix.adjMatrix.size()) {
		std::cout << "Connected\n";
	}
	else std::cout << "Not connected\n"<<adjMatrix.adjMatrix.size()<<" "<<visited.size();


}


