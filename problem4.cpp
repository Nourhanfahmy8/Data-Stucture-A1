// Problem 4: Sorting Algorithms
#include <algorithm>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <chrono>
#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>
#include <cstring>
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
    SortingSystem(int n, T* data);
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
};

template <typename T>
SortingSystem<T>::SortingSystem(int n, T* data) {
    size = n;
    this->data = new T[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = data[i];
    }
}


template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
    data = nullptr;
}

template <typename T>
void SortingSystem<T>::insertionSort() {
    // Implementation here
}

template <typename T>
void SortingSystem<T>::selectionSort() {
    for (int i = 0; i < this->size - 1; i++) {
        int least = i; // Initialize the index of the smallest element to the current index
        // Find the index of the smallest element in the unsorted portion
        for (int j = i + 1; j < this->size; j++) {
            if (this->data[j] < this->data[least]) {
                least = j;
            }
        }

        // Output the least element found in this iteration
        cout << "-> Least element [" << this->data[least] << "] in iteration " << i << " is at index [" << least << "]\n";
        // Swap the smallest element with the current element
        swap(this->data[least], this->data[i]);
        cout << "Swapped elements:\n"
             << " -> " << this->data[least] << " at index " << i << "\n -> " << this->data[i] << " at index " << least << "\n";

        // Display the current state of the array
        cout << "Set after iteration " << i << ": \n[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]\n\n";
    }
    cout << "-> This is a 1-case algorithm, it takes:\n"
         << "  Best Case: O(n^2) (even if the array is already sorted, the algorithm still performs all comparisons).\n"
         << "  Average case: O(n^2)\n"
         << "  Worst Case: O(n^2) (when the array is in reverse order).\n"
         << "  where n is the number of elements.\n";
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
    if (left >= right) return;

    int pivotIndex = partition(left , right);
    cout << "\n-> Pivot: " << this->data[pivotIndex] ;

    // Display the current state of the array
    cout << " -> Set: " << "[" ;
    for (int i = left; i <= right; i++) {
        cout << data[i];
        if (i < right) {
            cout << ", ";
        }
    }
    cout << "]\n";

    // Recursively make the same thing to the part before and after pivot
    quickSort(left , pivotIndex - 1);
    quickSort(pivotIndex + 1 , right);
}

