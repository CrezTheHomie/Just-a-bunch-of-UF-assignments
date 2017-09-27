#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;
int pIndex;
int buildNode(1);

struct node{
	int data;
	node* left;
	node* right;
};

int post[20],in[20],pos[20];
int ind;
/* Helper function that allocates a new node */
node* newNode(int data){
	node* n = new node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return (n);
}
// Build tree using utiltiy functions
node* buildtree(int in[], int post[], int start, int end){    
	// Base case
	//cout << "leftbound = " << start << " rightbound = " << end << "\n";
	if(start > end){
		return NULL;
 	}
	node *n = newNode(post[ind--]);
	int origP = pIndex;

	/* If this node has no children then return */
	if(start == end){
		return n;
	} 

	int m = pos[n->data];
	//cout << "pos = " << pos << "\n";
	//construct right subtree
	//cout << "right subtree\n";
	n->right = buildtree(in, post, m+1, end);
	//construct left subtree
	//cout << "\nleft subtree\n";
	//cout << "node data when constructing left subtree: " << n->data << "\n";
	n->left = buildtree(in, post, start, m-1);
		//cout << "root or subroot left is: " << n->left->data << "\n";
	return n;
}
void printLevelOrder(node *root){
	// Base Case
	if (root == NULL){return;}
 
	// Create an empty queue for level order tarversal
	queue<node *> q;
 
	// Enqueue Root and initialize height
	q.push(root);
 
	while(q.empty() == false){
		// Print front of queue and remove it from queue
		node *node = q.front();
		cout << node->data << " ";
		q.pop();
	 
	       	//Put the left child in queue
		if(node->left != NULL){
			q.push(node->left);
	 	}
		//Put the right child in queue
		if(node->right != NULL){
			q.push(node->right);
		}
	}
}   

//converts a string of ints to its integer value
int strToInt(string str){

	int num = 0;

	for(int i = 0; i < str.size(); i++) {
		num = num * 10; // move the number up a digit place
		num += str.at(i) - '0'; // ASCII math to convert the char to a number
	}

	return num;
}


int main(){
	
 // freopen("data.txt","r",stdin);
    int n,i=0;
    scanf("%d",&n);
 
    while(i<n)
    {
        scanf("%d",&post[i]);
        i++;
    }
    i=0;
    while(i<n)
    {
        scanf("%d",&in[i]);
        pos[in[i]]=i;
        i++;
    }
 
    ind=n-1;
    node *root=buildtree(in,post,0,n-1);
    printLevelOrder(root);
    cout << "\n";
	return 0;
}
