#include <string>
#include <iostream>
using namespace std;

/* string s1 = “ string”;
cout << s1.at(1) << endl; // output: ‘t’
cout << s1.at(4) << endl; // output: ‘n’
● Returns the character at a specific location of the 
string.
● Is equivalent to s[i], if s is defined by char[ ].

● Example:
char a = ‘5’;
int b;
// desired output: b = 5
b = a - ‘0’; */
#define MAX 20

 class stack{

	private:
	int arr[MAX];
	int top;

	public:
		stack(){
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

string seperate(string str){
	//ph is a placeholder
	int ph = 0;
	string space = " ";
	string word;

	while((ph = str.find(space)) !=  string::npos) {
		word = str.substr(0, ph);
		cout << word << endl;
		str.erase(0, ph + 1);
	}
	word = str.substr(0,str.size());
	return word;
}



int main(){
	stack awesome;
	awesome.push(10);
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
	return 0;
}
