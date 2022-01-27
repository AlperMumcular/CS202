/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Header file of MinHeap class
*/
#ifndef MINHEAP__H
#define MINHEAP__H
const int MIN_HEAP = 100;

class MinHeap {
public:
	MinHeap();				// default constructor
	// copy constructor and destructor are supplied by the compiler
	bool heapIsEmpty() const;
	void heapInsert(const int& newItem);
	void heapDelete(int& rootItem);

	void insert(int value);
	int peek();
	int extractMin();
	int size();

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
	int items[MIN_HEAP];	// array of heap items
	int          length;            	// number of heap items
	friend class MedianHeap;
}; 
#endif

