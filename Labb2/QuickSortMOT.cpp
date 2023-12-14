//
// Created by modiQ on 2023-11-18.
//

#include <vector>
#include "QuickSortMOT.h"

int QuickSortMOT::choosePivot(std::vector<int> &vector, int start, int end) {
    int mid = start + (end - start) / 2;
    int a = vector[start];
    int b = vector[mid];
    int c = vector[end];

    // Return the index of the median of three
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return mid;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return start;
    else
        return end;
}

void QuickSortMOT::sort(std::vector<int> &vector, int start, int end) {
    if (start < end) {
        int pivotIndex = choosePivot(vector, start, end);
        std::swap(vector[pivotIndex], vector[end]);
        int pivot = vector[end];
        int boundary = start - 1;

        for (int currenElement = start; currenElement < end; ++currenElement) {
            if (vector[currenElement] <= pivot) {
                ++boundary;
                std::swap(vector[boundary], vector[currenElement]);
            }
        }

        std::swap(vector[boundary + 1], vector[end]);
        pivotIndex = boundary + 1;

        sort(vector, start, pivotIndex - 1);
        sort(vector, pivotIndex + 1, end);
    }

}

QuickSortMOT::QuickSortMOT(std::vector<int> &vector) {
    sort(vector, 0, vector.size() - 1);

}




