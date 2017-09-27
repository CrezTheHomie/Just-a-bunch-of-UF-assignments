#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *newnode(int val)
{
    node *tmp=new node;
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
int post[100000],in[100000],pos[100000];
int ind;
node *buildtree(int st,int en)
{
    if(st>en) return NULL;
  //  printf("%d %d\n",st,en);
    node *r=newnode(post[ind--]);
    if(st==en) return r;
    int m=pos[r->data];
    r->right=buildtree(m+1,en);
    r->left=buildtree(st,m-1);
    return r;
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
int main()
{


   // freopen("data.txt","r",stdin);
    int n,i=0;
    scanf("%d",&n);
if(n<=0){return 0;}
 else{
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
    node *root=buildtree(0,n-1);
    printLevelOrder(root);
    cout << "\n";
return 0;}
}
