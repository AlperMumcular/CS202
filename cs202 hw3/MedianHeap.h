/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Header file of MedianHeap class
*/
#ifndef MEDIANHEAP__H
#define MEDIANHEAP__H
#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

class MedianHeap {
public:
	MedianHeap();
	void insert(int value);
	int findMedian();
	void balance();
	
private:
	int          length;            	// number of heap items
	MaxHeap max;
	MinHeap min;
}; 
#endif

