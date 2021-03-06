#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <cmath>
#include <unordered_map>

/*Status of code: Can do all computation required. Cann assign variables. Cannot handle error "undeclared variable"*/

typedef std::unordered_map<std::string,std::string> stringmap;

using namespace std;

//#define Pi 3.14169
//#define e 2.718

//It removes spaces so that the math is always correct and spaces don't mess anything up on accident.
string removeSpaces(string str){

	string space = " ";

	//remove spaces
	while(str.find(space) !=  string::npos && str.find(space) <= str.size()) {
		str.erase(str.find(space), 1);
   	}
	
   	return str;
}

//check to see if a character in the converted char[] is a variable 
bool isOp(char x){

	if(x == '+'){
		return true;
	}
	else if(x == '('){
		return true;
	}
	else if(x == ')'){
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
	else if(x == '^'){
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

//converts sqrt, log, sin, and cos into q l s and c (respectilvely) for since op management will be done via single characters.
string convertGrossOps(string str){

	
	//replace sqrt with q
	while(str.find("sqrt") != string::npos){
		int sq = str.find("sqrt");
		str.erase(sq, 5);
		str.erase(sq+1,1);
		str.insert(sq, "q");
	}
	
	
	//replace sin with s
	while(str.find("sin") != string::npos){
		int s = str.find("sin");
		str.erase(s, 4);
		str.erase(s+1,1);
		str.insert(s, "s");
	}

	
	//replace cos with c
	while(str.find("cos") != string::npos){
		int c = str.find("cos");
		str.erase(c, 4);
		str.erase(c+1,1);
		str.insert(c, "c");
	}
	
	
	//replace log with l
	while(str.find("log") != string::npos){
	int l = str.find("log");
		str.erase(l, 4);
		str.erase(l+1,1);
		str.insert(l, "l");
	}
	
	//Since define isn't working as I thought it would, just replace all instances of "e" with the number 2.718
	while(str.find("e") != string::npos){
	int e = str.find("e");
		str.erase(e, 1);
		str.insert(e, "2.718");
	}
	
	//Since define isn't working as I thought it would, just replace all instances of "Pi" with the number 3.14159
	//pdf says 3.14169 but thats not pi so I'm ignoring the probable typo
	while(str.find("Pi") != string::npos){
	int pi = str.find("Pi");
		str.erase(pi, 2);
		str.insert(pi, "3.14159");
	}
	
	return str;
}

//conversion for maths
double strToDouble(string str){

	int num = 0;
	int placeholder;

	for(int i = 0; i < str.size(); i++) {
		num = num * 10;
		num += str.at(i) - '0';
	}


	return num;
}

//does the inverse of the above
string doubleToStr(double n){
	string str;
	stringstream ss;
	ss << n;
	str = ss.str();
	return str;
	
}

//math function for algebra
double doMath(double a, double b, char x){
	double ans;
	if(x == '+'){
		ans = a + b;
		return ans;
	}
	else if(x == '-'){
		ans = a - b;
		return ans;
	}
	else if(x == '*'){
		ans = a * b;
		return ans;
	}
	else if(x == '/'){
		if(b != 0){
			ans = a / b;
			
			return ans;
		}
		else {
			cout << "Error: Dividing by zero.\n";
			//std::exit(EXIT_FAILURE);
		}
	}
	else if(x == '^'){
		ans = pow(a,b);
		return ans;
	}	

}
//overloaded math function for trig functions, log, and sqrt
double doMath(double a, char x){
	double ans = 1;
	if(x == 's'){
		ans = sin(a);
		return ans;
	}
	else if(x == 'c'){
		ans = cos(a);
		return ans;
	}	
	else if(x == 'q'){
		ans = sqrt(a);
		return ans;
	}
	else if(x == 'l'){
		ans = log(a);
		return ans;
	}	
}

//For the shunting yard algorithm
bool shouldPopOp(char Op1, char Op2){
	int a;
	int b;
	//cout << "Op1: " << Op1 << " Op2: " << Op2 << "\n";
	if(Op1 == '+' || Op1 == '-'){
		a = 1;
	}
	else if(Op1 == '*' || Op1 == '/'){
		a = 2;
	}
	else if(Op1 == '^'){
		a = 3;
	}
	else if(Op1 == 's' ||  Op1 == 'c' || Op1 == 'q' || Op1 == 'l'){
		a = 4;
	}

	if(Op2 == '+' || Op2 == '-'){
		b = 1;
	}
	else if(Op2 == '*' || Op2 == '/' ){
		b = 2;
	}
	else if(Op2 == '^'){
		b = 3;
	}
	else if(Op2 == 's' ||  Op2 == 'c' || Op2 == 'q' || Op2 == 'l'){
		b = 4;
	}
	if(Op1 == '(' || Op2 == '('){
		return false;
	}

	//if top of operator stack is larger or if parentheses close, you should pop
	if(a > b){
		return true;
	}
	//if equal, check type of associativity.
	else if(a == b)	{
		//left right associativity means pop
		if(a == 2 || a == 1){
			return true;
		}
		//right left means don't pop
		else {
			return false;
		}
	}
	//else we are going to add to operator stack
	else return false;
}

string infixToPostfix(string input){

	string inResult;
	stack<char> OperatorStack;
	
	stringstream stream;
	stream.str(input);
	char n;
	//Read input 1 character at a time. While you haven't reached the end of the input,
	while(stream >> n){
		//cout << "n: " << n << "\n";
		
		//If the token is a number, place it in the stack
		if(isOp(n) == false){
			inResult.push_back(n);
		}

		//If the token is an operator and we haven't found a closed parenthetical statment 
		else if(isOp(n) == true && n != ')'){
			if(n != 'l' && n != 's' && n != 'c' && n != '('){
				if(isOp(inResult.at((int)inResult.size()-1)) == false && inResult.at((int)inResult.size()-1) != '!'){					
					//cout << "num test: " << inResult.at((int)inResult.size()-1) << "\n";
					//cout << "placing ! \n";
					inResult.push_back('!');
				}
			}
			//If there is no operator in the operator stack push op into stack
			if(OperatorStack.empty() == true){
				//cout << "op is: " << n << " and stack was empty\n";
				OperatorStack.push(n);
			}

			//Else if lower precedence, start popping ops till you can put the lowest order op in
			else if(shouldPopOp(OperatorStack.top(),n) == true){
				while(shouldPopOp(OperatorStack.top(),n) == true){
					//cout << "Should pop. Top element: " << OperatorStack.top() << "\nTop popped\n";
					inResult.push_back(OperatorStack.top()); //Put the high order in the string
					OperatorStack.pop(); //take it out of the stack	
					//The first condition saves stack from seg fault. 
					//The 2nd makes sure to push onto stack in cases of LR associativity
					if(OperatorStack.empty() == true || shouldPopOp(OperatorStack.top(),n) == false){
						//cout << "LR assoc\n";
						OperatorStack.push(n); //push lower order into stack
						//cout << "New top element: " << OperatorStack.top() << "\n";
						//cout << "inResult: " << inResult << "\n";
						break;
					}
					//cout << "New top element: " << OperatorStack.top() << "\n";
					//cout << "inResult: " << inResult << "\n";
				}
			}	

			//for right left associativity, handling as special case since op shouldn't be popped immediately
			else if(OperatorStack.top() == n && n == '^'){
				//cout << "Should pop. RL assoc. Top element: " << OperatorStack.top() << "\npop\n";
				inResult.push_back(OperatorStack.top()); //Put the high order in the string
				OperatorStack.pop(); //take it out of the stack	
			}	

			//Else just push onto stack
			else{
				OperatorStack.push(n);
				//cout << "Not pop. Top element is now: " << OperatorStack.top() << "\n";
			}		
		}

		//if there is a parenthetical close
		else if(isOp(n) == true && n == ')'){
			//cout << "parentheses close\n";
			if(isOp(inResult.at((int)inResult.size()-1)) == false && inResult.at((int)inResult.size()-1) != '!'){			
				inResult.push_back('!');
			}
			//until you get to the rightP paired with the leftP
			while(OperatorStack.top() != '('){
				//cout << "Popping parenth express Top element: " << OperatorStack.top() << "\npopped\n";
				inResult.push_back(OperatorStack.top()); //Put the high order in the string
				OperatorStack.pop(); //take it out of the stack	
			}
			//cout << "Popping ( right out: " << OperatorStack.top() << "\npoppered\n";
			//inResult.push_back(OperatorStack.top()); //Put the high order in the string
			OperatorStack.pop(); //take rightP out of stack
		}
		
		//cout << "inResult: " << inResult << "\n\n";
	}

	//Pop the rest  of the ops from the stack since the expression has been read

	if(OperatorStack.empty() == false && isOp(inResult.at((int)inResult.size()-1)) == false){inResult.push_back('!');}	//cout << "3rd push back\n";
		while(OperatorStack.empty() == false){
			//cout << "  inResult: " << inResult << "\n";

			//cout << "Rest of elements are : " << OperatorStack.top() << "\npop\n";
			inResult.push_back(OperatorStack.top()); //Put the high order in the string
			OperatorStack.pop(); //take it out of the stack

			//cout << "inResult: " << inResult << "\n";
		}

	//Remove erroneus parentheses	
	string	rightP = "(";
	int 	ph = inResult.find(rightP);

	while(inResult.find(rightP) !=  string::npos && inResult.find(rightP) <= inResult.size()) {
		inResult.erase(inResult.find(rightP), 1);
   	}
	cout << "Removed parentheses with inResult: " << inResult << "\n";
	return inResult;
}

string solveExpression(string inResult){
	stack<double> NumberStack;
	//cout << "solving expression\n";

	int ph;
	
	double a;
	double b;
	double mathResult;
	string finalResult;
	stringstream ss;
	ss.str(inResult);
	char n;
	//Read input 1 character at a time. While you haven't reached the end of the input,
	while(ss >> n){
		//cout << "n_solve: " << n << "\n";
		//If number, push into number stack
		if(isOp(n) == false){
			char doubleCreator[inResult.size()];
			int i = 0;
			doubleCreator[i] = n;
			i++;
			while(ss >> n && n !='!'){
				//cout << "n_ss: " << n << "\n";
				doubleCreator[i] = n;
				i++;
				//cout << "doubleCreator: " << doubleCreator[i] << "\n";
			}
			//cout << "n = " << n << " is this !?\n";
			a = atof(doubleCreator);
			//cout << "pushed " << a << " into numStack\n";
			NumberStack.push(a);
		}
		//If operator, first pop 2 numbers out of the stack,
		//then, solve the expression you get from what you've got,
		//finally, push the result back into the NumberStack
		if(isOp(n) == true){
			//cout << "found op" << "\n";
			//If op requires 2 numbers IE if not a 1 number op
			if(n != 's' && n != 'l' && n != 'q' && n != 'c') {
				b = NumberStack.top(); //The first number is the right number in the sub-expression
				NumberStack.pop(); //take 1st number out of the stack	
				//cout << "b from stack= " << b << "\n";
				a = NumberStack.top(); //The 2nd number is the right number in the sub-expression
				//cout << "a from stack= " << a << "\n";
				NumberStack.pop(); //take 2nd number out of the stack
				
				mathResult = doMath(a,b,n);
				//cout << "doing arithmetic\nresult: " << mathResult << "\n";
				NumberStack.push(mathResult);
				//cout << "top: " << NumberStack.top() << "\n";
			}
			//Else op requires only 1 number
			else{
				//cout << "must not be arithmetic\nnumber is: ";
				a = NumberStack.top(); //Assign first number to a
				NumberStack.pop(); //take 1st number out of the stack

				mathResult = doMath(a,n);	
				//cout << "doing math\nresult: " << mathResult << "\n";
				NumberStack.push(mathResult);
			}	
		}
	cout << "stack result: " << mathResult << "\n";
	//mathResult;
	}
	mathResult = NumberStack.top(); //for return
	NumberStack.pop(); //take last number out of stack
	//cout << mathResult << "\n";
	finalResult = doubleToStr(mathResult);
	return finalResult;
}

int main(){

	string input;
	string input2;
	string variable;
	char var;
	char decision;
	int numSpaces;
	string subString;
	string result;
	stringstream inputSS;

	stringmap mymap;

	stringmap::hasher fn = mymap.hash_function();
	
	
	do {

		//get the input line from terminal
		getline (cin,input);

		//if "quit" is in the input, the user must want to quit
		if(input.find("quit") != string::npos){
			decision = '3';
			//cout << "decision = " << decision << "\n";
		}
		//if there is "let" in the input, there must be a variable expression
		else if(input.find("let") != string::npos){
			decision = '2';
			//cout << "decision = " << decision << "\n";
		}	
		//if neither of the above, solve the expression
		else{
			decision = '1';
			//cout << "decision = " << decision << "\n";
		}
			switch(decision){
				case '1' :
					
					//convert variables, if any in map, into numbers
					if(mymap.size() != 0){					
						for(auto& x: mymap){
							string var = x.first;
							//cout << "convertVar\n";
							//cout << "input: " << input << "\n";
							//cout << "var: " << var << "\n";	
	
							if(input.find(var) != string::npos){
								//cout << "found var to convert\n";
								int varSize = var.size();
								int whereVar = input.find(var);
								//cout << input << "\n";
								input.erase(whereVar, varSize);
								input.insert(whereVar, x.second);
								//cout << input << "\n";
							}
							else{	
								//cout << "didn't find var to convert\n";
							}
						}
					}
					/*numSpaces = 0;
					input2 = input;
					while(input2.find(' ') != string::npos){
						subString = input2.substr(0, input2.find(' '));
						cout << " sS: " << subString << "\n";
						//if(subString.size() == 3)
						input2.erase(0, input2.find(' ')+1);
						cout << input2 << "\n";
					} 
					if(input2.size() == 3){
						cout << "Error: undefined variable\n";
						break
					}
					else if(input2.size() == 1){
						
					}
					cout << numSpaces << "\n";*/
					input = removeSpaces(input);
					input = convertGrossOps(input);
					input = infixToPostfix(input);
					result = solveExpression(input);
					cout << result << "\n";
					break;

				case '2' : 
					input = removeSpaces(input);
					
					int let = input.find("let");
					input.erase(let, 3);
					inputSS.str(input);

					while(inputSS >> var && var != '='){
						variable.push_back(var);
					}
					//cout << "variable: " << variable << "\n";
					
					input.erase(0, variable.size()+1); //The rest of the input is now the expression to be evaluated.
					
					
					//convert variables, if any, into numbers
					if(mymap.size() != 0){					
						for(auto& x: mymap){
							string var = x.first;
							//cout << "convertVar\n";
							//cout << "input: " << input << "\n";
							//cout << "var: " << var << "\n";	
	
							while(input.find(var) != string::npos){
								//cout << "found var to convert\n";
								int varSize = var.size();
								int whereVar = input.find(var);
								//cout << input << "\n";
								input.erase(whereVar, varSize);
								input.insert(whereVar, x.second);
								//cout << input << "\n";
							}
						}
					}

					//solve the expression
					input = convertGrossOps(input);	
					input = infixToPostfix(input);
					result = solveExpression(input);

					//assigns variables in hashmap
					mymap.insert(std::pair<string,string>(variable, result));
					mymap.at(variable) = result;
					variable.clear();
					
					//cout << "Map size : " << mymap.size() << "\n";
					break;
			
		}			

	} while (decision != '3');

	return 0;
}
