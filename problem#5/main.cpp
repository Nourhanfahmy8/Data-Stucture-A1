#include<iostream>
#include "StatisticalCalculation.cpp"
using namespace std;

void Statistical_Calculation(){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    StatisticalCalculation<int> sc(size);
    sc.inputData();
    sc.sort();
    sc.displayArray();
    sc.statisticMenu();
}


int main(){
    Statistical_Calculation();
    return 0;
}