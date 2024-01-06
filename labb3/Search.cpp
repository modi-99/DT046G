//
// Created by modiQ on 2024-01-02.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Search.h"




int Search::binarySearch(std::vector<int> &primeNumbers, int target) {
    int left = 0;
    int right = primeNumbers.size();

    while (left <= right){
        int mid = left + (right - left) / 2;

        if(primeNumbers[mid] == target){
            return mid;
        }
        else if (primeNumbers[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return - 1;
}

int Search::linearSearch(std::vector<int> &primeNumbers, int target) {
    for (int i = 0; i < primeNumbers.size(); ++i) {
        if (target== primeNumbers[i]) return i;

    }
    return -1;
}


