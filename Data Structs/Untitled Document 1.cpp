#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]){

	int nodes = atoi(argv[0]);
        int path = atoi(argv[1]);
	int queries = atoi(argv[2]);
	
	int matrix[nodes][nodes]; 
	
	

	//initialize diagonal of matrix
	for(int i=0; i < nodes; i++){
		a[i][i]=0;
	}

	//initialize distances
	for(int i = 0; i < path; i++){
		matrix[atoi(argv[0])][atoi(argv[1])] = argv[2];
	}
	

	/*

	//Floyd-Warshall
	/Add nodes between (first 1 then 2, 3 till n) and look if
	distance is shorter/
	for(int k = 0; k < nodes; k++){
		for(int i = 0; i < nodes; i++){
			for(int j = 0; j < nodes; j++){
				if(a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}

	//Print out final distance
	for(int i = 0; i < queries; i++){

	}
	*/
	//Print matrix
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			cout << a[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
