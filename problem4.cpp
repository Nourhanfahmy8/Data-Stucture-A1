
#ifndef SORTING_SYSTEM_H
#define SORTING_SYSTEM_H

#include <iostream>
#include <limits>

using namespace std;

template <typename T>
class SortingSystem {
private:
    T* data;  // Dynamic array for storing input data
    int size; // Size of the array

public:
    // Constructor & Destructor
    SortingSystem(int n);
    ~SortingSystem();

    // Sorting Algorithms
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();  // Only for int
    void radixSort();  // Only for int
    void bucketSort();

    // Helper Functions
    void merge(int left, int mid, int right);
    int partition(int low, int high);

    // Utility Functions
    void displayData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
};

#endif 

template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
}


template <typename T>
SortingSystem<T>::~SortingSystem() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::insertionSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::selectionSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::shellSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::countSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::radixSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::bucketSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
    // Implementation here
}

template <typename T>
int SortingSystem<T>::partition(int low, int high) {
    // Implementation here
    return 0;
}

template <typename T>
void SortingSystem<T>::displayData() {
    cout << "Initial Data: [";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]"<<endl;
    
}

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::showMenu() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < size; i++)
    {
        cout << "Enter data " << i + 1 << ": ";
        while (!(cin >> data[i])) { 
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    cout << "\n";
    int choice;
    cout << "Select a sorting algorithm:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Quick Sort\n";
    cout << "7. Count Sort (Only for integers)\n";
    cout << "8. Radix Sort (Only for integers)\n";
    cout << "9. Bucket Sort\n";
    
    cout << "Enter your choice (1-9): ";
    
    while (!(cin >> choice) || choice < 1 || choice > 9) {
        cout << "Invalid input. Please enter a number between 1 and 9: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    switch (choice) {
        case 1: 
            cout << "Sorting using Insertion Sort...\n";
            displayData();
            insertionSort();
            break;
        case 2: 
            cout << "Sorting using Selection Sort...\n";
            displayData();
            selectionSort();
            break;
        case 3: 
            cout << "Sorting using Bubble Sort...\n";
            displayData();
            bubbleSort();
            break;
        case 4: 
            cout << "Sorting using Shell Sort...\n";
            displayData();
            shellSort();
            break;
        case 5: 
            cout << "Sorting using Merge Sort...\n";
            displayData();
            mergeSort(0, size - 1);
            break;
        case 6: 
            cout << "Sorting using Quick Sort...\n";
            displayData();
            quickSort(0, size - 1);
            break;
        case 7: 
            cout << "Count Sort is only for integers!\n";
            displayData();
            break;
        case 8: 
            cout << "Radix Sort is only for integers!\n";
            displayData();
            break;
        case 9: 
            cout << "Sorting using Bucket Sort...\n";
            displayData();
            bucketSort();
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
    
}

int main() {
    char choice; 
    do {
        int size;
        cout << "Enter the number of items to sort: ";
        cin >> size;

        SortingSystem<string> sorter(size);
        sorter.showMenu();

        cout << "\n\nDo you want to sort another dataset? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice == 'y' || choice == 'Y'); 
     return 0;
}
