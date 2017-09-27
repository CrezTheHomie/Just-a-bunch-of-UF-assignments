#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

/* This is where I'm going to put my thoughts and notes. This file is also going to be used for COP3530 class for problem 1a most likely */
/* */
template <typename T>
class Deque{

public:
	T* queue;		//The array which holds the queue
	int num_elements;	//Then number of elements in the queue
	int size_of_queue;	//The capacity of the queue
	int front;		//Keeps track of the front of the queue
	int back;		//Keeps track of the back of the queue

	//Constructor
	Deque() {
		num_elements = 0;
		size_of_queue = 8;
		front = -1;
		back = -1;
		queue = new string[size_of_queue];
	}

//Destructor
	~Deque(){
		delete[] queue;
	}

	//Inserts the element at the front of the queue.
	void enqueue_front(T item){
		//If the queue has no elements to begin with, the first element will be both the front and the back.
		if(empty()){	
			front++;
			back++;		
			//cout << "front = " << front << endl;
			//cout << "back = " << back << endl;
			queue[front] = item;
			
		}
		else if(front >= 0){
			//cout << "I'm in else\n";
			front++;
			queue[front] = item;
			//cout << "front = " << front << endl;
			//cout << "back = " << back << endl;
			
		}
		
		num_elements++;

		//cout << "item = " << item << endl;
	}

	//Inserts the the element at the back of the queue
	void enqueue_back(T item) {
		if(empty()){	
			front++;
			back++;
			//cout << "front: " << front << endl;
			//cout << "back: " << back << endl;
			queue[back] = item;
		}
		if(back == 0){
			//cout << "I'm in else\n";
			front++;
			//cout << "front = " << front << endl;
			//cout << "back = " << back << endl;
			queue[back+1] = queue[back];
			queue[back] = item;
			
			//cout << "I'm still in else\n";
		}

		/*if(num_elements = 8){
		resize();
		}*/

		num_elements++;
		
	}

	//Deletes the element at the front of the queue
	string pop_front() {
		queue[front].clear();
		front--;
		num_elements--;
		return *(queue + front);
		
	}

	//Deletes the element at the back of the queue
	string pop_back() {
		
		for(int i = 0; i < num_elements; i++){
			queue[i] = queue[i+1];
		} 
		queue[front].clear();
		front--;
		num_elements--;
		return *(queue - back);
	}

	//Returns the number of elements in the queue
	int size() {
		return size_of_queue;
	}

	//Tells whether the queue is empty or not.
	bool empty() {
		if(num_elements = 0){
			return true;
		}
		else{
			return false;
		}
	}
	/* Puts the contents of the queue from front to back into a 
	return string with each string item followed by a newline */
	string toStr() {
		for(int i=0; i < num_elements; i++){
			cout << queue[i] << "\n";
		}
	}
	
};

