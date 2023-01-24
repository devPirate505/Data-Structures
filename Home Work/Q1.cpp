/*
 The following code gets every value from the matrix we insert and in a second matrix it
 it calculates the value for second matrix through conditions. There are different conditions for 
 corners, side rows and columns and middle values.
*/


#include<iostream>
using namespace std;

void print(float arr[6][6]){ // print function to print array
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			cout<<"\t" << arr[i][j];
		}
		cout<<endl;
		
	}
}

int main(){
	float arr[6][6];
	float rArr[6][6];
	int c = 1;
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			arr[i][j] = c;
			c++;
		}	
	}
	print(arr);
	
	cout << endl << endl;
	
	for(int i = 0; i < 6; i++){	// loops to insert the values in every position
		for(int j = 0; j < 6; j++){
			if(i == 0 && j == 0){ // condition for top left corner
				
				rArr[i][j] = ((arr[i][j+1] + arr[i+1][j]+ arr[i+1][j+1]) / arr[i][j]);
				
			}else if(i == 0 && j <= 4){ // condition for top row
				
				rArr[i][j] = ((arr[i][j-1] + arr[i][j+1] + arr[i+1][j-1]+ arr[i+1][j] + arr[i+1][j+1]) / arr[i][j]);
				
			}else if(i == 0 && j == 5){ // condition for top right corner
				
				rArr[i][j] = (arr[i][j-1] + arr[i+1][j-1] + arr[i+1][j]) / arr[i][j];
				
			}else if(i <= 4 && j == 0){ // condition for left column
				
				rArr[i][j] = ((arr[i-1][j] + arr[i-1][j+1] + arr[i][j+1]+ arr[i+1][j] + arr[i+1][j+1]) / arr[i][j]);

			}else if(i == 5 && j == 0){ // condition for bottom left corner
				
				rArr[i][j] = (arr[i-1][j] + arr[i-1][j+1] + arr[i][j+1]) / arr[i][j];
				
			}else if(i == 5 && j <= 4){ // condition for bottom row
				
				rArr[i][j] = (arr[i][j-1] + arr[i-1][j-1] + arr[i-1][j]+ arr[i-1][j+1] + arr[i][j+1]) / arr[i][j];

			}else if(i == 5 && j == 5){ // condition for bottom right corner
				
				rArr[i][j] = (arr[i][j-1] + arr[i-1][j-1]+ arr[i-1][j]) / arr[i][j];
				
			}else if(i <= 4 && j == 5){ // condition for right column
				
				rArr[i][j] = (arr[i][j-1] + arr[i-1][j-1] + arr[i-1][j]+ arr[i+1][j-1] + arr[i+1][j]) / arr[i][j];
				
			}else{  // condition for mid entries
				
				rArr[i][j] = (arr[i][j-1] + arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]  + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j-1] + arr[i+1][j]) / arr[i][j];
				
			}
		}	
	}
	
	print(rArr);
	
	return 0;
}
