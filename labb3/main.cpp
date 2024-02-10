#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <valarray>
#include <fstream>
#include "Search.h"
#include "DataGeneration.h"

struct Data {
    double id;
    double meanValue;
    double stdDev;

};

void writeResultsToFile(const std::vector<Data> &resultVector, const std::string &filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }

    // Write results to the file
    for (const auto &element: resultVector) {
        //outputFile << "Type: " << "Quick Sort" << std::endl;
        //outputFile << "Sorting: " << "Random Integers" << std::endl;
        outputFile << "ID: " << element.id << std::endl;
        outputFile << "Mean Value: " << element.meanValue << std::endl;
        //outputFile << "Sum: " << element.sum << std::endl;
        outputFile << "Standard Deviation: " << element.stdDev << std::endl;
        //outputFile << "Samples: " << element.samples << std::endl;
        outputFile << std::endl;
    }

    // Close the file
    outputFile.close();

    std::cout << "Results written to " << filename << std::endl;
}

std::vector<Data> meanValueAndSum(const std::vector<std::vector<double>> &measurements) {
    std::vector<Data> resultVector;

    for (auto row: measurements) {
        int size = row.size() - 2;
        double sum = std::accumulate(row.begin() + 2, row.end(), 0.0);
        double meanValue = sum / size; // Adjusted the size for mean calculation

        std::vector<double> dev_squared(size);
        for (size_t i = 2; i < size; ++i) {
            dev_squared[i] = std::pow(row[i] - meanValue, 2);
        }


        auto square_sum = std::accumulate(dev_squared.begin(), dev_squared.end(), 0.0);
        double stdDev = std::sqrt(square_sum * (1.0 / (size - 1)));


        resultVector.push_back({row[0], meanValue, stdDev,});
    }
    return resultVector;
}


int main() {


    std::vector<int> primeNumbers;
    DataGeneration data;
    Search search;
    int N = 10'000;
    int END = 100'000;
    int samples = 1000;
    std::vector<std::vector<double>> timePoint;

    //std::cout<<table.calculateDepth();
    //table.print();

    while (N <= END) {
        data.primeNumbers(N, primeNumbers);


        std::vector<double> tempVec;
        tempVec.push_back(N);
        tempVec.push_back(samples);

        Node *rootPointer = nullptr;
        Node tree;
        rootPointer=tree.insert(0,N-1,primeNumbers);
        //tree.inOrder(rootPointer);

        HashNode table(primeNumbers[primeNumbers.size()-1]);
        for (int values:primeNumbers) {
            table.insertHash(values);
        }


        srand(time(NULL));

        int mid = N / 2;

        for (int i = 0; i < samples; ++i) {
            int target = data.getRandomPrime(primeNumbers);
            auto start = std::chrono::high_resolution_clock::now();
            //int returnValue = search.binary_search(primeNumbers.begin(), primeNumbers.end(), target);
            //int returnValue = search.binarySearch(primeNumbers, target);
            //int returnValue = search.linearSearch(primeNumbers, mid);
            bool isFound=table.searchInHash(target);
            //bool isFound=tree.search(rootPointer, target);
            auto end = std::chrono::high_resolution_clock::now();


            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            tempVec.push_back(duration.count());

            //std::cout << "Duration time to search: " << duration << std::endl;
            //std::cout << "Element at index " << returnValue << " has value: " << target << std::endl;
            std::cout <<"Is " <<target << " found in the tree? "<<isFound<< std::endl;
            //std::cout << " " << std::endl;
        }
        timePoint.push_back(tempVec);
        N = N + 10'000;


    }

    auto mean = meanValueAndSum(timePoint);
    std::string filename = "data.txt";

    // function to write results to the file
    writeResultsToFile(mean, filename);


    for (auto value: mean) {
        std::cout << value.id << " " << value.meanValue << " " << value.stdDev << std::endl;

    }


    return 0;
}


