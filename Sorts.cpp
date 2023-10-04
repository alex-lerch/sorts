/* implementations of sorting algorithms */

#include "Sorts.h"

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void insertionSort(int array[], int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        int num = array[i];
        int j = i;
        while (j > 0 && (num < array[j - 1])) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = num;
    }
}

void shellSort(int array[], int arraySize) {
    for (int gap = 2^arraySize - 1; gap > 0; gap--) {
        for (int i = 0; i < arraySize; i++) {
            int num = array[i];
            int j = i;
            while (j >= gap && num < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = num;
        }
    }
}

void bottomUpMergeSort(int array[], int arraySize) {
    // temporary array used to help sort the logical arrays
    int tempArray[arraySize];

    // the size of the logical arrays that are sorted
    int sizeOfSortedArrays = 1;

    // while we still have logical arrays to sort
    while (sizeOfSortedArrays < arraySize) {

        // the start index for the left logical array to be sorted
        int leftArrayIndex = 0;

        // check for real group
        while ( leftArrayIndex < (arraySize - sizeOfSortedArrays) ) {

            // calculate the start index for the right array
            int rightArrayIndex = leftArrayIndex + sizeOfSortedArrays;

            // calculate the end index for the right array
            int rightArrayEnd;
            if (arraySize < (leftArrayIndex + (2 * sizeOfSortedArrays) )) {
                rightArrayEnd = arraySize;
            }
            else {
                rightArrayEnd = rightArrayIndex + (sizeOfSortedArrays - 1);
            }

            // merge the two logical arrays
            merge(array, tempArray, leftArrayIndex, rightArrayIndex, rightArrayEnd);

            // move start index for the left array to the next unsorted logical array
            leftArrayIndex += 2 * sizeOfSortedArrays;
        } 



        // update the size of sorted arrays
        sizeOfSortedArrays *= 2;
    }
}


void merge(int array[], int tempArray[], int leftArrayIndex, int rightArrayIndex, int rightArrayEnd) {
    int leftArrayEnd = rightArrayIndex - 1;
    int tempPosition = leftArrayIndex;
    int numElements = rightArrayEnd - leftArrayIndex + 1;

    while (leftArrayIndex <= leftArrayEnd && rightArrayIndex <= rightArrayEnd) {
        if (array[leftArrayIndex] <= array[rightArrayIndex]) {
            tempArray[tempPosition++] = array[leftArrayIndex++];
        }
        else {
            tempArray[tempPosition++] = array[rightArrayIndex++];
        }
    }

    while (leftArrayIndex <= leftArrayEnd) {
        tempArray[tempPosition++] = array[leftArrayIndex++];
    }

    while (rightArrayIndex <= rightArrayEnd) {
        tempArray[tempPosition++] = array[rightArrayIndex++];
    }

    // copy tempArray back to array. needs to be fixed for it279 program 3 implementation
    for (int i = 0; i < numElements; ++i, --rightArrayEnd) {
        array[rightArrayEnd] = tempArray[rightArrayEnd];
    }
}