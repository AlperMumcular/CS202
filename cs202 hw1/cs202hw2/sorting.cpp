/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Mumcular
*ID: 21902740
*Section: 1
*Assignment: 1
*Description: Sorting.cpp file
*/
#include "sorting.h"
#include <iomanip>
#include <cmath>
#include <iostream> 
using namespace std;  
#include "ctime"
#include <stdlib.h>

void sorting::insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
	for (int unsorted = 1; unsorted < size; ++unsorted) {

	    int nextItem = arr[unsorted];
	    moveCount++;
	    int loc = unsorted;
	
	    for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
	    	compCount++;
	        arr[loc] = arr[loc-1]; 
	        moveCount++;
		}
	
	    arr[loc] = nextItem;
	    moveCount++;
  }

}

void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
	int first = 0;
	int last = size - 1;
	
	mergeSort2(arr, first, last, compCount, moveCount, size);
}

void sorting::mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size) {
	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergeSort2(arr, first, mid, compCount, moveCount, size);

      mergeSort2(arr, mid+1, last, compCount, moveCount, size);

      // merge the two halves
      merge(arr, first, mid, last, compCount, moveCount, size);
   }
}

void sorting::merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount, const int MAX_SIZE) {
	
	int *tempArray = new int [MAX_SIZE];
   //int tempArray[MAX_SIZE]; 	// temporary array
   
   int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (theArray[first1] < theArray[first2]) {
	  	 compCount++;  
         tempArray[index] = theArray[first1];
         moveCount;
         ++first1;
      }
      else {
	  	  compCount++;  
          tempArray[index] = theArray[first2];
          moveCount++;
          ++first2;
      }
   }
   
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index) {
      tempArray[index] = theArray[first1]; 
      moveCount++;
	}

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index) {
      tempArray[index] = theArray[first2]; 
	  moveCount++;
	}

   // copy the result back into the original array
   for (index = first; index <= last; ++index) {
      theArray[index] = tempArray[index]; 
	  moveCount++;  
	}
	delete[] tempArray;
}  // end merge



void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount) {
	int first = 0;
	int last = size - 1;
	
	quicksort2(arr, first, last, compCount, moveCount);
}

void sorting::quicksort2(int theArray[], int first, int last, int &compCount, int &moveCount){
	int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quicksort2(theArray, first, pivotIndex-1, compCount, moveCount);
      quicksort2(theArray, pivotIndex+1, last, compCount, moveCount);
   }

}

void sorting::partition(int theArray[], int first, int last,
			int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot
   
	// place pivot in theArray[first]
   //choosePivot(theArray, first, last);

   int pivot = theArray[first]; // copy pivot
   moveCount++;
   
    // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown
   
	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
      	  compCount++;
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1], compCount, moveCount);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1], compCount, moveCount);
   pivotIndex = lastS1;
}

void sorting::swap(int &x, int &y, int &compCount, int &moveCount) {
   int temp = x;
   x = y;
   y = temp;
   moveCount = moveCount + 3;
}

int sorting::digits(int element){
    int digits = 0;
    for(;(int(element != 0)); ) {
    	digits++;
        element /= 10;   
    }
    return digits;
}

int sorting::FindDigitCount(int *arr, const int size){
    int digit = digits(arr[0]);
    for (int x = 0; x <= size-1; x = x+1) {
        if (digits(arr[x]) > digit ) {
            digit = digits(arr[x]);
        }
    }
    return digit;
}


void sorting::radixSort(int *arr, int size){
    int digitCount = FindDigitCount(arr, size);
    radixsort(arr, size, digitCount);
}

void sorting::radixsort(int *arr, const int size, int digit){
	int number;
	number = 0;
	int lastDigit;
	lastDigit = 0;
    for (int n = 0; n < digit ; n= n+1) {
    	int counter[10] = {0}; 
        int groups[10][size]; 
        for (int x = 0; x < size; x = x+1){
            lastDigit  = ((int)(arr[x]/pow(10, n)))%10;
            number = counter[((int)(arr[x]/pow(10, n)))%10];
            groups[ lastDigit ][number] = arr[x];
            counter[(int)(arr[x]/pow(10, n))%10] = number+1; 
        }
        
        int position;
		position = 0;
		int current;
        for (int x = 0; x <= 9; x = x+1) {
            int current;
			current = 0;
            while(current < counter[x]){
                arr[position] = groups[x][current];
                position = position + 1;
                current = current + 1;
            }
        }
    }
}

void sorting::printArray(int *arr, int size) {
	cout << "Array: [";
	for(int i = 0; i < size - 1; i++){
		cout << arr[i];
		cout << ", ";
	}
	cout << arr[size-1];
	cout << "]" << endl;
}

