#include "HashTable.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

HashTable::HashTable( const int tableSize, const CollisionStrategy option ) { //ok
	items = new int[tableSize];
	for(int n = 0; n < tableSize; n=n+1){
		items[n] = -1; // -1 is empty -2 deleted else occupied
	}
	this->strategy = option;
	this->size = tableSize;
	this->currentSize = 0;
}

HashTable::~HashTable(){
	delete[] items;
}

bool HashTable::insert(const int item){ //ok
	int numProbes;
	if(search(item, numProbes)) {
		return false;
	}
	if(this->isFull()) return false;
	int address = item % size;
	bool isFound = true;
	if(items[address] > -1) {
		probe(address,item, item, isFound);
		if(address == item % size) return false;
	}
	currentSize = currentSize + 1;
	items[address] = item;
	return true;
}

bool HashTable::remove(const int item){
	int addr = item % size;
	int probes;
	bool isFound = true;
	if( !search(item, probes) ){
		return false; 
	}
	if( items[addr] != item )
		probe(addr, item, item, isFound);// 0 remove
	if(items[addr] > -1 ){
		items[addr] = -2; // removed
	}
	this->currentSize = this->currentSize - 1;
	return isFound;
}

bool HashTable::search(const int item, int& numProbes){
	bool isFound = 1;
	int addr = item % size;	
	if(items[addr] == -1 ) {
		numProbes = 1;
		return false; 
	}
	numProbes = probe(addr, item, item, isFound);
	return isFound;
}

void HashTable::display(){ //ok
	for(int n = 0; n < size; n++){
		cout << n <<": \t";
		if(items[n] > -1 ) {
			cout << items[n];
		}
		cout << "\n";
	}
}

void HashTable::analyze(int& numSuccProbes, int& numUnsuccProbes){
	numSuccProbes   = getNoOfProbes();
    numUnsuccProbes = 0;
    if( strategy == DOUBLE) {
    	cout << "\nSuccessful Average: " << ( (double) numSuccProbes / (double) currentSize ) << endl;
		cout << "Unsuccessful Average: -1" << endl;
        numUnsuccProbes = -1;
        return;
    }
    int  address;
    int unsuccCount = 0;
    int  totalUnsuccCount = 0;
    for( int n = 0; n <= size - 1; n++) {
        address = n;
        if( search( address, unsuccCount)) {
            while( search( address, unsuccCount) ) {
				address = size + address; 
			}
        }
        totalUnsuccCount = unsuccCount + totalUnsuccCount;
    }
    numUnsuccProbes = totalUnsuccCount;
    cout << "\nSuccessful Average: " << ( (double) numSuccProbes / (double) currentSize ) << endl;
	cout << "Unsuccessful Average: " << ( (double) totalUnsuccCount / (double) size ) << endl << endl;
}

void HashTable::readFile(const string fileName ){ //ok
	string line;
	fstream file(fileName.c_str());
	bool result = true;
	int item;
	int probeCount = 0; // for Searching
	while(getline(file,line) ){
		if(line[0] == 'I' ){
			item = getNumber(line);
			result = insert(item);
			if(!result) cout <<item<< " not inserted.\n";
			else cout << item<< " inserted.\n";
		}
		else if(line[0] == 'D' ){
			item = getNumber(line);
			result = remove(item);
			if(!result) cout <<item<< " not deleted.\n";
			else cout <<item<< " deleted.\n";
		}
		else if(line[0] == 'S') {
			item = getNumber(line);
			result = search(item, probeCount);
			if(!result) cout<<item<<" not found after "<<probeCount<<" probes.\n";
			else cout<<item<<" found after "<<probeCount<<" probes.\n";
		}
	}
}

int HashTable::hash2(int itemToBeAdded ){ //ok
	int tmp = 0;
	for(;itemToBeAdded != 0; itemToBeAdded = itemToBeAdded / 10){
		tmp = tmp*10+itemToBeAdded%10;
	}
	return tmp;
}

int HashTable::probe( int& addr, const int item, const int search, bool& isFound ){
	int probCount = 1;
	
	if(strategy == DOUBLE){
		int secondHash = hash2(item);
		while( items[addr] != search ){
			if( secondHash % size == item % size && secondHash % this->size == 0){
				if( items[addr] != search )
					isFound = false;
				break;
			}
			addr = (secondHash*probCount + ( item % size));
			addr = addr % size;
			probCount = probCount + 1;
			if( item == 0 || isFull() || items[addr] == -1 ) {
				isFound = false;
				break;
			}	
		}
	}
	
	else if(strategy == QUADRATIC){
		while(items[addr] != search ){
			addr = ((item % size) + probCount * probCount);
			addr = addr % size;
			probCount = probCount + 1;
			if( probCount > size || isFull() || items[addr] == -1 ) {
				isFound = false;
				break;
			}
			
		}
	}
	
	else if( strategy == LINEAR) {
		while( items[addr] != search ){
			probCount = probCount + 1;
			addr = (addr + 1) % size;
			if( isFull() || items[addr] == -1 ){
				isFound = false;
				break;
			}
		}
	}
	return probCount;
}

int HashTable::getNumber(const string line){ //ok
	int temp;
	int n;
    int index = 0;  
    for(n = 2; line[n] && !( line[n] == ' ' || line[n] == '\t'); n++ ){}
    index = n;
    istringstream( line.substr( 2, index - 1)) >> temp;
    return temp;
}

int HashTable::getNoOfProbes(){ //ok
	int totalProbeCount = 0;
	int probeCount = 0;
	for(int n = 0; n <= size - 1; n = n + 1){
		if(items[n] > -1) {
			search(items[n], probeCount);
			totalProbeCount = totalProbeCount + probeCount;
		}
	}
	return totalProbeCount;
}

int HashTable::isFull(){ // ok
	return (this->currentSize == this->size);
}
