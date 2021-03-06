//possible errors...
//	unbalanced parentheses: numleft =/= numright
//	Division by zero
//	bad parenthesis )2+4(
//	bad log domain

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <math.h>
#define MAX 20
using namespace std;


/* This calculator can handle simple mathematical operations, but does not handle fractions, negative values, or zero. It rounds up fractional values, and throws errors for the other two. */


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

//check to see if a character in the converted char[] is a variable 
bool isOp(char x){

	if(x == '+'){
		return true;
	}
	else if(x == '-'){
		return true;
	}
	else if(x == '*'){
		return true;
	}
	else if(x == '/'){
		return true;
	}
	//sin
	else if(x == 's'){
		return true;
	}
	//cos
	else if(x == 'c'){
		return true;
	}	
	//sqrt
	else if(x == 'q'){
		return true;
	}
	//log
	else if(x == 'l'){
		return true;
	}
	else{return false;}
}


//It removes spaces so that the math is always correct and spaces don't mess anything up on accident.
string removeSpaces(string str){

	string	space = " ";
	int 	ph = str.find(" ");


	if(str.find(space) !=  string::npos){
		while(str.find(space) !=  string::npos && str.find(space) <= str.size()) {
			
			str.erase(str.find(space), space.length());
			//string	stuff = str.at(str.find(space));
				//if(stuff.compare(space) != 0){break;}
   		}
	return str;
   	}
   	else{
	return str;
	}
}
//converts sqrt, log, sin, and cos into q l s and c (respectilvely) for easier coding.
string convertGrossOps(string str){
	int sq = str.find("sqrt");
	int s = str.find("sin");
	int c = str.find("cos");
	int l = str.find("log");
	if(str.find("sqrt") != string::npos){
		while(str.find("sqrt") != string::npos){
			str.erase(sq, 4);
			str.insert(sq, "q");
		}
	}
	if(str.find("sin") != string::npos){
		while(str.find("sin") != string::npos){
			str.erase(s + 1, 2);
		}
	}
	if(str.find("cos") != string::npos){
		while(str.find("cos") != string::npos){
			str.erase(c + 1, 2);
		}
	}
	if(str.find("log") != string::npos){
		while(str.find("log") != string::npos){
			str.erase(l + 1, 2);
		}
	}
	return str;
}

//checks to see if the parenthesis are balanced
bool parenthCheck(string str){

	char* 	strng = new char[str.size() + 1];
		strncpy(strng, str.c_str(),str.size());

	/*this is my way to convert the strings I input to char[]'s. I decided that it was 
	easier to implement many of my functions using characters over strings because I could compare
	different characters and not str.at(int)'s*/

	
	int openP   = 0;
	int closedP = 0;
	for(unsigned i = 0; i < str.length(); i++) {
		if(strng[i] == '('){
			openP++;
		}
		if(strng[i] == ')'){
			closedP++;
		}
	}
	if(openP == closedP && openP != 0 && closedP != 0){
	return true;
	}

	//if there are literally no parnetheses
	else if(openP == 0 || closedP == 0){
	cout << "Error: You told me there would be parentheses!\n"; 
	std::exit(EXIT_FAILURE);
	}
	//if unbalanced
	else if(openP != closedP) {
	cout << "Error: Unbalanced parentheses.   Executing order 65. Call off order 66." << endl;
	std::exit(EXIT_FAILURE);
	}
}


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

//does the opposite of the above
string intToStr(int n){
	string str;
	stringstream ss;
	ss << n;
	str = ss.str();
	return str;
	
}

//stacks the elements of the mathematical expression one by one.
void startStacking(string str){
	stack<string> input;
	input.push(str);
}

