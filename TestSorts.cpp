/* a program to test sorting algorithm implementations */

#include <iostream>
#include "Sorts.h"

void printNums(int array[], int arraySize);
bool isSorted(int array[], int arraySize);

int main() {
    int nums[23] = {18, 13, 3, 17, 14, 38, 21, 16, 40, 3, 18, 2, 5, 67, 34, 2, 67, 88, 94, 23, 63, 78, 80};
    int numsSize = 23;
    bottomUpMergeSort(nums, numsSize);
    printNums(nums, numsSize);
    std::string output;
    isSorted(nums, numsSize) == true ? output = "the array is sorted" : output = "the array is not sorted";
    std::cout << "\n" << output << std::endl;
}

void printNums(int array[], int arraySize) {
    std::cout << "[";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

bool isSorted(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] < array[0]) {
            return false;
        }
    }
    return true;
}