#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <string>
#include <sstream>

/*Size of the input lists doesn't matter in the sense of being an input. 
Taking the input as a stringstream removes the need for the question "how big are my lists?"
Made a cin just so that the io would be consistent with the instructions.*/

using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
	Node *prev;
    };

// public member
public:
    // constructor
	LinkedList(){
		head = NULL; // set head to NULL
		cur = NULL; // set current to NULL
	}

    // Create initial list
	void initialize(int val){

	Node *n = new Node();   // create new Node
	n->x = val;             // set value       
	n->next = NULL;         // make the node point to the next node.
	
	if(head == NULL){
		head = n;
		}
	else if(head->next == NULL && head !=NULL){
		head -> next = n;
		cur = n;
		}
	else{
		cur -> next = n;
		cur = n;
		}
	}

	void insert(int leave, int val){
		//make steps
		if(cur==head){
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
                cur = head;
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
 
// private member
private:
    Node *head; // the pointer to the first Node
    Node *cur;
};
int main() {
	
	LinkedList list;
	int N; //size of list. In my case its rather unnecessary
	int leave; //# of interleave steps
	cin >> N; //Get size input

	//Initialize linkedlist with size 
	string name;
	getline (cin, name); //extra getline since it behaves when its here. Its a quickfix, but hey it works.

	string input;
	getline (cin,input);
	stringstream stream;
	stream.str(input);
	int n;
 	while(stream >> n) {
		list.initialize(n);
	}	
		stream.str("");
		stream.clear();
	
	list.rewind();
	
	//get # of extra lists
	int xtra;
	cin >> xtra;
	for(int j = 0; j < xtra; j++){
		//get the step
		cin >> leave;
		cin >> N;
		//get the elements
		getline (cin, name); //extra getline since it behaves when its here
		getline (cin,input);
		stream.str(input);
		stream.clear();
		while(stream >> n) {
			list.insert(leave, n);
		}
		list.rewind();
	}
	list.rewind();
	//print output
	while( list.hasValue()){
                cout << list.getValue() << " ";
                list.next();
	        }
	cout << "\n";
	
	return 0;
}
