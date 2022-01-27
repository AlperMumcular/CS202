/**
* Title: Trees
* Author: Alper Mumcular
* ID: 21902740
* Assignment: 2
* Description: Header file for NgramTree
*/
#include "NgramNode.h"
#include <iostream>
using namespace std;
#ifndef NGRAMTREE__H
#define NGRAMTREE__H
// NgramTree.h
	class NgramTree { 
	public:
		NgramTree();
		~NgramTree();
		void addNgram( string ngram ); int getTotalNgramCount(); bool isComplete();
		bool isFull();
		void generateTree( string fileName, int n );
	private:
	int size;
	NgramNode *root;
	void destroyTree( NgramNode *& treePtr);
	void insertItem(NgramNode *& treePtr, string newItem);
	int getNgram(NgramNode *& treePtr);
	bool complete(int count, NgramNode *&treePtr, int index);
	bool full(NgramNode *&treePtr);
	void print(NgramNode *& treePtr);
	friend ostream& operator<<( ostream& out, NgramTree tree );
}; 
#endif
