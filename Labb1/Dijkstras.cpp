#include "Dijkstras.h"
#include<iterator>
#include<iostream>

typedef std::pair<int, double> prioQueueNeighbours;

void Neighbours(Matrix& adjMatrix, std::priority_queue<prioQueueNeighbours, std::vector<prioQueueNeighbours>, std::greater<prioQueueNeighbours>>& neighbours, std::vector<int>& treatedNodes, std::vector<double>& treatedNodeWeights, std::vector<int>& path)
{
	int nodeNumber = neighbours.top().first;
	double nodeWeight = neighbours.top().second;

	neighbours.pop();

	for (size_t i = 0; i < adjMatrix.adjMatrix.size(); i++)
	{
		if (adjMatrix.adjMatrix[nodeNumber][i] != -1 &&  
			std::find(treatedNodes.begin(), treatedNodes.end(), i) == treatedNodes.end()) {

			double weight = adjMatrix.adjMatrix[nodeNumber][i];
			double totalWeight = weight + nodeWeight;

			neighbours.push(std::make_pair(i, totalWeight));
			path.at(i)=nodeNumber;
			
		}
	}

	if (std::find(treatedNodes.begin(), treatedNodes.end(), nodeNumber) == treatedNodes.end()) {
		treatedNodes.push_back(nodeNumber);
		treatedNodeWeights.push_back(nodeWeight);
	}
}

Dijkstras::Dijkstras(int fromNode, int toNode, Matrix adjMatrix){

	std::priority_queue<prioQueueNeighbours, std::vector<prioQueueNeighbours>, std::greater<prioQueueNeighbours>> neighbours;

	neighbours.push(std::make_pair(fromNode, 0));
	std::vector<int> path(adjMatrix.adjMatrix.size(), -1);
	path.at(fromNode) = fromNode;
	//visited.push_back(fromNode);

	Neighbours(adjMatrix, neighbours, treatedNodes, treateddNodesWeight,path);

	while (!neighbours.empty())
	{
		Neighbours(adjMatrix, neighbours, treatedNodes, treateddNodesWeight, path);

	}
	std::vector<int>::iterator itr = std::find(treatedNodes.begin(), treatedNodes.end(), toNode);
	int index = std::distance(treatedNodes.begin(), itr);
	double totalDistance = treateddNodesWeight.at(index);
	
	
	int start = toNode;
	std::cout << start << " ";
	while (start != fromNode) {
		std::cout << path.at(start) << " ";
		start = path.at(start);
	}
	std::cout << totalDistance << std::endl;
	}







