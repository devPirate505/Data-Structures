/*
	The following code reads data from a file and stores the data in 2D array
	and stores the sum of rows in another array.

*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string t;
	int arr[5][5];		// array to store the data
	int sum[5];			// array to store the sum
	
	ifstream file("data.txt");	//opening file
	
	
	for(int i = 0; i < 5; i++){		//inserting data from file into 2D array
		for(int j = 0; j < 5; j++){
			
			file >> t;
			arr[i][j] = stoi(t);	
					
			}
		}
  		
	file.close();
	
	int add = 0;
	
	for(int i = 0; i < 5; i++){		// calculating the sum and storing in summ array
		for(int j = 0; j < 5; j++){
		
			cout << arr[i][j] << " ";	//displaying the data in array
			add += 	arr[i][j];	
		}
		cout << endl;
		sum[i] = add;
		add = 0;
	}
	cout << endl << "The Sum of rows is: ";		// printing the sum array
	for(int i = 0; i < 5; i++){
		cout << "\t" << sum[i];
	}
	
	
	return 0;
}
