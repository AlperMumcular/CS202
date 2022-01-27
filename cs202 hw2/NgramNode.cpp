/**
* Title: Trees
* Author: Alper Mumcular
* ID: 21902740
* Assignment: 2
* Description: NgramNode implementation (additional class) 
*/
#include "NgramNode.h"
#include <string>
#include <iostream>
using namespace std;

NgramNode::NgramNode(){
	item = "empty!";
	count = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

NgramNode::NgramNode(string newItem){
	item = newItem;
	count = 1;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}




