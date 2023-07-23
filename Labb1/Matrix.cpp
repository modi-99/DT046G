#include "Matrix.h"
#include <iostream>

int Matrix::nodesAmount(adjacency_list_t& data)
{
	return data.first.size();
}

int Matrix::edgeSize(adjacency_list_t& data)
{
	return data.second.size();
}

edge Matrix::readEdge(adjacency_list_t data, int pos)
{
	return  data.second[pos];
}


Matrix::Matrix(adjacency_list_t& data)
{
	int size = nodesAmount(data);

	//skapar 2D-matris
	std::vector<double> vector(size, -1);
	std::vector<std::vector<double>> emptyMatrix(size, vector);

	adjMatrix = emptyMatrix;




	for (int i = 0; i < edgeSize(data); i++)
	{
		int node1 = readEdge(data, i).n1;
		int node2 = readEdge(data, i).n2;
		//std::cout << node1 <<" " << node2<<std::endl;

		adjMatrix[node1][node2] = readEdge(data, i).weight;
	}
	
	// To print the matrix
	/*for (const auto& row : adjMatrix) {
		for (const auto& element : row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}*/
}

