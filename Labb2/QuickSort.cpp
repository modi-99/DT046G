//
// Created by modiQ on 2023-11-18.
//

#include "QuickSort.h"

int QuickSort::partition(std::vector<int> &vector, int start, int end) {
    int pivot = vector[end];
    int boundary = start - 1;
    for (int currentElement = start; currentElement < end; ++currentElement) {
        if (vector[currentElement] <= pivot) {
            boundary++;
            std::swap(vector[currentElement], vector[boundary]);
        }
    }
    std::swap(vector[boundary + 1], vector[end]); // Move the pivot to its final position
    return boundary + 1; // Returns the pivot position after the swap
}


void QuickSort::sort(std::vector<int> &vector, int start, int end) {
    if (start >= end) return;
    int pivotPos = partition(vector, start, end);
    sort(vector, start, pivotPos - 1); //sort left side of the pivot
    sort(vector, pivotPos + 1, end); //sort left side of the pivot
}


QuickSort::QuickSort(std::vector<int> &vector) {
    sort(vector, 0, vector.size() - 1);


}

