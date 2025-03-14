#ifndef STATISTICALCALCULATION_H
#define STATISTICALCALCULATION_H

#include <iostream>
#include <limits>
using namespace std;

// Class for Statistical Calculation
template <typename T>
class StatisticalCalculation {
private:
    T* data;    // Dynamically allocated array for storing data
    int size;   // Number of elements in the array

public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();

    void sort();  // Implement Sort Algorithm

    // Statistical Calculation Functions
    double findMedian();
    T findMin();
    T findMax();
    double findMean();
    T findSummation();

    // Utility Functions
    void displayArray();  // Display sorted array
    void inputData();     // Take input dynamically
    void statisticMenu(); // Menu for statistical operations
};

#endif 

//============================================================

template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int size) : size(size) {
    data = new T[size];
}

template <typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data;
    data = nullptr;
}

template <typename T>
void StatisticalCalculation<T>::sort() {
    bool flag = true;
    
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++) 
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

template <typename T>
double StatisticalCalculation<T>::findMedian() {
    sort();
    if (size % 2 == 0) {
        return static_cast<double>(data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return static_cast<double>(data[size / 2]);
    }
}

template <typename T>
T StatisticalCalculation<T>::findMin() {
    sort();
    return data[0];
}

template <typename T>
T StatisticalCalculation<T>::findMax() {
    sort();
    return data[size - 1];
}

template <typename T>
double StatisticalCalculation<T>::findMean() {
    T sum = findSummation();
    return static_cast<float>(sum) / size;
}

template <typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

template <typename T>
void StatisticalCalculation<T>::displayArray() {
    cout << "Sorted Array: [";
    for (int i = 0; i < size; ++i) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <typename T>

void StatisticalCalculation<T>::inputData() {
    for (int i = 0; i < size; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        while (!(cin >> data[i])) { 
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

template <typename T>
void StatisticalCalculation<T>::statisticMenu() {
    int choice;
    do {
        cout << "Select a statistical calculation:\n";
        cout << "1. Find Median\n";
        cout << "2. Find Minimum\n";
        cout << "3. Find Maximum\n";
        cout << "4. Find Mean\n";
        cout << "5. Find Summation\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Median: " << findMedian() << endl;
                break;
            case 2:
                cout << "Minimum: " << findMin() << endl;
                break;
            case 3:
                cout << "Maximum: " << findMax() << endl;
                break;
            case 4:
                cout << "Mean: " << findMean() << endl;
                break;
            case 5:
                cout << "Summation: " << findSummation() << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice < 1 || choice > 5);
}


//============================================================
int main(){
    int size;
    cout << "Enter the number of elements: ";

    while (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Please enter a valid positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    
    StatisticalCalculation<double> sc(size);
    sc.inputData();
    sc.sort();
    sc.displayArray();
    sc.statisticMenu();
    return 0;
}