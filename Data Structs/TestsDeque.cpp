#include "sDeque.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

Deque* q = new Deque;

q -> enqueue_front("I'm the first front facing item");
q -> enqueue_back("Hello world1");
q -> enqueue_front("Hello world2");
q -> pop_back();
q -> toStr();
cout << "Heyyyy\n";
return 0;
}
