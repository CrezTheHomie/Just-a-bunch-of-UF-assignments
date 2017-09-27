#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std

class btree{

struct Node{
	int key;
	node* leftChild;
	node* rightChild;
};

public:
    // constructor
	btree(){
		root = NULL; // set root to NULL
		cur = NULL; // set current to NULL
	}

    // Create initial list
	void initialize(int val){

	Node *n = new Node();   // create new Node
	n->x = val;             // set value       
	n->next = NULL;         // make the node point to the next node.
	
	if(root == NULL){
		root = n;
		}
	else if(root->next == NULL && root !=NULL){
		root -> next = n;
		cur = n;
		}
	else{
		cur -> next = n;
		cur = n;
		}
	}

	void insert(int leave, int val){
		//make steps
		if(cur==root){
			for(int i= 0; i < leave-1; i++){
				cur = cur-> next;
			}
		}
		else{
			for(int i= 0; i < leave; i++){
			cur = cur-> next;
			}
		}
		//insert new value into list
		Node *n = new Node();   // create new Node
		n->x = val;             // set value       
		n->next = cur->next;    // make the node point to the next node.
		cur -> next = n;
		cur = n;
	}

        void rewind(){
                cur = root;
        }
        void next(){
                if( cur != NULL )
                        cur = cur->next;
        }
        int getValue(){
                if( cur != NULL )
                        return cur->x;
                return 0; // really we should raise exception
        }
        int hasValue(){
                return ( cur != NULL ? true : false );
        }
private:
	node *root;
};


int main() {
	string input;
	int n;
	getline(cin,input);
	return 0;
}
