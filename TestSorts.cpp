/* a program to test sorting algorithm implementations */

#include <iostream>
#include "Sorts.h"

void printNums(int array[], int arraySize);

int main() {
    int nums[24] = {33, 18, 13, 3, 17, 14, 38, 21, 16, 40, 3, 18, 2, 5, 67, 34, 2, 67, 88, 94, 23, 63, 78, 80};
    bottomUpMergeSort(nums, 24);
    printNums(nums, 24);
}

void printNums(int array[], int arraySize) {
    std::cout << "[";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << "]" << std::endl;
}