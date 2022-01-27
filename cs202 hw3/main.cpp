/*
* Title : Heaps and AVL Trees
* Author : Alper Mumcular
* ID : 21902740
* Section : 1
* Assignment : 3
* Description : Main class of Question 1
*/
#include <iostream>
using namespace std;
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

int main(int argc, char** argv) {
    MaxHeap myHeap;
   
    cout << "Inserting 5 " << endl; myHeap.insert(5);
    cout << "Inserting 4 " << endl; myHeap.insert(4);
    cout << "Size is: " << myHeap.size() << endl;
    cout << "Peak is: " << myHeap.peek() << endl;
	cout << "Inserting 6 " << endl; myHeap.insert(6);
	cout << "Inserting 7 " << endl; myHeap.insert(7);
	cout << "Size is: " << myHeap.size() << endl;
	cout << "Peak is: " << myHeap.peek() << endl;
	cout << "Inserting 3 " << endl; myHeap.insert(3);
	cout << "Inserting 1 " << endl; myHeap.insert(1);
	cout << "Inserting 2 " << endl; myHeap.insert(2);
	cout << "Size is: " << myHeap.size() << endl;
	cout << "Peak is: " << myHeap.peek() << endl;

	cout << "Deleted item: " << myHeap.extractMax() << endl;
	cout << "Size is: " << myHeap.size() << endl;
	cout << "Peak is: " << myHeap.peek() << endl;
	
	cout << "Deleted item: " << myHeap.extractMax() << endl;
	cout << "Size is: " << myHeap.size() << endl;
	cout << "Peak is: " << myHeap.peek() << endl;
	
	cout << "Deleted item: " << myHeap.extractMax() << endl;
	cout << "Size is: " << myHeap.size() << endl;
	cout << "Peak is: " << myHeap.peek() << endl;
	
	cout << "\n\n\n\n\n\n";
	
	MinHeap myHeap2;
   
    cout << "Inserting 5 " << endl; myHeap2.insert(5);
    cout << "Inserting 4 " << endl; myHeap2.insert(4);
    cout << "Size is: " << myHeap2.size() << endl;
    cout << "Peak is: " << myHeap2.peek() << endl;
	cout << "Inserting 6 " << endl; myHeap2.insert(6);
	cout << "Inserting 7 " << endl; myHeap2.insert(7);
	cout << "Size is: " << myHeap2.size() << endl;
	cout << "Peak is: " << myHeap2.peek() << endl;
	cout << "Inserting 3 " << endl; myHeap2.insert(3);
	cout << "Inserting 1 " << endl; myHeap2.insert(1);
	cout << "Inserting 2 " << endl; myHeap2.insert(2);
	cout << "Size is: " << myHeap2.size() << endl;
	cout << "Peak is: " << myHeap2.peek() << endl;

	cout << "Deleted item: " << myHeap2.extractMin() << endl;
	cout << "Size is: " << myHeap2.size() << endl;
	cout << "Peak is: " << myHeap2.peek() << endl;
	
	cout << "Deleted item: " << myHeap2.extractMin() << endl;
	cout << "Size is: " << myHeap2.size() << endl;
	cout << "Peak is: " << myHeap2.peek() << endl;
	
	cout << "Deleted item: " << myHeap2.extractMin() << endl;
	cout << "Size is: " << myHeap2.size() << endl;
	cout << "Peak is: " << myHeap2.peek() << endl;
	
	cout << "\n\n\n\n";
	
	MedianHeap myHeap3;
	
	cout << "Inserting 1 " << endl; myHeap3.insert(1);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 8 " << endl; myHeap3.insert(8);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 0 " << endl; myHeap3.insert(0);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 9 " << endl; myHeap3.insert(9);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 5 " << endl; myHeap3.insert(5);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 4 " << endl; myHeap3.insert(4);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 7 " << endl; myHeap3.insert(7);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 3 " << endl; myHeap3.insert(3);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 6 " << endl; myHeap3.insert(6);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	cout << "Inserting 2 " << endl; myHeap3.insert(2);
	cout << "Median is: " << myHeap3.findMedian() << endl;
	
	
    return 0;
}
