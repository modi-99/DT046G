//
// Created by modiQ on 2023-11-18.
//

#ifndef LABB2_QUICKSORTMOT_H
#define LABB2_QUICKSORTMOT_H


class QuickSortMOT {
private:
    int choosePivot(std::vector<int> &vector, int start, int end);

    void sort(std::vector<int> &vector, int start, int end);

public:
    QuickSortMOT(std::vector<int> &vector);
};


#endif //LABB2_QUICKSORTMOT_H
