enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class HashTable {
	public: 
		HashTable( const int tableSize, const CollisionStrategy option );
		~HashTable();
		bool insert( const int item );
		bool remove( const int item );
		bool search( const int item, int& numProbes );
		void display();
		void analyze( int& numSuccProbes, int& numUnsuccProbes );
		void readFile( const string fileName );
	private:
		int size;
		int currentSize;
		int* items;
		CollisionStrategy strategy;
		int hash2(int itemToBeAdded ); // second hash function
		int probe( int& addr, const int item, const int search, bool& isFound); // option 1 = insertion  -1 = otherwise
		int getNumber(const string line); // gets the number to be added / removed / searched
		int getNoOfProbes(); // returns the number of probes
		int isFull(); // checks the hash table is full or not.
};