template<typename T>
void SortingSystem<T>::countSort(const int &d){

    if(is_same<T, int>::value){
        if constexpr (is_same<T, int>::value) {
            // base used for the radix sort
            const int base = 10;

            // storing the max element
            int max_element = data[0];
            for(int i=0;i<this->size;i++){
                if(data[i]>max_element){
                    max_element = data[i];
                }
            }

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
                    //extracting the least significant bit
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
                     << "Best case: O(d*(n+k))\n"
                     << "Average case: O(d*(n + k))\n"
                     << "Worst case: O(d*(n + k))\n"
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
    }else{
        cout << "Count Sort is only for integers!\n";
        return;
    }
}

template <typename T>
void SortingSystem<T>::radixSort() {

    if(is_same<T, int>::value)
    {
        if constexpr (is_same<T, int>::value) {
            // getting the maximum element in the array to know the number of digits of that number
            // to know how many times the count sort function will be called
            int max_element = data[0];
            for(int i=0;i<this->size;i++){
                if(data[i]>max_element){
                    max_element = data[i];
                }
            }

            // for each loop, sort the elements based on the least significant bit
            for(int d=1;max_element/d >0;d*=10){
                countSort(d);
            }
        }
    }else{
        cout << "Radix Sort is only for integers!\n";
        return;
    }
}

template <typename T>
void SortingSystem<T>::bucketSort() {
    if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(double))
    {
        T maxValue = data[0];
        T minValue = data[0];
        for(int i = 1; i < size; i++){
            if(data[i] > maxValue)
                maxValue = data[i];
            if(data[i] < minValue)
                minValue = data[i];
        }

        int bucketCount = size;
        T** buckets = new T*[bucketCount];
        int* bucketSizes = new int[bucketCount]();

        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = new T[size];
        }
        for (int i = 0; i < size; i++) {
            if constexpr (is_same<T, int>::value || is_same<T, float>::value || is_same<T, double>::value) {
                int index = (bucketCount * (data[i] - minValue)) / (maxValue - minValue + 1);
                buckets[index][bucketSizes[index]++] = data[i];
            } else {
                cout << "Bucket sort for non-numeric types is not supported in this branch.\n";
            }
        }
        cout << "Unsorted buckets: " << endl;
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Sorted buckets: " << endl;
        for (int i = 0; i < bucketCount; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
                    if (buckets[i][k] > buckets[i][k + 1]) {
                        T temp = buckets[i][k];
                        buckets[i][k] = buckets[i][k + 1];
                        buckets[i][k + 1] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }
        int index = 0;
        for (int i = 0; i < bucketCount; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                data[index++] = buckets[i][j];
            }
        }
        for (int i = 0; i < bucketCount; i++) {
            delete[] buckets[i];
        }
        delete[] buckets;
        delete[] bucketSizes;
        displaySortedData();
    }
    else if(typeid(T) == typeid(string)){
        int bucketCount = 26;
        T** buckets = new T*[bucketCount];
        int* bucketSizes = new int[bucketCount]();

        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = new T[size];
        }

        for (int i = 0; i < size; i++) {
            if(is_same<T, string>::value){
                if constexpr (is_same<T, string>::value) {
                    int index = data[i][0] - 'a';
                    buckets[index][bucketSizes[index]++] = data[i];
                } else {
                    cout << "Bucket sort for non-string types is not supported in this branch.\n";
                }
            }
        }

        int index = 0;
        for (int i = 0; i < bucketCount; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                data[index++] = buckets[i][j];
            }

        }


        cout << "Unsorted buckets: " << endl;
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Sorted buckets: " << endl;
        for (int i = 0; i < bucketCount; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
                    if (buckets[i][k] > buckets[i][k + 1]) {
                        T temp = buckets[i][k];
                        buckets[i][k] = buckets[i][k + 1];
                        buckets[i][k + 1] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < bucketSizes[i]; j++) {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }

        index = 0;
        for (int i = 0; i < bucketCount; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                data[index++] = buckets[i][j];
            }
        }

        for (int i = 0; i < bucketCount; i++) {
            delete[] buckets[i];
        }
        delete[] buckets;
        delete[] bucketSizes;

        displaySortedData();
    }


}


template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
    // Implementation here
}

/// function to get the pivot of quicksort
template <typename T>
int SortingSystem<T>::partition(int low, int high) {

    // This function used to make all the elements before pivot is smaller amd what elements after pivot is greater
    T x = this->data[low];
    // Let the pivot is the first element
    int i  = low;
    /* Put j at the index after the first element
     If the element that i points to is greater so make with order
     - increase the index i
     - swap the elements on both indices
     - increase the index j , else increase the index j only
     */
    for (int j = low + 1 ; j <= high; j++){
        if (this->data[j] <= x){
            i++;
            if (i != j) {  // Avoid unnecessary swaps
                swap(this->data[i], this->data[j]);
            }
        }
    }
    // making sure that i is not > high (not out of range)
    if (i != low) {
        swap(this->data[i], this->data[low]);
    }

    return i;
}

template <typename T>
void SortingSystem<T>::displayData() {
    cout << "[";
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
    auto start = std::chrono::high_resolution_clock::now();

    (this->*sortFunc)();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Sorting completed in: " << duration.count() << " seconds.\n";
}

