#ifndef STATISTICALCALCULATION_H
#define STATISTICALCALCULATION_H

#include <iostream>

template <typename T>
class StatisticalCalculation {
private:
    T* data;    // Dynamically allocated array for storing data
    int size;   // Number of elements in the array

public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();

    void merge(T* array, int low, int mid, int high);
    void mergeSort(T* array, int low, int high);

    void sort();  // Implement Sort Algorithm

    // Statistical Calculation Functions
    T findMedian();
    T findMin();
    T findMax();
    double findMean();
    T findSummation();

    // Utility Functions
    void displayArray();  // Display sorted array
    void inputData();     // Take input dynamically
    void statisticMenu(); // Menu for statistical operations
};

#endif // STATISTICALCALCULATION_H