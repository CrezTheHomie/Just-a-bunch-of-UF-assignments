#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){

	int nodes, edges, queries, cost, A, B;

	int i, j, k;
	cin >> i >> j >> k;

	nodes = i;
	edges = j;
	queries = k;

	/*cout << nodes << endl;
	cout << edges << endl;
	cout << queries << endl;*/
	
	int matrix[nodes][nodes]; 
	int matrix2[nodes][nodes];
	//int path[nodes][nodes];
	
	

	//initialize matrices
	for(int row=0; row < nodes; row++){
		for(int col = 0; col < nodes; col++){
			matrix[row][col]=0;
		}
	}
	for(int row=0; row < nodes; row++){
		for(int col = 0; col < nodes; col++){
			matrix2[row][col]=0;
		}
	}
	/*for(int row=0; row < nodes; row++){
		for(int col = 0; col < nodes; col++){
			path[row][col]=0;
		}
	}*/


	//Print matrix
	/*for(int row = 0; row < nodes; row++){
		for(int col = 0; col < nodes; col++){
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}*/

	//add connections to matrix
	for(int i = 0; i < edges; i++){
		/*cout << "Add connection\n";
		cout << "A: " << A << endl;
		cout << "B: " << B << endl;*/
		cin >> A >> B >> cost;
		matrix[A-1][B-1] = cost;
		matrix2[A-1][B-1] = cost;
	}


	//Floyd-Warshall
	/*Add nodes between (first 1 then 2, 3 till n) and look if
	distance is shorter*/
	for(int k = 0; k < nodes; k++){
		for(int i = 0; i < nodes; i++){
			for(int j = 0; j < nodes; j++){
				if((matrix2[i][k] * matrix2[k][j] != 0) && (i != j)){		
					if((matrix2[i][j]>matrix2[i][k]+matrix2[k][j]) || (matrix2[i][j] == 0)){
						matrix2[i][j]=matrix2[i][k]+matrix2[k][j];
						//path[i][j] = first[i][k];
					}
				}
			}
		}
	}
	/*
	//Print matrix
	for(int i = 0; i < nodes; i++){
		for(int j = 0; j < nodes; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//Print matrix2
	for(int i = 0; i < nodes; i++){
		for(int j = 0; j < nodes; j++){
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}
	//Print path
	for(int i = 0; i < nodes; i++){
		for(int j = 0; j < nodes; j++){
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << "WTF\n";*/

	int qA, qB;
	//Print output
	for(int i = 0; i < queries; i++){
		cin >> qA >> qB;
		if(qA == qB){
			cout << "cost = 0\n";
			cout << qA << "-" << qB << endl;
		}
		else if(matrix2[qA-1][qB-1] == 0 && qA != qB){
			cout << "NO PATH\n";
		}
		else{
			cout << "cost = " << matrix2[qA-1][qB-1] << endl;
		}
	}

	return 0;
}
