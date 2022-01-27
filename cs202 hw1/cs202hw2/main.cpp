/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Mumcular
*ID: 21902740
*Section: 1
*Assignment: 1
*Description: main.cpp file
*/
#include <iostream> 
using namespace std; 
#include "sorting.h"
#include "sorting.h"
  
int main () 
{ 
	sorting s;
  	
  	int arr1[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
  	int arr2[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
  	int arr3[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
  	int arr4[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
  	
  	int compCount = 0;
  	int moveCount = 0;
  	s.insertionSort(arr1, 16, compCount, moveCount);
  	s.printArray(arr1, 16);
  	compCount = 0;
  	moveCount = 0;
  	s.mergeSort(arr2, 16, compCount, moveCount);
  	s.printArray(arr2, 16);
  	compCount = 0;
  	moveCount = 0;
  	s.quickSort(arr3, 16, compCount, moveCount);
  	s.printArray(arr3, 16);
  	compCount = 0;
  	moveCount = 0;
  	s.radixSort(arr4, 16);
  	s.printArray(arr4, 16);

	s.performanceAnalysis();
	
    return 0; 
} 
