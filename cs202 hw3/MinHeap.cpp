/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Cpp file of MinHeap class
*/
#include <iostream>
using namespace std;
#include "MinHeap.h"

MinHeap::MinHeap() : length(0) {

}

bool MinHeap::heapIsEmpty() const {
	return (length == 0);
}

void MinHeap::heapInsert(const int&newItem) {

	if (length >= MIN_HEAP){
	}
		

	// Place the new item at the end of the heap
	items[length] = newItem;

	// Trickle new item up to its proper position
	int place = length;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place] < items[parent] ) ) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++length;
}

void MinHeap::heapDelete(int&rootItem) {
	if (heapIsEmpty())
		{}
	else {
		rootItem = items[0];
		items[0] = items[--length];
		heapRebuild(0);
	}
}

void MinHeap::heapRebuild(int root) {   
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < length ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < length) &&
		     (items[rightChild] <items[child] ) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root] > items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		} 
	}
}


void MinHeap::insert(int value) {
	heapInsert(value);
}

int MinHeap::peek() {
	if(heapIsEmpty())
		return -1; // no elements
	else
		return items[0];
}

int MinHeap::extractMin() {
	int min;
	heapDelete(min);
	return min;
}

int MinHeap::size() {
	return length;
}
