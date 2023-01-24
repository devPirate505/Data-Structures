/*
	The following code will print the table of a user input number and it's limit using pointers 
	passing them into function.
*/


#include<iostream>
using namespace std;

void table(int* n, int* l){ 	// Funtion for table, passing the pointers
	
	for(int i = 1; i <= *l; i++){
		cout << *n << " * " << i << " = " << *n * i << endl;
	}
	
}

int main(){
	string c;	// variable for loop continuity
	do{
		int num, lim;
		int* n = &num;	// pointer declaration
		int* l = &lim;
	
		cout << "Enter table number: ";	// taking user input
		cin >> *n;
		cout << "Enter table limit: ";
		cin >> *l;
	
		table(n, l);	// function call
		
		cout << endl;
		cout << "Do you want to continue?(y/n)";	// asking user if he wants to continue
		cin >> c;
		
	}while(c != "n");
	
	
	return 0;
}

