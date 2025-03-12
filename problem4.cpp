#include <iostream>
#include <limits>
using namespace std;

void swap (int &x , int &y){
    x = x ^ y ;
    y = x ^ y ;
    x = x ^ y ;
}

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
    void displaySortedData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
};
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
    for (int i = 0 ; i < this->size - 1 ; i++){
        for (int j = this->size-1 ; j > i ; j--){
            if (this->data[j] < this->data[j-1]){
                cout << "Element [ "<<data[j-1] << " ] is bigger than [ " << data[j] << " ] so swap between them ... \n" ;
                swap (this->data[j-1] , this->data[j]);                
                displaySortedData();
            }
        }
    }
    cout << "\nThis is 3-cases algorithm which takes \nBest case : O(n)\nAverage case : O(n^2)\nWorst case : O(n^2)" ;
    
}

template <typename T>
void SortingSystem<T>::shellSort() { 
    for (int gap = size / 2 ; gap > 0 ; gap/=2){
        for (int j = gap ; j < size ; j++){
            for (int i = j ; i >=gap ; i-=gap){
                if (data[i-gap] > data[i]){
                    swap(data[i-gap] , data[i]);
                    cout << "Gap is equal "<<gap<< " and element [ "<<data[i] << " ] is bigger than [ " << data[i-gap] << " ] so swap between them ... \n" ;
                    displaySortedData() ;
                }
            }
        }
    }
    cout << "\nThis is 3-cases algorithm which takes \nBest case : O(n)\nAverage case : O(n^1.5)\nWorst case : O(n^2)" ;
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
void SortingSystem<T>::displaySortedData() {
    cout << "Sorted Data: [";
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
