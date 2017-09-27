#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
	int data;
	node* left;
	node* right;
	node* next;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	node* node = (struct node*)
			malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
 
	return node;
}
 
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
	if (node == NULL){
		return;
	}
	// first recur on left subtree
	printPostorder(node->left);
	 
	// then recur on right subtree
	printPostorder(node->right);
	 
	// now deal with the node
	cout << node->data << " "; 
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
	if (node == NULL){
		return;
	}
	/* first recur on left child */
	printInorder(node->left);
	 
	/* then print the data of node */
	cout << node->data << " "; 
	 
	/* now recur on right child */
	printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
	if (node == NULL){
		return;
	}
	/* first print data of node */
	cout << node->data << " "; 
	 
	/* then recur on left sutree */
	printPreorder(node->left);  
	 
	/* now recur on right subtree */
	printPreorder(node->right);
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

/* Driver program to test above functions*/
int main()
{
	string input;
	int size, j, k;
	int i = 0;
	
	stringstream stream;
	cin >> j; //get the number of nodes for the tree
	if(j<=0){
		return 0;
	}
	size = (j*3); //multiply it by 3 so array can store data and left and right assignments.
	int arr[size]; //array for stored input
	while(j+1 > 0){
		//cout << "j = " << j << "\n";
		getline(cin,input);
		stream.str(input);
		while(stream >> k){
			//cout << "k: " << k << " was placed in array at: " << i << "\n";
			arr[i] = k;
			i++;
		}
		stream.clear();//clear any bits set in the stringstream
		j--;
	}

	node *root = newNode(arr[0]);
	node *cur = root;
	node *n = root;

	//cout << "for loop start \n" << "i/3 = " << i/3 << "\n";
	//create a linked list
	for(k = 1; k < size/3; k++){
		if(root->next == NULL && root !=NULL){
			n = newNode(arr[k*3]);
			root->next = n;
			cur = n;
		}
		else{
			n = newNode(arr[k*3]);
			cur -> next = n;
			cur = n;
		}
	}
	
	//assign children to nodes
	cur = root;
	j = 0;
	while(cur != NULL){
		//assign left child
		n = root;
		k = arr[(j*3)+1];
		//cout << "k = " << k << "\n";
		if(k == 0-1){
			//cout << "left pointer for node with " << cur->data << " assigned to null\n";
			cur->left = NULL;
		}
		else{
			while(n->data != arr[k*3] && n->next != NULL){
				n = n->next;
			}
			//cout << "left pointer for node with " << cur->data << " assigned to " << n->data << "\n";
			cur->left = n;
		}
		//assign right child
		n = root;
		k = arr[(j*3)+2];
		//cout << "k = " << k << "\n";
		if(k == 0-1){
			//cout << "right pointer for node with " << cur->data << " assigned to null\n";
			cur->right = NULL;
		}
		else{
			n = root;
			k = arr[(j*3)+2];
			while(n->data != arr[k*3] && n->next != NULL){
				n = n->next;
			}
			//cout << "right pointer for node with " << cur->data << " assigned to " << n->data << "\n";
			cur->right = n;
		}
		//update next line
		cur = cur->next;
		j++;
	}

	printPreorder(root); cout << "\n";
	printInorder(root);  cout << "\n";
	printPostorder(root);
	cout << "\n";
	return 0;
}
