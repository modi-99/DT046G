//
// Created by modiQ on 2024-01-02.
//

#ifndef UNTITLED3_SEARCH_H
#define UNTITLED3_SEARCH_H


#include <vector>
#include <list>

struct HashNode{
    int size;
    std::list<int>* table;

    HashNode(int _size);

    void insertHash(int value);
    int hashFunction(int value);
    bool searchInHash(int value);


    int calculateDepth();
    void print();

};



struct Node {
    int data;
    Node *right;
    Node *left;

    Node()=default;
    Node(int value);


    Node* insert(int start, int end, std::vector<int> &primeNumbers);
    void inOrder(Node* root);
    bool search(Node *root, int value);
};


class Search {
public:
    int linearSearch(std::vector<int> &primeNumbers, int target);


    bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& key);


    int binarySearch(std::vector<int> &primeNumbers, int target);


};


#endif //UNTITLED3_SEARCH_H
