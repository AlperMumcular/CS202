/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Cpp file of MedianHeap class
*/
#include "MedianHeap.h"
using namespace std;

MedianHeap::MedianHeap() : length(0) {
}

void MedianHeap::insert( int value ) {
	if (value >= min.items[0] ) 
		min.insert(value); 
	else if( min.heapIsEmpty() )
		min.insert(value); 
	else
		max.insert(value); 
	this->balance();
	length++;
}

int MedianHeap::findMedian() {
	return min.items[0];
}

void MedianHeap::balance() {
	if( min.length - max.length > 1 )
		max.insert( min.extractMin() );
	else if ( max.length > min.length  )
		min.insert( max.extractMax() );
}
