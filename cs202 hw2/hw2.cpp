/**
* Title: Trees
* Author: Alper Mumcular
* ID: 21902740
* Assignment: 2
* Description: Main class (Taken from hw2.pdf) 
*/
// hw2.cpp 
#include <iostream>
#include <string>
using namespace std; 
#include <stdlib.h>
#include "NgramTree.h"
int main( int argc, char **argv ) { 
NgramTree tree;
string fileName( argv[1] ); 
int n = atoi( argv[2] );
tree.generateTree( fileName, n );
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl; 
cout << tree << endl;
cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No");
// Before insertion of new n-grams
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
tree.addNgram( "samp" ); 
tree.addNgram( "samp" ); 
tree.addNgram( "zinc" ); 
tree.addNgram( "aatt" );
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl; 
cout << tree << endl;
cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
return 0;
}
