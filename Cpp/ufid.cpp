#include <iostream>

//69868100

int main(){
	int n;	std::cin >> n; int k = 0; int digit;
	int ufid[8]; int rem = 10000000; int f = 0;

	std::cout << "Your input was...\n";

	for (int i = 1; i <= 8; i++){
	
		digit = n;
		digit = digit/rem;
		digit = digit % 10;
		rem = rem/10;
		ufid[i] = digit;
		std::cout << ufid[i] << "\t";
	}
	std::cout << "\n";
	for (int j = 1; j <=8; j++){
	
		if (ufid[1] < ufid[j]) {
			
			std::cout << ufid[j] << ",";
		}
	}
	std::cout << " are greater than the first digit " << ufid[1] <<". \n";

	for (int o = 1; o <=8; o++){
	
		if (ufid[1] > ufid[o]) {
			
			f += ufid[o];
		}
	}
	std::cout << "Sum of other digits is " << f << ".";
	return 0;
}

