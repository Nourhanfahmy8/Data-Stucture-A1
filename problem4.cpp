// Problem 4: Sorting Algorithms

#include <iostream>
#include <limits>
using namespace std;

/// function to swap
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
    void countSort(const int &d);  // Only for int
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
    int get_max(); // used to return the maximum number for the count and radix sort
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

/// function used to return the maximum element in the input data
template<>
int SortingSystem<int>::get_max() {
    int max_element = data[0];
    for(int i=0;i<this->size;i++){
        if(data[i]>max_element){
            max_element = data[i];
        }
    }
    return max_element;
}

template<>
void SortingSystem<int>::countSort(const int &d){

    // base used for the radix sort
    const int base = 10;

    // storing the max element
    int max_element = get_max();

    // creating a dynamic array to store the frequency of each element
    int*freq;

    // creating a dynamic array to store the result after sorting
    int *result = new int [this->size]();

    // count sort is called
    if(d==0){

        // the size of the frequency array = max_element + 1 as the array is zero based
        freq = new int[max_element+1]();
        for(int i = 0;i<max_element;i++){
            freq[i] =0;
        }

        cout << "\n1. Creating a frequency array to store the frequency of each element\n";
        // calculating the frequency of each value
        for(int j=0;j< this->size;j++){
            freq[data[j]] = freq[data[j]] +1;
        }

        // Display frequency array
        cout << "Frequency Array: [";
        for (int i = 0; i <= max_element; i++) {
            cout << freq[i] << " ";
        }
        cout << "]\n\n";

        cout << "2. Calculating the cumulative frequency to know how many elements are less than or equal each element\n";
        // calculating the cumulative frequency to know how many elements are less than or equal each element
        for(int i=1;i<=max_element;i++){
            freq[i] = freq[i] + freq[i-1];
        }

        // Display cumulative frequency array
        cout << "Cumulative Frequency Array: [";
        for (int i = 0; i <= max_element; i++) {
            cout << freq[i] << " ";
        }
        cout << "]\n\n";

        cout << "The array before sorting\n";
        displayData();
        cout << endl;
        // storing the sorted numbers in the result array
        for(int i=this->size-1;i>=0;i--){
            result[freq[data[i]]-1] = data[i];

            // Display the array after each interation
            cout << "- Placing [" << data[i] << "] at position : " << (freq[data[i]]-1)+1<< "\n";
            cout << "  Sorted Array: [";
            for (int j = 0; j < this->size; j++) {
                cout << result[j];
                if (j < this->size - 1) cout << " ";
            }
            cout << "] \n";
            freq[data[i]]= freq[data[i]]-1;
        }
        cout << "\n- This is a non comparative algorithm as it doesn't compare the elements directly, it takes:\n"
             << "  Best case: O(n + k)\n"
             << "  Average case: O(n + k)\n"
             << "  Worst case: O(n + k)\n"
             << "  where n is the number of elements and k is the range of input.\n\n";
        // radix sort was called
    }else {

        // dynamically allocating a frequency array
        freq = new int[base];

        // initialize the freq array to zero
        for (int i = 0; i < base; i++) {
            freq[i] = 0;
        }

        cout << "\n1. Creating a frequency array to store the frequency of each least significant digit\n";
        // Count the occurrences of each digit -> the least significant bit
        for (int i = 0; i < this->size; i++) {
            int digit = (data[i] / d) % base;
            freq[digit]++;
        }

        // Display frequency array
        cout << "Frequency Array for digit " << d << " [ ";
        for (int i = 0; i < base; i++) {
            cout << freq[i] << " ";
        }
        cout << "]\n\n";

        cout << "2. Calculating the cumulative frequency for each digit\n";
        // calculating the cumulative frequency for each digit
        for (int i = 1; i < base; i++) {
            freq[i] += freq[i - 1];
        }

        // Display cumulative frequency array
        cout << "Cumulative Frequency Array for digit " << d << " [ ";
        for (int i = 0; i < base; i++) {
            cout << freq[i] << " ";
        }
        cout << "]\n\n";

        cout << "The array before sorting\n";
        displayData();
        cout << endl;
        // storing the sorted numbers in the result array
        for (int i = this->size - 1; i >= 0; i--) {
            int digit = (data[i] / d) % base;
            result[freq[digit] - 1] = data[i];

            // Display the array after each interation
            cout << "- Placing [" << data[i] << "] at position : " << (freq[digit]-1)+1<< "\n";
            cout << "  Sorted Array: [";
            for (int j = 0; j < this->size; j++) {
                cout << result[j];
                if (j < this->size - 1) cout << " ";
            }
            cout << "]\n";
            freq[digit]--;

        }
        cout << "\nThis is a divide-and-conquer algorithm which takes:\n"
             << "Best case: O(n log n)\n"
             << "Average case: O(n log n)\n"
             << "Worst case: O(n^2)\n"
             << "where n is the number of elements.\n\n";
    }


    // Copy the sorted elements back to the original array
    for (int i = 0; i < this->size; i++) {
        data[i] = result[i];
    }

    // displaying the sorted elements
    displaySortedData();

    // deallocating the memory
    delete [] result;
    delete [] freq;
}

template <typename T>
void SortingSystem<T>::radixSort() {

    // getting the maximum element in the array to know the number of digits of that number
    // to know how many times the count sort function will be called
    int max_element = get_max();
    // for each loop, sort the elements based on the least significant bit
    for(int d=1;max_element/d >0;d*=10){
        countSort(d);
    }
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

/// method to show the main menu calling all the sorting methods
template <typename T>
void SortingSystem<T>::showMenu() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // making the user input the data he wants to sort
    for (int i = 0; i < size; i++)
    {
        cout << "- Enter data " << i + 1 << ": ";
        while (!(cin >> data[i])) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "\n";
    int choice;
    cout << "- Please select a sorting algorithm:\n";
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
            cout << "Sorting using Count Sort...\n";
            displayData();
            countSort(0);
            break;
        case 8:
            cout << "Radix Sort is only for integers!\n";
            displayData();
            radixSort();
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

/// main menu to check if the user wants to keep sorting or to exit
int main() {
    cout << "\n===== Welcome to the 'Sorting Program' =====\n";

    char choice;
    do {
        // asking the user to input the number of elements he wants to sort
        int size;
        cout << "- Please enter the number of items to sort: ";

        // validation check on the input
        while (!(cin >> size) || size <=0) {
            cout << "Invalid input. Please enter a valid positive integer greater than 0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        SortingSystem<int> sorter(size);
        sorter.showMenu();

        // asking the user if he wants to continue using the system or to exit
        cout << "\n\n- Do you want to sort another dataset? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(choice == 'N' || choice == 'n'){
            cout << "\n-- Thank you for using the sorting system! Goodbye!";
            break;
        }

    } while (choice == 'y' || choice == 'Y');
     return 0;
}
