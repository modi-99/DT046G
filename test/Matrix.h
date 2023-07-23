#pragma once
#include "reader.h"
class Matrix
{
private:
	int nodesAmount(adjacency_list_t& data);
	int edgeSize(adjacency_list_t& data);
	edge readEdge(adjacency_list_t data, int pos);
	
public:

	Matrix(adjacency_list_t &data);
	std::vector <std::vector<double>> adjMatrix;

};

