/*
	The following code checks if a email is valid or invalid using regex.
*/

#include<iostream>
#include<regex>

using namespace std;

bool emailCheck(string email){	//function to check an email
	string regexpattern = "[a-zA-Z]+[-_.]?[a-zA-Z]+@[a-zA-Z]+\\.[com||COM]+";
	regex regexRule(regexpattern);
	
	return regex_match(email,regexRule);
}

int main(){
	
	string email;
	cout << "Enter email: ";
	cin >> email;
	
	if(emailCheck(email)){	//email is valid if function returns true
		cout << "Email is valid!";	
	}else{
		cout << "Email is invalid!";
	};
	
	return 0;
}
