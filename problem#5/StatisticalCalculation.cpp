#include "StatisticalCalculation.h"
#include <iostream> 
#include <limits>

using namespace std;

template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int size) : size(size) {
    data = new T[size];
}

template <typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data;
}

template <typename T>
void StatisticalCalculation<T>::merge(T* array, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    T* left = new T[n1];
    T* right = new T[n2];

    for (int i = 0; i < n1; ++i) {
        left[i] = array[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < n1) {
        array[k++] = left[i++];
    }

    while (j < n2) {
        array[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

template <typename T>
void StatisticalCalculation<T>::mergeSort(T* array, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, mid, high);
    }
}

template <typename T>
void StatisticalCalculation<T>::sort() {
    mergeSort(data, 0, size - 1);
}

template <typename T>
T StatisticalCalculation<T>::findMedian() {
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