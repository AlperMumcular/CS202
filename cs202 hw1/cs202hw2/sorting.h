/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Mumcular
*ID: 21902740
*Section: 1
*Assignment: 1
*Description: Sorting.h file
*/
#ifndef SORTING_H_
#define SORTING_H_

class sorting {
	public:
		void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
		void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
		void quickSort(int *arr, const int size, int &compCount, int &moveCount);
		void radixSort(int *arr, const int size);
		void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount, const int size);
		void mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size);
		void quicksort2(int theArray[], int first, int last, int &compCount, int &moveCount);
		void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
		void swap(int &x, int &y, int &compCount, int &moveCount);
		void printArray(int *arr, int size);
		void performanceAnalysis();
		int digits(int element);
		int FindDigitCount(int *arr, const int size);
		void radixsort(int *arr, const int size, int maxDigit);
};

#endif 
