#include <iostream>
#include <vector>
#include <chrono>
#include "Search.h"



void primeGenerator(int N, std::vector<bool> &primeVec) {
    primeVec.assign(N, true);
    primeVec[0] = false;
    primeVec[1] = false;

    int i = 2;
    while (i < N / 2) {
        int divisor = i * 2;
        while (divisor < N) {
            primeVec[divisor] = false; // Corrected line
            divisor += i;
        }
        i++;
        while (primeVec[i] == false) {
            i++;
        }
    }
}
void pushBackTrueIndices(std::vector<bool> &primeNumbers, std::vector<int> &trueIndices) {
    for (int i = 0; i < primeNumbers.size(); ++i) {
        if (primeNumbers[i] == true)
            trueIndices.push_back(i);
    }
}
int getRandomPrime(std::vector<int> &trueIndices) {

    return trueIndices[std::rand() % trueIndices.size()];

}

int main() {


    int N = 1'000;
    int samples = 20;
    std::vector<bool> primeNumbers;
    std::vector<int> trueIndices;
    primeGenerator(N, primeNumbers);
    pushBackTrueIndices(primeNumbers, trueIndices);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Search search;


    std::vector<std::vector<double>> timePoint;

    for (int i = 0; i < samples; ++i) {

        int target = getRandomPrime(trueIndices);
        auto start = std::chrono::high_resolution_clock::now();
        int returnValue = search.binarySearch(trueIndices, target);
        //int returnValue=search.linearSearch(trueIndices,target);
        auto end = std::chrono::high_resolution_clock::now();


        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds >(end - start);

        std::cout << "Duration time to search: " << duration << std::endl;
        std::cout << "Element at index "<<returnValue<<" has value: " << target << std::endl;
        std::cout << " " << std::endl;

    }

    std::cout<< trueIndices.size();

    return 0;
}

