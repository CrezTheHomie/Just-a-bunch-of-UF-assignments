#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

using namespace std;


//Parameters of the Node called "tree"
struct tree {
	int size;
	string name;
	tree *next;
	tree *previous;
};

bool isEmpty(tree *root) {
	if (root == NULL) {
		return true;
	} 
	else {
		return false;
	}
}
//Menu is pretty self explanatory...
char menu(){
	char userChoice;

	cout<< "\nMENU" <<endl;
	cout << "1. Add program.\n";
	cout << "2. Remove program.\n";
	cout << "3. Fragmentation.\n";
	cout << "4. Show the List.\n";
	cout << "5. Exit.\n";

	cin >> userChoice; 
	return userChoice;
}






 	char findFit(){
	char fit;

	cout<< "\nWould you like Best Fit, or Worst fit?" <<endl;
	cout << "1. Best Fit.\n";
	cout << "2. Worst Fit.\n";
	cin >> fit; 
	return fit; 
} 
	void insertFit(page *&root, page *&last, page* &previous, page* &math, int size, string name, int fitfinal ){
	if (fitfinal == 1) {
		bestFit(root, last, previous, size, name);
	} 
	else if (fitfinal ==2) {
		worstFit(root, last, previous, size, name);
		page *temp = new page;
		temp -> name = name;
		temp -> size = size;
		temp -> next = math ->next;
		temp -> previous = math -> next -> previous;

		for(int i=0; i>= size; i++){
			insert(root, last, previous, size, name);
		}
	}

	else if (last -> name != "Free") {
			last = last -> previous;
			insert (root, last, last->previous, size, name);
		}

}
void insertAsFirstElement(tree *&root, tree* &last, tree* &previous,  int size, string name){
	tree *temp = new tree;
	temp -> size = size;
	temp -> name = name;
	temp -> next = NULL;
	temp -> previous = NULL;
	root = temp;
	last = temp;

}
void insertFreeSpace(tree *&root, tree *&last, tree* &previous, int size, string name){
	if (isEmpty(root)) {
		insertAsFirstElement(root, last, previous, size, name);
	} else { 
		tree *temp = new tree;
		temp -> name = name;
		temp -> size = size;
		temp -> next = NULL;
		last -> next = temp;
		temp -> previous = last;
		last = temp;
	}

}
//set last was needed because last got confused when more than one thing was added into the list. Set last makes it so that last starts as the last element.
void setLast(tree* &root, tree* &last) {
	if (root -> next == NULL) {
		last = root;
	} else {
		setLast(root ->next, last);
	}
}
void insert(tree *&root, tree *&last, tree* &previous, int size, string name){
	//If the tree has no roots,
	int Match(char c)
    {
        if(cin.peek()==c) {
            cin>>c;
            return 1;
        } else
        {
            cout << "Syntax Error! " << (char)cin.peek()<<endl;
            cin.ignore();
            return 0;
        }
    }

    void MatchOp()
    {
        if(cin.peek()=='+') 
            Match('+');
        else if(cin.peek()=='-')
            Match('-');
        else
        {
            cout << "invalid Operation: " << (char)cin.peek()<<endl;
            cin.ignore();
        }
    }

    void Exp()
    {   static int openParenthesis = 0; 
        static int closeParenthesis = 0;  
        if(cin.peek()!='\n')
            if(cin.peek()=='(')
            {
                if (Match('(') == 1) {
                    openParenthesis += 1;
                }
                Exp();MatchOp();Exp();
                if (Match(')') == 1) {
                    closeParenthesis -= 1;
                }
            }
            else if(isdigit(cin.peek()))
            {   
                if (openParenthesis-closeParenthesis>0) {
                    cout << "Syntax Error! " << (char)cin.peek()<<endl;
                    cin.ignore();               
                } else {
                    while(isdigit(cin.peek()))
                    { cout<<(char)cin.peek();
                    Match(cin.peek());  
                    }
                }   
            }
            else 
            {
                cout << "Syntax Error!" << (char)cin.peek()<<endl;
                cin.ignore();
            }
    }



		if (last -> name != "Free") {
			if (a < mina) {
				mina = a;
				a = 0;
				if (mina >= size) {
					gooda = mina;
					page* math = new page;
					math -> size = 0;
					math -> name = "math";
					math -> next = last;
					math -> previous = NULL;
				}
			}
			cout <<"pretty much over";
			last = last -> previous;
			cout <<"it really is over";
		}
		else if (last == root) {
			 if(mina = 32) {
					gooda = mina;
					page* math = new page;
					math -> size = 0;
					math -> name = "math";
					math -> next = last;
					math -> previous = NULL;
				}
					
		}
	}while (last != root);
}

void looseFit(page* &root, page* &last, page* &previous, int size, string name) {
	int a = 1;
	int maxa = 0;
	do {
		if(last -> name == "Free") {
			a += 1;
			if (last == root) {
				if (a == 32) {
					page* math = new page;
					math -> size = 0;
					math -> name = "math";
					math -> next = last;
					math -> previous = NULL;
					cout << math -> next -> name;
				}
			}
			last = last -> previous;
			
		} 
		else if (last -> name != "Free") {
			if (a > maxa) {
				maxa = a;
				a = 0;
				page* math = new page;
				math -> size = 0;
				math -> name = "math";
				math -> next = last;
				math -> previous = NULL;
			}
			last = last -> previous;	
		}
		 
	} while (last != root);
}

int main() {

	tree *root = NULL;
	tree *last = NULL;
	tree *previous = NULL;
	tree *math = NULL;
	char userChoice;
	int size;
	int fragments;
	char fit;
	int fitness;
	string name;
	
	name = "Free";
		size = 4;
		for (int i=1; i<=32; i++) {
			insertFreeSpace (root, last, previous, size, name);
		}

		fit = findFit();
	do {
		switch(fit) {
			case '1': cout<< "Best fit." << "\n";
				fitness = 1;
				break;
			case '2': cout<< "Wrost fit." << "\n";
				fitness = 2;
				break;
			default: cout << "Pick one of the two choices." << "\n";
		}
	} while (fitness == 0); 
	do {
		
		userChoice = menu();

		switch(userChoice) {
			case '1':cout << "Please enter the name of your program: ";
					cin >> name; 
					cout << "Please tell me the size of the program (KB): ";
					cin >> size;
					setLast(root, last);
					insert (root, last, previous, size, name);
					break;

			case '2': cout << "Which program are you going to kill? ";
					cin >> name;
					if (name == "Free") {
						cout << "\n" << "You aren't allowed to just delete the free spaces." << "\n";
						break;
						}
					setLast(root, last);
					remove (root, last, previous, size, name);
					cout << "Program terminated." << size << " KBs freed" << "\n" 
					break; 

			case '3': fragmentation(root);
					break;

			case '4': print(root);
					break;		

			default: cout<< "System exit.\n";
		}

	} while (userChoice != '5');
	return 0;
}
