#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class btree{

	struct Node{
		int key;
		Node* left;
		Node* right;
	};

public:
	btree(){
		root = NULL;
	}
	
node* createNode(int val){
	Node *n = new Node();   // create new Node
	n->key = val;             // set value       
	n->left = NULL;         // initially created nodes have 
	n->right = NULL;
	
	if(root == NULL){
		root = n;
		}
	else if(head->left == NULL && head !=NULL){
		head -> left = n;
		cur = n;
		}
	else{
		cur -> next = n;
		cur = n;
		}
	}

}

private:
	Node* root;
};


//converts a string of ints to its integer value
int strToInt(string str){

	int num = 0;
	int placeholder;

	for(int i = 0; i < str.size(); i++) {
		num = num * 10;
		num += str.at(i) - '0';
	}

	return num;
}

int main() {
	string input;
	int j;
	int k;
	int i = 0;
	int size;
	btree Tree; 

	stringstream stream;
	getline(cin,input);
	j = strToInt(input); //get the number of nodes for the tree
	size = (j*3); //multiply it by 3 so array can store data and left and right assignments.
	int arr[size]; //array for stored input
	while(j > 0){
		getline(cin,input);
		stream.str(input);
		k = 0;
		while(stream >> k){
			cout << "k: " << k << " was placed in array at: " << i << "\n";
			arr[i] = k;
			i++;
		}
		stream.clear();//clear any bits set in the stringstream
		stream.str(std::string()); //resets the stream variable
		j--;
	}
	Node *n = new Node();   // create new Node
	n->key = arr[i-2];             // set value     
	arr[i-2] = &n;
	cout << arr[i-2] << "\n";

	/* Print the array
	for(int j = 0; j < size; j++){
		cout <<  tree[j] << " ";
	}
	cout << "\n";*/

	

	return 0;
}
