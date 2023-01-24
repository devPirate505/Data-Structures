/*
	The following code checks if a password is valid or invalid.
*/

#include<iostream>
using namespace std;

int checklen(string temp){		//function to check the length
	int c = 0;
	if(temp.length()>=5 && temp.length()<=11){
		c = 1;
	}
	return c;
}

int checkCap(string temp){		//function to check capital letter in password
	int c = 0;
	for(int i = 0; i < temp.length(); i++){
		if(isupper(temp[i])){
			c = 1;
			break;
		}
	}
	return c;
}

int checkDigit(string temp){		//function to check digit in password
	int c = 0;
	for(int i = 0; i < temp.length(); i++){
		if(isdigit(temp[i])){
			c = 1;
			break;
		}
	}
	return c;
}

int checkChar(string temp){			//function to check special character in password
	int c = 0;
	for(int i = 0; i < temp.length(); i++){
		if(ispunct(temp[i])){
			c = 1;
			break;
		}
	}
	return c;
}

int main(){
	string temp;
	int n = 0;	// flag
	 
	cout << "Please set your password: ";
	cin >> temp;
	
	
	do{
		n = 1;	//flag set to 1
		if(checklen(temp) == 0){
			cout << "The length of your password should greater than 5 and less than 11! \n";
			n = 0;	//flag set to 0 due to length
		}
		if(checkCap(temp) == 0){
			cout << "There should be atleast one capital letter in your password! \n";
			n = 0;	//flag set to 0 due to missing capital letter
		}
		if(checkDigit(temp) == 0){
			cout << "There should be atleast one digit in your password! \n";
			n = 0;		//flag set to 0 due to missing digit letter
		}
		if(checkChar(temp) == 0){
			cout << "There should be atleast one special character in your password! \n";
			n = 0;		//flag set to 0 due to missing special character letter
		}
		if(n == 0){
			cout << "\nTry again: ";
			cout << endl;
			cin >> temp;
		}
	}while(n == 0);
	
	if(n == 1){
		cout << "\nPassword is Valid";
	}
	
	
	return 0;
}
