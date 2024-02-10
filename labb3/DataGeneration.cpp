//
// Created by modiQ on 2024-01-06.
//

#include <cstdlib>
#include "DataGeneration.h"


bool DataGeneration::isPrime(int value) {

    if (value <= 1) {
        return false;
    }
    for (int i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;

}

void DataGeneration::primeNumbers(int numbersOfPrime, std::vector<int> &primeNumbers) {

    int current = 2;

    while (primeNumbers.size() < numbersOfPrime) {
        if (isPrime(current)) {
            primeNumbers.push_back(current);
        }
        ++current;
    }


}

int DataGeneration::getRandomPrime(std::vector<int> &primeNumbers) {
    return primeNumbers[std::rand() % primeNumbers.size()];
}


