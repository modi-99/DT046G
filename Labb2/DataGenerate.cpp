//
// Created by modiQ on 2023-11-17.
//

#include <cstdlib>
#include "DataGenerate.h"


void DataGenerate::monoIncreasedGenerator(int N, std::vector<int> &vector) {
    for (int i = 0; i < N; ++i) {
        vector.push_back(i);

    }

}

void DataGenerate::monoDecreasedGenerator(int N, std::vector<int> &vector) {
    for (int i = N; i > 0 ; --i) {
        vector.push_back(i-1);
    }
}

void DataGenerate::randGenerator(int N, std::vector<int> &vector) {
    for (int i = 0; i < N; ++i) {
        int randomNumber=rand();
        vector.push_back(randomNumber);
    }
}

DataGenerate::DataGenerate(int N) : constantNumber(N, 5) {
monoIncreasedGenerator(N,monoIncreasedNumbers);
monoDecreasedGenerator(N,monoDecreasedNumbers);
randGenerator(N,randomGeneratedNumbers);

}


