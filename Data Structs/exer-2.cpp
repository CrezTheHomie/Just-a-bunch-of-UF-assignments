#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <map>


using namespace std;

void linear_search(int* A, int key, int size){
	int totesBool = 0;
	//Searches one element at a time to see if the key is in the array.
	for(int i = 0; i < size; i++){
		if(A[i] == key)	{
			totesBool = 1;
			break;
		}
		
	}
	//Prints if the searched element is in array.
	if(totesBool == 1){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}
//Iterative binary search
void binary_search(int* A, int key){
	int totesBool = 0;
	int size = sizeof(A)/sizeof(A[0]);
	int low = 0;
	int high = size-1;
	int mid;
	//Base case is until there are no more elements to check
	while (low <= high){
		mid = (low + high) / 2;
		//If key is located on the upper half of array
		if (A[mid] > key){
			high = mid - 1;
		}
		//If key is located on the bottom half of array
		else if(A[mid] < key){
			low = mid + 1;
		}
		else if(A[mid] == key){
			/*Instead of printing everytime this was checked, it was more effective to use a boolean. I felt like pretending to use a boolean was literally just as effective as actually using one, so I thought I'd have a bit of fun and use an int.*/
			totesBool = 1;
		}
   	 }
	//Prints if the searched element is in array.
	if(totesBool == 1){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
	
}

int main(int argc, char *argv[])
{
    const char* fileName;
    int NE;  // number of elements
    int NS;  // number of element to search
    
    int start, finish; // for the clocks
//Makes sure you inputted arguments.
    if (argc != 3)
    {
        printf("<usage>: parameters.\n");
        return 1;
    }
    else
    {
        NE = atoi(argv[1]);
        NS = atoi(argv[2]);
        //printf("Number of elements = %d\nNumber of elements to search = %d\n", NE, NS);
    }
    int Elements[NE]; // array initialized to the size of number of elements
    int Searchers[NS]; // array initialized to the size of number of searches

/*I thought it'd be nice to make a file that contained the numbers being searched for debugging purposes. I named the file appropriate to its size*/
    if(NE == 1000){
	fileName = "input-1k.in";
    }
    else if(NE == 1000000){
	fileName = "input-1m.in";
    }
    else if(NE == 1000000000){
	fileName = "input-1b.in";
    }
    else{fileName = "input-x.in";}

    // Initializing seed for pseudo-random sequence
    srand(time(NULL));

    ofstream inputFile; //File that stores the elements to be searched and the # we are looking for.
    inputFile.open(fileName); //open the file so it can be edited
    inputFile << NE << " " << NS << "\n"; /*I didn't know how to use printf to create a file..*/ //printf("%d %d\n", NE, NS);
    for (int i=1; i <= NE; i++)
    {
        int number;

        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));

        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        inputFile << number << " "; //printf("%d ", number);
	Elements[i] = number; //Inputs the element in the first array

        if (!(i % 100)) inputFile << "\n"; //if (!(i % 100)) printf("\n"); /*Hellpful to not get swamped with numbers. Thanks for the idea.*/
    }
    inputFile << "\n";
    for (int i=1; i <= NS; i++)
    {
        int number;

        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));

        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        inputFile << number << " ";
	Searchers[i] = number; //Inputs the number into the array containing the numbers we are searching for.

        if (!(i % 100)){ inputFile << "\n";}
    }
	inputFile.close(); //stop writing numbers on the file
	sort(Elements, Elements + NE); //Thanks for letting us use sort.
	cout << "Linear Search: \n";
	start = clock();
	//For each element to be searched, use the linear search algorithm.
	for(int i = 0; i < NS; i++){
		linear_search(Elements, Searchers[i], NE);
	}
	finish = clock();

	//cout << "time: " << (finish - start)/double(CLOCKS_PER_SEC)*1000 << endl; /*clock final - start gives us running time of the linear search*/ 
	start = clock();
	int size = sizeof(Elements)/sizeof(Elements[0]);


	cout << "Binary Search: \n";
	//For each element to be searched, use the binary search algorithm.
	for(int i = 0; i <= NS; i++){
		binary_search(Elements, Searchers[i]);
	}
	finish = clock();
	//cout << "time: " << (finish - start)/double(CLOCKS_PER_SEC)*1000 << endl; /*This one gives running time for binary search*/
    return 0;
}



