/* header file for sorting algorithms */

#ifndef SORTS_H_
#define SORTS_H_

void swap(int array[], int index1, int index2);

void insertionSort(int array[], int arraySize);

void shellSort(int array[], int arraySize);

void bottomUpMergeSort(int array[], int arraySize);

void merge(int array[], int tempArray[], int leftArrayIndex, int rightArrayIndex, int rightArrayEnd);

#endif