/// method to show the main menu calling all the sorting methods
template <typename T>
void SortingSystem<T>::showMenu() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int choice;
    cout << "\n- Please select a sorting algorithm:\n";
    cout << "   1. Insertion Sort\n";
    cout << "   2. Selection Sort\n";
    cout << "   3. Bubble Sort\n";
    cout << "   4. Shell Sort\n";
    cout << "   5. Merge Sort\n";
    cout << "   6. Quick Sort\n";
    cout << "   7. Count Sort (Only for integers)\n";
    cout << "   8. Radix Sort (Only for integers)\n";
    cout << "   9. Bucket Sort\n";

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
            cout << "Initial Data: ";

            displayData();
            insertionSort();
            break;
        case 2:
            cout << "Sorting using Selection Sort...\n";
            cout << "Initial Data: ";

            displayData();
            selectionSort();
            break;
        case 3:
            cout << "Sorting using Bubble Sort...\n";
            cout << "Initial Data: ";

            displayData();
            bubbleSort();
            break;
        case 4:
            cout << "Sorting using Shell Sort...\n";
            cout << "Initial Data: ";

            displayData();
            shellSort();
            break;
        case 5:
            cout << "Sorting using Merge Sort...\n";
            cout << "Initial Data: ";

            displayData();
            mergeSort(0, size - 1);
            break;
        case 6:
            cout << "Sorting using Quick Sort...\n";
            cout << "Initial Data: ";

            displayData();
            quickSort(0, size - 1);
            cout << "\n-> Final Sorted Set: ";
            displayData();
            //measureSortTime(&SortingSystem::quickSort(0,size-1));
            cout << "\n-> This is a divide-and-conquer algorithm which takes:\n"
                 << "Best case: O(n log n)\n"
                 << "Average case: O(n log n)\n"
                 << "Worst case: O(n^2)\n"
                 << "Partition part: O(n)\n"
                 << "where n is the number of elements.\n\n";
            break;
        case 7:
            cout << "Sorting using Count Sort...\n";
            cout << "Initial Data: ";

            displayData();
            countSort(0);
            break;
        case 8:
            cout << "Radix Sort is only for integers!\n";
            cout << "Initial Data: ";

            displayData();
            radixSort();
            break;
        case 9:
            cout << "Sorting using Bucket Sort...\n";
            cout << "Initial Data: ";

            displayData();
            bucketSort();
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

}


bool isNumber(const string& s) {
    return all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    cout << "\n===== Welcome to the 'Sorting Program' =====\n";

    char choice;
    do {
        int size;
        cout << "- Please enter the number of items to sort: ";

        while (!(cin >> size) || size <= 0) {
            cout << "Invalid input. Please enter a valid positive integer greater than 0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string DataType;
        cout << "Enter Data 1: ";

        cin.ignore();

        string temp;
        getline(cin, temp);

        if (isNumber(temp)) {
            DataType = "int";
        } else {
            try {
                stof(temp);
                DataType = "float";
            } catch (...) {
                DataType = "string";
            }
        }

        void* data = nullptr;

        if (DataType == "int") {
            data = new int[size];
            static_cast<int*>(data)[0] = stoi(temp);
        } else if (DataType == "float") {
            data = new float[size];
            static_cast<float*>(data)[0] = stof(temp);
        } else if (DataType == "string") {
            data = new string[size];
            static_cast<string*>(data)[0] = temp;
        } else {
            cout << "Unsupported data type!\n";
            return 1;
        }

        for (int i = 1; i < size; i++) {
            cout << "Enter Data " << i + 1 << ": ";
            if (DataType == "int") {
                string input;
                while (true) {
                    cin >> input;
                    if (isNumber(input)) {
                        static_cast<int*>(data)[i] = stoi(input);
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (DataType == "float") {
                string input;
                while (true) {
                    cin >> input;
                    try {
                        static_cast<float*>(data)[i] = stof(input);
                        break;
                    } catch (...) {
                        cout << "Invalid input. Please enter a valid float number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            } else if (DataType == "string") {
                getline(cin, static_cast<std::string*>(data)[i]);
            }
        }

        if (DataType == "int") {
            SortingSystem<int> sorter(size, static_cast<int*>(data));
            sorter.showMenu();
        } else if (DataType == "float") {
            SortingSystem<float> sorter(size, static_cast<float*>(data));
            sorter.showMenu();
        } else if (DataType == "string") {
            SortingSystem<string> sorter(size, static_cast<string*>(data));
            sorter.showMenu();
        } else {
            cout << "Invalid choice!\n";
        }

        if (DataType == "int") {
            delete[] static_cast<int*>(data);
        } else if (DataType == "float") {
            delete[] static_cast<float*>(data);
        } else if (DataType == "string") {
            delete[] static_cast<string*>(data);
        }

        cout << "\n\n- Do you want to sort another dataset? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 'N' || choice == 'n') {
            cout << "\n-- Thank you for using the sorting system! Goodbye!\n";


            break;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
