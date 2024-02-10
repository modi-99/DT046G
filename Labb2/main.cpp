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

/**
 * @brief this is a struct for results.
 * @param Id The first element.
 * @param meanValue The second element.
 * @return doesnt have any return value.
 */
struct Result {
    double id;
    double meanValue;
    double sum;
    double stdDev;
    double samples;

};

/**
 * @brief This function adds two integers.
 * @param measurements hold different time point for a sorting algorithms.
 * @return return a vector filled with desired results.
 */
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

/**
 * @brief This function creates a file a reads in data .
 * @param measurements hold different time point for a sorting algorithms.
 * @param filename is a filename.
 */
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


int main() {
    std::vector<std::vector<double>> timePoint;

    int samples = 5;
    int end = 20000;
    int N = 2000;
    int test = 0;


    while (N <= end) {
        std::vector<double> tempVec;
        tempVec.push_back(samples);
        tempVec.push_back(N);
        for (int i = 1; i <= samples; ++i) {
            DataGenerate data = DataGenerate(N);
            auto start = std::chrono::high_resolution_clock::now();
            //SelectionSort(data.monoIncreasedNumbers);
            //InsertionSort(data.randomGeneratedNumbers);
            QuickSortMOT(data.monoIncreasedNumbers);
            //QuickSort(data.randomGeneratedNumbers);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            tempVec.push_back(duration.count());
        }
        timePoint.push_back(tempVec);
        N += 2000;
    }

    std::vector<Result> resultVector = meanValueAndSum(timePoint);

    std::string filename = "data.txt";

    // function to write results to the file
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

