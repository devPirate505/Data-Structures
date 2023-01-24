
#include<iostream>
using namespace std;
int main(){
//	int a,b;
//	int* x, * y;
//	a = 33;
//	b = 66;
//	x = &a;
//	y = &b;
//	cout << "Memory address of variable a = " << x << endl;
//	cout << "Memory address of variable b = " << x << endl;
//	cout << "Memory address of pointer x = " << &x << endl;
//	cout << "Memory address of pointer y = " << &x << endl;
//	cout << "Memory address of variable x = " << *&x << endl;
//	cout << "Memory address of variable y = " << *&x << endl;

//	int* p;
//	int a;
//	p = &a;
//	cout << "Enter data value? ";
//	cin >> *p;
//	cout << "Value of variable a = " << a << endl;
//	cout << "Value of variable *p = " << *p << endl;
//	cout << "Memory Address of variable = " << p << endl;
	
//	int a;
//	int* b;
//	int** c;
//	int*** d;
//	a = 7;
//	b = &a;
//	c = &b;
//	d = &c;
//	cout << "The address of the variable a is: " << b << endl;
//	cout << "The address of the variable b is: " << c << endl;
//	cout << "The address of the variable c is: " << d << endl;
	
	int arr[5], * pp, i;
	pp = arr;
	cout << "Enter Values into an array(index): " << endl;
	for (int i = 0; i <= 4; i++){
		cin >> arr[i];
	}
	
	pp = arr;
	cout << "Enter Values into an array(pointer): " << endl;
	for (int i = 0; i <= 4; i++){
		cin >> *pp;
		pp++;
	}
	
	cout << "Values from array using Pointer notation: " << endl;
	pp = arr;
	for (int i = 0; i <= 4; i++){
		cout << *pp << "\t";
		pp++;
	}
	cout << "\nUsing while loop: " << endl;
	int* ptr = arr;
	while (*ptr != NULL){
		cout << *ptr++ << "\t";
	}
	
	return 0;
	
}
