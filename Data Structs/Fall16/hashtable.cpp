//hashtable.cpp

#include <string>
#include <iostream>
#include <cstdlib>

 /*	I figured this out after I was done coding everything but I originally planned on having a hashtable header, but I mispelled the name I used for the header file (hastable.h) and it made me rage. So, I put everything into one big file... Oops.	*/
#include "hashtable.h" //Certainly not hastable.h

using namespace std;

class hash{
public:
	static const int tableSize = 20; //Const table size because chaining via linked lists.

	//Item is the element that takes up a space in the hashtable.
	struct item{
		string name;
		item* next;
	};

	item* hashtable[tableSize];

	hash();
	int Hash(string key);
	void addItem(string name);
	/*int NumberOfItemsInBucket(int bucket);
	void printTable();	I did some extra stuff because it helped debugging and it was fun.
	void printItemsInBucket(int bucket);*/
	void findName(string name);
	void removeItem(string name);
};

//Initialize the array of linked lists.
hash::hash(){
	for(int i = 0; i < tableSize; i++){
		hashtable[i] = new item;
		hashtable[i]->name = "empty";
		hashtable[i]->next = NULL;
	}
}

//Add item function only takes a name.
void hash::addItem(string name){

	//Figure out which bucket to put the name in by using the hash function.
	int bucket = Hash(name);

	//If the bucket is empty
	if(hashtable[bucket]->name == "empty"){
		//The first element becomes the name.
		hashtable[bucket]->name = name;
	}
	else{
		//Create a new item
		item* Ptr = hashtable[bucket];
		item* n = new item;
		n->name = name;
		n->next = NULL;
		//Traverse the list until you get to the end
		while(Ptr->next != NULL){
			Ptr = Ptr->next;
		}
		//Set the end to point to the new item
		Ptr->next = n;
	}
}
/*	Not a function that was asked for in the project.
int hash::NumberOfItemsInBucket(int bucket){
	int count = 0;
	//If we haven't put anything in the bucket
	if(hashtable[bucket]->name == "empty"){
		return count;
	}
	else{
		count++;
		item* Ptr = hashtable[bucket];
		while(Ptr->next != NULL){
			count++;
			Ptr = Ptr->next;
		}
	}
}
	Also not a function asked for.
void hash::printTable(){
	int number;
	for(int i = 0; i < tableSize; i++){
		number = NumberOfItemsInBucket(i);
		cout << "----------------\n";
		cout << "bucket = " << i << endl;
		cout << hashtable[i]->name << endl;
		cout << "#number of items  = " << number << endl; 
		cout << "----------------\n";
	}
}
	Also also not a function asked for.
void PrintItemsInBucket(int bucket){
	item* Ptr = hashtable[bucket];

	if(Ptr->name == "empty"){
		cout << "bucket = " << bucket << " is empty\n";
	}
	else{
		cout << "bucket = " << bucket << "contains the following items\n";

		while(Ptr != NULL){
			cout << "----------------\n";
			cout << Ptr->name << endl;
			cout << "----------------\n";
			Ptr = Ptr->next;
		}
	}
}*/

//Find the name inputted by the user.
void hash::findName(string name){
	//figure out which bucket to look in.
	int bucket = Hash(name);

	bool foundName = false;
	item* Ptr = hashtable[bucket];

	//Search each link until you get to the end of the linked list.
	while(Ptr != NULL){
		if(Ptr->name == name){
			//Hey we found the name in the bucket it was supposed ot be in! Wow!
			foundName = true;
		}
		Ptr = Ptr->next;
	}
	//Print out results of find name. Could have returned a string but this is faster and does the same thing.
	if(foundName==true){
		cout << "Yes" << endl;
	}
	else{
		cout << "No\n";
	}
}

/*	Secret remove item function that you probably won't even know exists until you read this comment. <Inserts Mindblown.gif here>	*/
void hash::removeItem(string name){
	int bucket = Hash(name);

	item* delPtr;
	item* p1;
	item* p2;

	//bucket is empty
	if(hashtable[bucket]->name == "empty"){
		cout << name << " was not found in the hashtable" << endl;
	}

	//first item is a match and is the only item in bucket
	else if(hashtable[bucket]->name == name && hashtable[bucket]->next == NULL){
		cout << hashtable[bucket]->name << " was removed";
		hashtable[bucket]->name = "empty";
	}

	//first item is a match, but more than 1 item in bucket
	else if(hashtable[bucket]->name == name){
		delPtr = hashtable[bucket];
		hashtable[bucket] = hashtable[bucket]->next;
		delete delPtr;
		cout << name << " was removed fron the hastable" << endl;
	}

	//bucket contains items but first item is not a match
	else{
		p1 = hashtable[bucket]->next;
		p2 = hashtable[bucket];

		while(p1 != NULL && p1->name != name){
			p2 = p1;
			p1 = p1-> next;
		}
		//no match found
		if(p1 == NULL){
			cout << name << " was not found in the hashtable." << endl;
		}
		//match found and match gets deleted
		else{
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delPtr;
			cout << name << " was removed fron the hastable" << endl;
		}
	}
}

//Simple hash function
int hash::Hash(string key){
	int hash = 0;
	int bucket;

	/*	Take the ascii values of the characters that make up the string and add them together	*/
	for(int i = 0; i < key.length(); i++){
		hash += (int)key[i];
		//cout << "hash = " << hash << endl;
	}

	//Mod the hash by the table size.
	bucket = hash % tableSize;
	return bucket;
}

/*	Menu is pretty self explanatory... but it isn't needed and I don't want points taken away because its not 'the same I/O'. At least it was helpful when running test cases.	*/
char menu(){
	char choice;

	/*cout<< "\nMENU" << endl;
	cout << "0. Exit.\n";
	cout << "1. Add name.\n";
	cout << "2. Find a name.\n";
	cout << "3. Remove a poor sap from the table of awesomeness.\n";*/


	cin >> choice; 
	return choice;
}


int main(){
	
	hash hashTable;	//Create a hashtable.
	string name;	//Name to be inputted by user.
	char choice;	/*	Argument input. Both name and choice kinda replace the (argc, argv), but I 					like it this way more.	*/

	do {
		choice = menu();

		switch(choice) {
			case '1':	//cout << "\nPlease enter a name. ";
					cin >> name; 
					
					hashTable.addItem(name);
					break;

			case '2': 	//cout << "\nWho you lookin' for Willis?: ";
					cin >> name;
					hashTable.findName(name);
					break; 

			case '3': 	//cout << "\nWho has been voted off the island?: ";
					cin >> name;

					hashTable.removeItem(name);
					break;		
			
			//default: cout<< "\nRussian say: 'Have nice day'.\n";
		}

	} while (choice != '0');

	return 0;
}