void sorting::performanceAnalysis() {
	int *tmp;
	double totaltime = 0;
	int tmpCompCount = 0;
	int tmpMoveCount = 0;
	cout << "-----------------------------------------------------" << endl;
	cout << "Part a - Time Analysis of Insertion Sort" << endl;
	cout << "Array Size             Time Elapsed          compCount          moveCount" << endl;
	int x;
	int size = 2000;
	int compCount = 0;
	int moveCount = 0;
	double duration;
	clock_t startTime;
	int *my2000Array1 = new int[size];
	int *my2000Array2 = new int[size];
	int *my2000Array3 = new int[size];
	int *my2000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my2000Array1[i] = x;
		my2000Array2[i] = x;
		my2000Array3[i] = x;
		my2000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my2000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my2000Array1;
	// 6000
	size = 6000;
	int *my6000Array1 = new int[size];
	int *my6000Array2 = new int[size];
	int *my6000Array3 = new int[size];
	int *my6000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my6000Array1[i] = x;
		my6000Array2[i] = x;
		my6000Array3[i] = x;
		my6000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my6000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my6000Array1;
	
	
	// 10000
	size = 10000;
	int *my10000Array1 = new int[size];
	int *my10000Array2 = new int[size];
	int *my10000Array3 = new int[size];
	int *my10000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my10000Array1[i] = x;
		my10000Array2[i] = x;
		my10000Array3[i] = x;
		my10000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my10000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                      " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "            " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my10000Array1;
	
	
	// 14000
	size = 14000;
	int *my14000Array1 = new int[size];
	int *my14000Array2 = new int[size];
	int *my14000Array3 = new int[size];
	int *my14000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my14000Array1[i] = x;
		my14000Array2[i] = x;
		my14000Array3[i] = x;
		my14000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my14000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                     " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "            " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my14000Array1;
	
	
	// 18000
	size = 18000;
	int *my18000Array1 = new int[size];
	int *my18000Array2 = new int[size];
	int *my18000Array3 = new int[size];
	int *my18000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my18000Array1[i] = x;
		my18000Array2[i] = x;
		my18000Array3[i] = x;
		my18000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my18000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                     " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "            " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my18000Array1;
	
	
	// 22000
	size = 22000;
	int *my22000Array1 = new int[size];
	int *my22000Array2 = new int[size];
	int *my22000Array3 = new int[size];
	int *my22000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my22000Array1[i] = x;
		my22000Array2[i] = x;
		my22000Array3[i] = x;
		my22000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my22000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                     " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "           " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my22000Array1;
	
	
	// 26000
	size = 26000;
	int *my26000Array1 = new int[size];
	int *my26000Array2 = new int[size];
	int *my26000Array3 = new int[size];
	int *my26000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my26000Array1[i] = x;
		my26000Array2[i] = x;
		my26000Array3[i] = x;
		my26000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my26000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                     " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "           " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my26000Array1;
	
	
	// 30000
	size = 30000;
	int *my30000Array1 = new int[size];
	int *my30000Array2 = new int[size];
	int *my30000Array3 = new int[size];
	int *my30000Array4 = new int[size];
	for (int i = 0; i < size; i++){
		x = rand();
		my30000Array1[i] = x;
		my30000Array2[i] = x;
		my30000Array3[i] = x;
		my30000Array4[i] = x;
	}
	for(int i = 0; i < 9; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my30000Array1[n];
		}
		startTime = clock();
		insertionSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                     " << std::fixed << std::setprecision(2) << totaltime/9 << " ms           " << compCount/100 << "           " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my30000Array1;
	
	
	
	
	// part b
	cout << "-----------------------------------------------------" << endl;
	cout << "Part b - Time Analysis of Merge Sort" << endl;
	cout << "Array Size             Time Elapsed          compCount          moveCount" << endl;
	// 2000
	size = 2000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my2000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my2000Array2;
	// 6000 
	size = 6000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my6000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my6000Array2; 
	// 10000
	size = 10000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my10000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my10000Array2;
	// 14000
	size = 14000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my14000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my14000Array2;
	// 18000
	size = 18000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my18000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my18000Array2;
	// 22000
	size = 22000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my22000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my22000Array2;
	// 26000
	size = 26000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my26000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                      " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my26000Array2;
	// 30000
	size = 30000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my30000Array2[n];
		}
		startTime = clock();
		mergeSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                      " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my30000Array2;




// part c
	cout << "-----------------------------------------------------" << endl;
	cout << "Part c - Time Analysis of Quick Sort" << endl;
	cout << "Array Size             Time Elapsed          compCount          moveCount" << endl;
	// 2000
	size = 2000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my2000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my2000Array3;
	// 6000 
	size = 6000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my6000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my6000Array3;
	// 10000
	size = 10000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my10000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "              " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my10000Array3;
	// 14000
	size = 14000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my14000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my14000Array3;
	// 18000
	size = 18000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my18000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my18000Array3;
	// 22000
	size = 22000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my22000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my22000Array3;
	// 26000
	size = 26000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my26000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my26000Array3;
	
	
	// 30000
	size = 30000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my30000Array3[n];
		}
		startTime = clock();
		quickSort(tmp, size, compCount, moveCount );
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms           " << compCount/100 << "             " << moveCount/100 << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[] my30000Array3;
	
	
	// part d radix sort
	cout << "-----------------------------------------------------" << endl;
	cout << "Part d - Time Analysis of Radix Sort" << endl;
	cout << "Array Size             Time Elapsed" << endl;
	// 100
	size = 2000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my2000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my2000Array4;
	
	
	// 6000 
	size = 6000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my6000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                        " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my6000Array4;
	
	
	// 10000
	size = 10000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my10000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my10000Array4;
	
	
	// 14000
	size = 14000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my14000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my14000Array4;
	
	
	// 18000
	size = 18000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my18000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my18000Array4;
	
	// 22000
	size = 22000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my22000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my22000Array4;
	
	
	// 26000
	size = 26000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my26000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my26000Array4;
	
	
	// 30000
	size = 30000;
	for(int i = 0; i < 100; i++) {
		tmp = new int[size];
		for(int n = 0; n < size; n++){
			tmp[n] = my30000Array4[n];
		}
		startTime = clock();
		radixSort(tmp, size);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		totaltime = totaltime + duration;
		delete[] tmp;
	}
	cout << size << "                       " << std::fixed << std::setprecision(2) << totaltime/100 << " ms" << endl;
	totaltime = 0;
	compCount = 0;
	moveCount = 0;
	delete[]  my30000Array4;
}
