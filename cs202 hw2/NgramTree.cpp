/**
* Title: Trees
* Author: Alper Mumcular
* ID: 21902740
* Assignment: 2
* Description: NgramTree class implementation
*/
#include <string>
#include <fstream>
#include "NgramTree.h"
#include <iostream>
using namespace std;

NgramTree::NgramTree():root(NULL) {

}

NgramTree::~NgramTree() {
		//destroyTree(root);
}

void NgramTree::destroyTree(NgramNode *& treePtr) {

		if (treePtr != NULL){
			destroyTree(treePtr->leftChildPtr);
			destroyTree(treePtr->rightChildPtr);
			delete treePtr;
			treePtr = NULL;
		}
}

void NgramTree::addNgram(string ngram) {
		insertItem(root, ngram);
}

int NgramTree::getTotalNgramCount() {
	return getNgram(root);
}

bool NgramTree::isComplete(){
	int count = getNgram(root);
	return complete(count, root, 0);
}

bool NgramTree::isFull(){
	return full(root);
}

void NgramTree::generateTree(string fileName, int n){
	size = n;
	fstream txtFile;
	string word;
	word = "";
	int length;
	length = 0;
	txtFile.open(fileName.c_str());
	
	for(;txtFile>>word;){
		length = word.length();
		if(length < n )
			continue;
		else{
			length = length - n + 1;
			int x = 0;
			while(x<length){
				addNgram(word.substr(x,n));
				x++;
			}
		}
	}
	txtFile.close();
}

ostream& operator<<( ostream& out, NgramTree tree ){
	tree.print(tree.root);
	return out;
}

void NgramTree::insertItem(NgramNode *& treePtr, string newItem) {
		if (treePtr == NULL) { 
			treePtr = new NgramNode(newItem);
		}
		else if (newItem.compare(treePtr->item) < 0) 
			insertItem(treePtr->leftChildPtr, newItem);
		else if (newItem.compare(treePtr->item) > 0) 
			insertItem(treePtr->rightChildPtr, newItem);
		else 
			(treePtr->count)++;	
}

int NgramTree::getNgram(NgramNode *& treePtr){
	if(treePtr == NULL){
		return 0;
	}
	return 1+getNgram(treePtr->leftChildPtr)+getNgram(treePtr->rightChildPtr);
}

bool NgramTree::complete(int count, NgramNode *&treePtr, int index){
	if(treePtr == NULL)
		return true;
	else if(count <= index){
		return false;
	}
	return complete(count,treePtr->leftChildPtr,1+2*index) && complete(count,treePtr->rightChildPtr,2+2*index);
}

bool NgramTree::full(NgramNode *&treePtr){
	if(treePtr == NULL)
		return true;
	else if(treePtr->leftChildPtr!= NULL && treePtr ->rightChildPtr==NULL)
		return false;
	else if(treePtr->leftChildPtr==NULL && treePtr->rightChildPtr!=NULL)
		return false;
	return full(treePtr->leftChildPtr) && full(treePtr-> rightChildPtr);
}

void NgramTree::print(NgramNode *& treePtr){
	if(treePtr == NULL)
		return;
	else {
		print(treePtr->leftChildPtr);
		cout << "\"" << treePtr->item << "\" appears " << treePtr->count << " time(s)\n";
		print(treePtr->rightChildPtr);	
	}
}
