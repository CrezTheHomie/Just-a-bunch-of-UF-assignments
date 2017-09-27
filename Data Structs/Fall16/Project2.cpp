#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>

using namespace std;

int KMP(string input, string hintString){
    //cout << "start KMP\n";
    int i = 0;
    int j = 0;
    int combination = 0;
    int size = hintString.size();
    int *tempArray = new int[size];
    int index = 0;
    tempArray[0] = 0;
    
    for(int i = 1; i < size;){
        if(hintString[i] == hintString[index]){
            tempArray[i] = index + 1;
            index++;
            i++;
        }
        else if(index!=0){
            index = tempArray[index-1];
        }
        else{
            tempArray[i] = 0;
            i++;
        }
    }/*
    cout << "using string:\t";
    for(int k=0; k < input.size(); k++){
        cout << input[k] << "\t";
    }
    cout << "\n";*/
    while(i < input.size()){
        //If the two characters are the same check the next character
        if(input[i] == hintString[j]){
            i++;
            j++;
                if(j == hintString.size()){
                //cout << "found combination due to " << input[i-2] << input[i-1] <<input[i] << "\n";
                combination++;
                j = tempArray[j-1];
            }
        }

        //Else, try to find a prefix from the hintstring 
        //that can match input's character at i
        //If there is no prefix, check the next character in input
        else if(j==0){
            i++;
        }
            
        else{
            if(j!=0){
                j = tempArray[j-1];
            }
        }
    }
    //cout << "how many combinations?\n" << combination << "\n\n";
    return combination;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs2( char *X, char *Y, int m, int n ){
   int L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++){
     for (int j=0; j<=n; j++){
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0){
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1]){
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   //cout << "LCS of " << X << " and " << Y << " is " << lcs;
	//cout << "\n";
   cout << lcs;
}

int main(){

    string hintString;
    cin >> hintString;
    
    string input;
    int N;
    cin >> N;
    int combRow[N];
    int combCol[N];
    
    
    string *row = new string[N];
    string *col = new string[N];
    
    stringstream ss;
    //getline (cin,input);
    cin.ignore();
    //create matrix
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        row[i] = input;

        //check each row string in console
        //cout << "String " << i << " " << rowStrings[i] << "\n";

        //take each character and add it to the string of the columns
        for (int j = 0; j < N; j++) {
            col[j] = col[j] + input[j];
        }
    }
    
    //print row
    /*
    for(int k=0; k < N; k++){
        cout << "row " << k << ": " << row[k] << "\n";
    }
    //print column
    cout << "\n";
    for(int k=0; k < N; k++){
        cout << "column " << k << ": " << col[k] << "\n";
    }
    cout << "\n";*/
    //do
    
    for(int k1=0; k1 < N; k1++){
        //cout << "row " << k1 << "\n";
        combRow[k1]=KMP(row[k1],hintString);
    }
    for(int k2=0; k2 < N; k2++){
        //cout << "col " << k2 << "\n";
        combCol[k2]=KMP(col[k2],hintString);
    }
    if(N == 1){
        cout << combCol[0];
        return 0;
    }

    
    //max combination
    char char1[N], char2[N];
    char c;
    for(int i = 0; i < N; i++){
        c = combRow[i] + '0';
        //cout << "int1 = " << combRow[i] << "\n";
        //cout << "c = " << c << "\n";
        char1[i] = c;
    }
    for(int i = 0; i < N; i++){
        c = combCol[i] + '0';
        //cout << "int2 = " << combCol[i] << "\n";
        //cout << "c = " << c << "\n";
        char2[i] = c;
    }
    
    lcs2(char1,char2, N, N);

	cout << "\n";

    return 0;
}
