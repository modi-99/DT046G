#include <iostream>
#include <algorithm>
#include "DataGenerate.h"
#include <chrono>
#include <numeric>
#include <valarray>
#include "QuickSortMOT.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include <fstream>


struct Result {
    double id;         // Assuming you want to print "i" from your loop
    double meanValue;
    double sum;
    double stdDev;
    double samples; // Assuming you want to print the last element of the row

};

std::vector<Result> meanValueAndSum(const std::vector<std::vector<double>> &measurements) {
    std::vector<Result> resultVector;

    for (const auto &row: measurements) {
        int size = row.size() - 2;
        double sum = std::accumulate(row.begin() + 2, row.end(), 0.0);
        double meanValue = sum / size; // Adjusted the size for mean calculation

        std::vector<double> dev_squared(size);
        for (size_t i = 2; i < size; ++i) {
            dev_squared[i] = std::pow(row[i] - meanValue, 2);
        }


        auto square_sum = std::accumulate(dev_squared.begin(), dev_squared.end(), 0.0);
        double stdDev = std::sqrt(square_sum * (1.0 / (size - 1)));


        resultVector.push_back({row[1], meanValue, sum, stdDev, row[0]});
    }
    return resultVector;
}

void writeResultsToFile(const std::vector<Result> &resultVector, const std::string &filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }

    // Write results to the file
    for (const auto &element: resultVector) {
        outputFile << "Type: " << "Quick Sort" << std::endl;
        outputFile << "Sorting: " << "Random Integers" << std::endl;
        outputFile << "ID: " << element.id << std::endl;
        outputFile << "Mean Value: " << element.meanValue << std::endl;
        outputFile << "Sum: " << element.sum << std::endl;
        outputFile << "Standard Deviation: " << element.stdDev << std::endl;
        outputFile << "Samples: " << element.samples << std::endl;
        outputFile << std::endl;
    }

    // Close the file
    outputFile.close();

    std::cout << "Results written to " << filename << std::endl;
}


int main() {
    std::vector<std::vector<double>> timePoint;

    int samples = 5;
    int end = 400000;
    int N = 200000;

    int test = 0;


    while (N <= end) {
        std::vector<double> tempVec;
        tempVec.push_back(samples);
        tempVec.push_back(N);
        for (int i = 1; i <= samples; ++i) {
            DataGenerate data = DataGenerate(N);
            auto start = std::chrono::high_resolution_clock::now();
            //SelectionSort(data.randomGeneratedNumbers);
            InsertionSort(data.constantNumber);
            //QuickSortMOT(data.randomGeneratedNumbers);
            //QuickSort(data.randomGeneratedNumbers);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            tempVec.push_back(duration.count());
        }
        timePoint.push_back(tempVec);
        N += 20000;
    }


    std::vector<Result> resultVector = meanValueAndSum(timePoint);

    std::string filename = "results.txt";

    // Call the function to write results to the file
    writeResultsToFile(resultVector, filename);

    for (auto element: resultVector) {
        std::cout << "ID: " << element.id << std::endl;
        std::cout << "Mean Value: " << element.meanValue << std::endl;
        std::cout << "Sum: " << element.sum << std::endl;
        std::cout << "Standard Deviation: " << element.stdDev << std::endl;
        std::cout << "Samples: " << element.samples << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

