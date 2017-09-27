//possible errors...
//	unbalanced parentheses: numleft =/= numright
//	Division by zero
//	bad parenthesis )2+4(
//	bad log domain

#include <stack>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <math.h>
#define MAX 20
using namespace std;

/* Your code should input a string from user, which contains the expression he/she
wants to compute. Then, your code should parse the input, detect the operators and
their argument(s), and return the result. For simplicity, you can assume that the input
expression is fully parenthesized (see below for more details). It is expected that you use
the stack data structure to pass arguments and compute the result.

example input ((6 + (4 * 12))/6) */


 class myStack{

	private:
	int arr[MAX];
	int top;

	public:
		myStack(){
			top = -1;
		}

		void push(int newElement){
			top++;
			if(top < MAX){
				arr[top] = newElement;
			}
			else{
			cout << "stack is full" << endl; 
			top--;
			}
		}

		int pop(){
			if(top == -1) {
				cout << "stack is empty, nothing to pop" << endl;
				return NULL;
			}
			else{
			int data = arr[top];
			arr[top] = NULL;
			top--;
			return data;
			}
		}
};

string findOps(string str){
	
}
//"(6 + (4 * 12))"
string removeSpaces(string str){

	string	space = " ";
	int 	ph = str.find(" ");


	if(str.find(space) !=  string::npos){
		while(str.find(space) !=  string::npos && str.find(space) <= str.size()) {
			
			str.erase(str.find(space), space.length());
			//string	stuff = str.at(str.find(space));
				//if(stuff.compare(space) != 0){break;}
			cout << str.find(space) << endl << str << endl;
   		}
	cout << "\n" << str << endl;
	return str;
   	}
   	else cout << str << "uh oh" << endl;

}

int strToInt(string str){

	int num = 0;
	int placeholder;
	int str_size = str.size();

	for(int i = 0; i < str_size; i++) {
		num = num * 10;
		num += str.at(i) - '0';
		cout << num << " is maybe?" << endl;
	}


	return num;
}

string findOrder(string str){
	
	str = removeSpaces(str);
	//cout << "\n" << str << endl;
	//going to try and find () expressions. ((6 + (4 * 12))/6)
	
	
	char* 	numsAndOps = new char[str.size() + 1];
		//numsAndOps[str.size()] = 0;
		strncpy(numsAndOps, str.c_str(),str.size());
		//cout << numsAndOps[0] << numsAndOps[1] << numsAndOps[2] << numsAndOps[11] << endl;

	int	numP = 0;
	char	openPar = '(';
	string	openP   = "(";
	string 	closedP  = ")";
	int	placeOpenP = 0;
	int	placeClosedP = 0;


/*What do I want? to parse by yfinding the ( parenthesis and getting the strings from the first one to the second one. What are the problems? */

	//trying (6+(4*12)) first


	/*for(int i = 0; i < str.size() + 1; i++){
		if(str.at(i) == openPar){
			numP++;
			cout << "BOOM\n";
		}
		cout << numP << endl;
	}*/

	//ph is a placeholder
	int ph = 0;
	//hp is the  converse of ph
	int hp = str.size();
	string word;
	int arraySize = str.size() + 1;

	while(ph != hp){
	if(numsAndOps[ph] == '('){
		for(int i = 0; i < arraySize - 2; i++){
			numsAndOps[i] = numsAndOps [i+1];
			cout << numsAndOps[i];
		}
	cout << endl;
	}
		if(numsAndOps[ph] != ')'){
			word = str.substr(0, ph + 1);
			ph++;
			cout << "ph: " << word << endl << numsAndOps[ph] << endl;
		}
		if(numsAndOps[hp - 1] != '('){

			word = str.substr(hp-1,str.size());
			hp--;
			cout << "hp: " << word << endl;
		}
		
	}
	while((ph = str.find(closedP)) !=  string::npos) {
		word = str.substr(ph, str.size());
		cout << word << endl;
		//it looked weird to have space.length() when a ( is 1 unit long. Hence, the ph + 1.
		str.erase(ph - 1, string::npos);
	}
	word = str.substr(0,str.size());
	cout << word << endl;
	return word;

//if is not parenthesis

	/*while(str.at(ph+1) != str.find(")")){
		if(str.at(ph) != str.at(ph+1)){	
		
			cout << "HELP ME\n";
			ph++;
			numsAndOps = str.substr(ph,ph+1);
			cout << numsAndOps << endl;
			//findOps(numsAndOps);
			str.erase(0, ph);
			cout << str << endl;	
		}
	}*/	

}




  
/* I don't think I want this anymore
string seperate(string str){
	//ph is a placeholder
	int ph = 0;
	string space = " ";
	string word;

	while((ph = str.find(space)) !=  string::npos) {
		word = str.substr(0, ph);
		cout << word << endl;
		//it looked weird to have space.length() when a space is 1 unit long. Hence, the ph + 1.
		str.erase(0, ph + 1);
	}
	word = str.substr(0,str.size());
	return word;
}*/
/*
bool balParenthesis(string str){
	//if numb left = num right and num right = num left. && )2+4(
	int     ph = 0;
	char	openP   = '(';
	char 	closedP  = ')';
	int	numOpenP = 0;
	int	numClosedP  = 0;

	for(int i = 0; i < str.size(); i++){
		if(str.at(i).compare(leftP) == 0){
			numLeftP++;
		}	
		if(str.at(i).compare(rightP) == 0){
			numRightP++;
		}
	}
	try{
		if(numLeftP == numRightP && numRightP == numLeftP){
		return true;
		}
		else if(numLeftP != numRightP || numRightP != numLeftP){
		throw 346;
		}
	}
	catch(int e){
	cout << "Error: Unbalanced parenthesis!!!" << endl;
	}
}*/

bool divByZero(){
	/* int numerator;
	   int denominator;
	   if(denominator = 0){
		throw 12356;
	   }
	   catch(int e) {
	   cout << "Error: Div by 0" << endl;
	   }
	   else return TRUE;
   */
}


char* getOp(char *opper){
	char* op = opper;
	return op;
	cout << "you have reached opper " << op << endl;
	/*if(op == "+"){
		return '+';
	}
	else if(op == "-"){
		return '-';
	}
	else if(op == "*"){
		return '*';
	}
	else if(op == "/"){
		return '/';
	}
	//sin
	else if(op == "s"){
		return 's';
	}
	//cos
	else if(op == "c"){
		return 'c';
	}	
	//sqrt
	else if(op == "q"){
		return 'q';
	}
	//log
	else if(op == "l"){
		return 'l';
	}*/
}


/*int math(int number, string operation){
	
}*/

int main(){
	//string n;
	//cout << "Please enter the expression: " << endl;
	//cin >> n;
	//string expression = n;
	myStack awesome;
	stack<string> ops;
        //balParentheses(expression);
	findOrder("(6 + (4 * 12) + 6)");

	/*awesome.push(10);
	cout << "10 is pushed" << endl;
	awesome.push(2);
	cout << "2 is pushed" << endl;
	awesome.push(5);
	cout << "5 is pushed" << endl;

	cout << awesome.pop() << " was popppped\n";
	cout << awesome.pop() << " was popppped\n";
	cout << awesome.pop() << " was popppped\n";
	cout << awesome.pop() << " was popppped\n";

	cout << strToInt("12345") << endl;
	cout << seperate("This is a sample sentence") << endl;

	cout << "The result is: " << endl;*/

	return 0;
}
