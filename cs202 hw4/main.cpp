#include "HashTable.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int tableSize = 13;
    
    cout<<"Linear Hashing"<<endl;
    HashTable table1( tableSize , LINEAR);
    table1.readFile( "input2.txt");
    cout<< endl <<"Final HashTable: "<<endl;
    table1.display();
    int numSucc, numUnsucc;
    table1.analyze( numSucc, numUnsucc);

    cout<<"Quadratic Hashing"<<endl;
    HashTable table2( tableSize , QUADRATIC);
    table2.readFile( "input2.txt");
    cout<< endl <<"Final HashTable: "<<endl;
    table2.display();
    table2.analyze( numSucc, numUnsucc);
    

    cout<<"Double Hashing"<<endl;
    HashTable table3( tableSize , DOUBLE);
    table3.readFile( "input2.txt");
    cout<< endl <<"Final HashTable: "<<endl;
    table3.display();
    table3.analyze( numSucc, numUnsucc);
    return 0;

}
