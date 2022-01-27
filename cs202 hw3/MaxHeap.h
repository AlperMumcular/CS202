/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Header file of MaxHeap class
*/
#ifndef MAXHEAP__H
#define MAXHEAP__H
const int MAX_HEAP = 100;

class MaxHeap {
public:
	MaxHeap();				// default constructor
	// copy constructor and destructor are supplied by the compiler
	bool heapIsEmpty() const;
	void heapInsert(const int& newItem);
	void heapDelete(int& rootItem);

	void insert(int value);
	int peek();
	int extractMax();
	int size();

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
	int items[MAX_HEAP];	// array of heap items
	int          length;            	// number of heap items
	friend class MedianHeap;
}; 
#endif

