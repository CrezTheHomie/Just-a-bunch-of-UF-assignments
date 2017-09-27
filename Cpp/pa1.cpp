#include <iostream>

int main() {
	
	int n; std::cin >> n; 
	
	int row = n; int col = n; int square[row][col]; int mConstant = (n * ((n*n)+1))/2;

	//initializes 0 for each element. This way none of those crazy numbers mess up the magi squares.
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			square[i][j] = 0;
		}
	}

	row = 1;
	col = n/2 + 1;
if(n > 2 && (n%2) != 0) {
	for (int i = 1; i <= n*n; i++) {
		
		if (col > n) {
			col = col-n;
		}
		if (row <= 0) {
			row = row+n;
		}
		//If the element is non-zero...
		if (square[row][col] != 0) {
			/*Probably could have use recursive function here but these are basically so that, when you arrive at a non-zero element, the next number is input in the space directly under the previous element.*/
			if(row + 2 <= n) {
			row += 2;
			col -= 1; }
			else if (row + 1 <=n) {
			row += 1;
			col -= 1;
			}
			else {
			row = 2;
			col = n;
			}	
		}

		/*Input the element; then move the cursor diagonally one space*/
		square[row][col] = i;
		row--;
		col++;
		

		
	}

	std::cout << "\n" << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		std::cout << square[i][j] << "\t"; }
	std::cout << "\n";
	}
	std::cout << "\n";
	
	for (int i = 1; i <= n; i++) {
		int sumRows = 0;
		for(int j = 1; j <= n; j++){
			sumRows += square[i][j];
		}
		std::cout << "Checking the sum of row " << i << ":\t" << sumRows << " \n";
	}
	
	for (int i = 1; i <= n; i++) {
		int sumCols = 0;
		for(int j = 1; j <= n; j++){
			sumCols += square[j][i];
		}
		std::cout << "Checking the sum of column " << i << ":\t" << sumCols << " \n";
	}
	
	std::cout << "The sum of both diagonals is:\t" << mConstant << "\n";
	return 0;
}
	else {
	std::cout << "Please try again and enter an odd, positive integer that is greater than one." << "\n";
	}
}
