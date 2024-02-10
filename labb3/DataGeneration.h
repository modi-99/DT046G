//
// Created by modiQ on 2024-01-06.
//

#ifndef UNTITLED3_DATAGENERATION_H
#define UNTITLED3_DATAGENERATION_H


#include <vector>

class DataGeneration {
private:
    bool isPrime(int value);
public:
    void primeNumbers(int numbersOfPrime, std::vector<int>& primeNumbers);
    int getRandomPrime(std::vector<int> &primeNumbers);


};


#endif //UNTITLED3_DATAGENERATION_H
