#include <iostream>
#include <exception>
#include <string>
#include <string.h>

using namespace std;

/* This is where I'm going to put my thoughts and notes. This file is also going to be used for COP3530 class for problem 1b most likely */
/* */
template <class T>
class Deque{

public:
	T* queue;		//The array which holds the queue
	T* ph;			//A placeholder for resizing functions
	int num_elements;	//Then number of elements in the queue
	int size_of_queue;	//The capacity of the queue
	int front;		//Keeps track of the front of the queue
	int back;		//Keeps track of the back of the queue

	//Constructor
	Deque() {
		num_elements = 0;
		size_of_queue = 8;
		front = 0;
		back = 0;
		queue = new T[size_of_queue];
	}

	//Destructor
	~Deque(){
		delete[] queue;
	}

	//For when we initially fill the array
	T* grow(){
		ph = queue;
		size_of_queue = size_of_queue * 2;
		queue = new T[size_of_queue];	

		//If the back pointer is in a higher index than the front pointer,
		if(back > front){
		/*D is like some determinant or something. Its the relationship between front and the 			distance between the front and the end of the array. */
		int D = front - ph.size();
			//Set the values from the copied array ph to the resized que' from front to back.
			for(int i = back; i < ph.size() - 1; i++){
				queue[i - back] = ph[i];
			}
			for(int j = 0; j < front; j++){
				queue[j + D] = ph[j];
			}
		back = 0;
		front = ph.size() - 1;
		}
		/*Otherwise, the front will be in the higher index (Meaning that back never traversed to 			the other side of the array */
		else{
			for(int i = 0; i < ph.size() - 1; i++){
				queue[i] = ph[i];
			}
		back = 0;
		front = ph.size() - 1;
		}
	delete[] ph;
	return queue;
	}
	//For when the array reaches 1/4 the original size
	T* shrink(){
		ph = queue;
		size_of_queue = size_of_queue / 2;		
		queue = new T[size_of_queue];

		if(back > front){
			for(int i = back; i >= front; i--){
				queue[i] = ph[i];
			}
		back = 0;
		front = ph.size() - 1;
		}
		else{
			for(int i = back; i <= front; i++){
				queue[i] = ph[i];
			}
		back = 0;
		front = ph.size() - 1;
		}
	delete[] ph;
	return queue;
	}

	//Inserts the element at the front of the queue.
	void push_front(T item){
		//If the queue has no elements to begin with, the first element will be both the front and the back.
	try{
		if(queue.empty()){		
			queue[front] = item;
			front++;
			num_elements++;	
		}
		else{
			front++;
			queue[front] = item;
			num_elements++;
			if(num_elements == queue.size()){
				grow();
			}
		}
	}
	catch(bad_alloc e){
		throw e;
	}
	}

	//Inserts the the element at the back of the queue
	void push_back(T item) {
	try{
		if(queue.empty()){	
			queue[back] = item;
		}
		else{
			if(back == 0){
				back = queue.size() - 1;
				queue[back] = item;
				num_elements++;
				/* Just in case there is an item enque'd back when front is size - 1. The 					array should be resized in this case. */
				if(num_elements == queue.size()){
					grow();
				}
			}
			if(back - 1 == front){
				grow();
				enqueue_back(item);
			}
			else{
				back--;
				queue[back] = item;
				num_elements++;
			}
		}
	}
	catch(bad_alloc e){
		throw e;
	}
	}
	//Deletes the element at the front of the queue
	T pop_front() {
		try{
			queue[front].clear();
			front--;			
			num_elements--;
			if(num_elements == queue.size() / 4 && queue.size() > 8){
					shrink();
			}
		}
		catch(exception runtime_error){
			throw runtime_error;
		}
		return queue[front];
	}

	//Deletes the element at the back of the queue
	T pop_back() {
		try{
			T temp = queue[back];
			queue[back].clear();
			if(back + 1 == queue.size()){
			back = 0;
			}
			else{
			back++;
			num_elements--;
			if(num_elements == queue.size() / 4 && queue.size() > 8){
					shrink();
			}
			}
		}
		}
		catch(exception runtime_error){
			throw runtime_error;
		}
		
		return temp;
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
	/* Puts the contents of the queue from back to front into a 
	return string with each string item followed by a newline */
	string toStr() {
		//If the back pointer is in a higher index than the front pointer,
		if(back > front){
			//print from the back to the end of the queue, then
			for(int i = back; i < size_of_queue - 1; i++){
				cout << queue[i] << "\n";
			}
			//print from the beginning of the queue to the front.
			for(int j = 0; j < front; j++){
				cout << queue[j] << "\n";
			}
		}
		//Otherwise, the front will be in the higher index.
		else{
			//So, print from the back until you reach the front.
			for(int i = back; i <= front; i++){
				cout << queue[i] << "\n";
			}
		}
	}
};

