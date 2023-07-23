#include <iostream>
#include "reader.h"
#include <fstream>
#include <codecvt>
#include "Matrix.h"
#include "DFS.h"
#include "BFS.h"
#include "Dijkstras.h"
/*
* changed data file, added edge (3,19) to make the whole dataset bi directional. 
*/
int main() {
    system("chcp 1252 >nul");
    auto parsedList = parse_file("data.txt");
    //printAdjacencyLsit(parsedList);

    Matrix adjMatrix = Matrix(parsedList);
    DFS s = DFS(adjMatrix, 3);
    BFS a = BFS(adjMatrix, 0); 
    Dijkstras nackstaTillFörrådet = Dijkstras(23, 37, adjMatrix);
    Dijkstras L319TillD025 = Dijkstras(46, 47, adjMatrix);
    Dijkstras univesitetTillBiteLine = Dijkstras(19, 44, adjMatrix);

    return 0;


}