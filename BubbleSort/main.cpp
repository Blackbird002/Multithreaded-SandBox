/*
Riad Shash (Ray)
Bubble Sort C++ implementation
*/

#include <iostream>

void swap(int &num1, int &num2);
void bubbleSort(int array[], const int &arraySize);
void printArray(int array[], const int &arraySize);

int main(void){

    int ary1[10] = {9,4,2,5,7,8,1,0,6,3};
    std::cout<<"Bubble Sort \n";
    std::cout<<"Array: { 9,4,2,5,7,8,1,0,6,3 } \n";
    bubbleSort(ary1,10);
    printArray(ary1,10);
    std::cin.ignore();

    return 0;
}

//Swaps two given array elements
void swap(int &num1, int &num2){
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

void printArray(int array[], const int &arraySize){
    std::cout<<"After sorting (using Bubble Sort): ";
    std::cout<<"{ ";
    for(int i = 0; i < arraySize; i++){
        std::cout<<array[i] <<" ";
    }
    std::cout<<"}";
}

//Bubble Sort Algorithm
void bubbleSort(int array[], const int &arraySize){
    int i,j;
    for (i = 0; i < arraySize-1; i++){
        for(j = 0; j < arraySize-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}
