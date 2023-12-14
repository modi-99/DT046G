//
// Created by modiQ on 2023-11-17.
//

#include "SelectionSort.h"
#include <vector>


SelectionSort::SelectionSort(std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        int minIndex = i;
        for (int currentElement = i + 1; currentElement < vector.size(); ++currentElement) {
            if (vector[currentElement] < vector[minIndex]) {
                minIndex = currentElement;
            }
        }
        std::swap(vector[i], vector[minIndex]);
    }
}
