//
// Created by modiQ on 2024-01-02.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include "Search.h"


int Search::binarySearch(std::vector<int> &primeNumbers, int target) {
    int left = 0;
    int right = primeNumbers.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (primeNumbers[mid] == target && target == mid) {
            return true;
        } else if (primeNumbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int Search::linearSearch(std::vector<int> &primeNumbers, int target) {
    for (int i = 0; i < primeNumbers.size(); ++i) {
        if (target == primeNumbers[i]) return i;

    }
    return -1;
}

bool Search::binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &key) {
    while (first <= last) {
        auto mid = first + std::distance(first, last) / 2;

        if (*mid == key) {
            return true;
        }

        if (*mid < key) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return false;
}


Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

Node *Node::insert(int start, int end, std::vector<int> &primeNumbers) {

    if (start <= end) {
        int mid = (start + end) / 2;

        Node *root = new Node(primeNumbers[mid]);

        root->right = insert(mid + 1, end, primeNumbers);
        root->left = insert(start, mid - 1, primeNumbers);
        return root;
    }
    return nullptr;
}

void Node::inOrder(Node *root) {
    if (!root) {
        return;
    }
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);

}

bool Node::search(Node *root, int value) {
    if (root == nullptr || root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}


HashNode::HashNode(int _size) : size(_size) {
    table = new std::list<int>[size];

}

int HashNode::hashFunction(int value) {
    return value % size;
}

void HashNode::insertHash(int value) {
    int index = hashFunction(value);
    table[index].push_back(value);
}

bool HashNode::searchInHash(int value) {

    int index = hashFunction(value);
    for (auto first = table[index].begin(); first != table[index].end(); first++) {
        if (*first == value) {
            //std::cout << "Found" << std::endl;
            return true;
        }
    }
    std::cout << "Not found" << std::endl;
    return false;

}

void HashNode::print() {
    for (int i = 0; i < size; i++) {
        std::cout << i;
        for (auto e: table[i]) {
            std::cout << " --> " << e;
        }
        std::cout << std::endl;
    }
}

int HashNode::calculateDepth() {
    int maxDepth = 0;
    for (int i = 0; i < size; ++i) {
        int currentDepth = table[i].size();
        maxDepth = std::max(maxDepth, currentDepth);
    }
    return maxDepth;
}


