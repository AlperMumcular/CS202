/**
* Title: Trees
* Author: Alper Mumcular
* ID: 21902740
* Assignment: 2
* Description: Header file for NgramNode (additional class) 
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef NGRAMNODE__H
#define NGRAMODE__H
class NgramNode {
private:
	NgramNode();
	NgramNode(string newItem);
	
	std::string item;
	int count;
	NgramNode* leftChildPtr;
	NgramNode* rightChildPtr;
	
	friend class NgramTree; // to access private part
};
#endif