//math function
double doMath(int number, int numbertwo, string x){
	int ans;
	if(x == "+"){
		ans = number + numbertwo;
		return ans;
	}
	else if(x == "-"){
		if(number > numbertwo){
		ans = number - numbertwo;
		return ans;
		}
		if(number == numbertwo){
		cout << "The result is: 0\n";
		std::exit(EXIT_FAILURE);
		}
		if(number < numbertwo){
		cout << "I'm just a baby program. I don't understand negative numbers.\n";
		std::exit(EXIT_FAILURE);
		}
	}
	else if(x == "*"){
		ans = number * numbertwo;
		return ans;
	}
	else if(x == "/"){
		if(numbertwo != 0){
			ans = number / numbertwo;
			return ans;
		}
		else {
			cout << "Error: Dividing by zero. Mission failed.\n";
			std::exit(EXIT_FAILURE);
		}
	}	

}
//math function for trig functions and sqrt
double doMath(int number, string x){
	int ans = 1;
	if(x == "s"){
		ans = sin(number);
		return ans;
	}
	else if(x == "c"){
		ans = cos(number);
		return ans;
	}	
	else if(x == "q"){
		ans = sqrt(number);
		return ans;
	}
	else if(x == "l"){
		ans = log(number);
		return ans;
	}	
}


//throws the elements of the expression to the stack.
string expToStack(string str){
	int ph = 0;
	char* 	numsAndOps = new char[str.size() + 1];
		strncpy(numsAndOps, str.c_str(),str.size());
	string operation;
	string num;
	string numtwo;
	

	for(int i = 0; i < str.size(); i++) {
		if(isOp(numsAndOps[i]) == true){
			ph = i;
		}
	}
	
	
	int number;
	int numberTwo;
	int ans;

	if(ph != 0){
	num = str.substr(0,ph);
	startStacking(num);
	number = (strToInt(num));

	operation = str.substr(ph, 1);
	startStacking(operation);

	str.erase(0,ph + 1);
	numtwo = str.substr(0, string::npos);
	startStacking(numtwo);
	numberTwo = (strToInt(numtwo));
	}

	if(ph == 0){
	num = str.substr(ph + 2, str.size() - 3);
	startStacking(num);
	number = (strToInt(num));

	operation = str.substr(ph, 1);
	startStacking(operation);

	str.erase(0,ph + 1);
	}


	string answer;
       if(numsAndOps[ph] == 's' || numsAndOps[ph] == 'c' || numsAndOps[ph] == 'q' || numsAndOps[ph] == 'l'){
		ans = doMath(number, operation);
		answer = intToStr(ans);
	}
	else{
	ans = doMath(number, numberTwo, operation);
		answer = intToStr(ans);
	}

	return answer;
	
}

//finds the first parenthesis that is closed
void findExpression(string str){
	str = removeSpaces(str);
	str = convertGrossOps(str);
	string answar;

//if there is still a string left
while(str.size() != string::npos && str.find("(") != string::npos){
	

	//ph is a placeholder
	int ph;	
	int hp;

	char* 	exp = new char[str.size() + 1];
		strncpy(exp, str.c_str(),str.size());

	//Get the position of the last open par
	for(int i = 0; i < str.size(); i++) {
		if(exp[i] == '('){
			ph = i + 1;
		}
	}
	//Get position of the last closed par
	for(int j = str.size(); j > 0; j--) {
		if(exp[j] == ')'){
			hp = j;
		}
	}

	//The expression you are looking for is between those two parentheses 
	string	expression = str.substr(ph, hp-ph);

	//If the epxression is a trig function or the sqrt function
	if(str.find("s") != string::npos || str.find("sq") != string::npos || 
	   str.find("c") != string::npos || str.find("l") != string::npos) {
		expression = str.substr(ph - 2, expression.length() + 3);
		str.erase(ph -2, hp-ph +3);
	}
	else{
		str.erase(ph - 1, (hp-ph) + 2);
	}

	//Answer is mathed out from the stacks. I can't spell answer correctly.
	answar = expToStack(expression);
	
	if(answar.size() == 1 && answar == "0"){
	str.insert(ph - 2, answar);
	}
	else{
	str.insert(ph - 1, answar);
	}
}
	 cout << "The result is: " << answar << endl;	

}





int main(){
	cout << "Please enter the expression: " << endl;
	string expression;
	getline(cin, expression);
	
	
	myStack awesome;
	stack<string> input;
	

        parenthCheck(expression);
	findExpression(expression);



	return 0;
}
