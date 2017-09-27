//hashtable.h

/*	Not necessary anymore because I just copy/pasted this into the cpp file. I thought you might have a laught if I kept it in, however.	*/

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class hash{
public:
	static const int tableSize = 20;

	struct item{
		string name;
		item* next;
	};

	item* hashtable[tableSize];

	hash();
	int Hash(string key);
	void addItem(string name);
	int NumberOfItemsInBucket(int bucket);
	void printTable();
	void printItemsInBucket(int bucket);
	void findName(string name);
	void removeItem(string name);
};
