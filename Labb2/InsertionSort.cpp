//
// Created by modiQ on 2023-11-17.
//

#include <vector>
#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int> &vector) {
    for (int i = 1; i < vector.size(); ++i) {
        int currentElement = vector[i];
        int nextElement = i - 1;
        while (nextElement >= 0 && vector[nextElement] > currentElement) {
            vector[nextElement + 1] = vector[nextElement];
            nextElement--;
        }
        vector[nextElement + 1] = currentElement;
    }
}
