//
// Created by modiQ on 2023-11-18.
//

#ifndef LABB2_QUICKSORT_H
#define LABB2_QUICKSORT_H


#include <vector>

class QuickSort {
private:
    int partition(std::vector<int> &vector, int start, int end);

    void sort(std::vector<int> &vector, int start, int end);

public:
    QuickSort(std::vector<int> &vector);

};


#endif //LABB2_QUICKSORT_H
