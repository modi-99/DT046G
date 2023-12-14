//
// Created by modiQ on 2023-11-17.
//

#ifndef LABB2_DATAGENERATE_H
#define LABB2_DATAGENERATE_H

#include <vector>


class DataGenerate {
private:


    void monoIncreasedGenerator(int N, std::vector<int>& vector);
    void monoDecreasedGenerator(int N, std::vector<int>& vector);
    void randGenerator (int N, std::vector<int>& vector);
public:
    explicit DataGenerate(int N);
    std::vector<int> randomGeneratedNumbers;
    std::vector<int> monoIncreasedNumbers;
    std::vector<int> monoDecreasedNumbers;
    std::vector<int> constantNumber;




};


#endif //LABB2_DATAGENERATE_H
