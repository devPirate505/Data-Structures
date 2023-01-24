#include<iostream>
#include<regex>

using namespace std;

bool passCheck(string pass){
	string regexpattern = "(?=.[a-z])(?=.[A-Z])(?=.[0-9])(?=.[!@#$%^&*()&_+=-]*)(?=.{5,11})";
	regex regexRule(regexpattern);
	
	return regex_match(pass,regexRule);
}

int main(){
	
	string pass;
	cout << "Enter Password: ";
	cin >> pass;
	
	if(passCheck(pass)){
		cout << "Password is valid!";
	}else{
		cout << "Password is invalid!";
	};
	
	return 0;
}
