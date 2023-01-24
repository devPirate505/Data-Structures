#include<iostream>
using namespace std;

//void temp(int*, int*);
//
//int main(){
//	
//	int a, b;
//	a = 10;
//	b = 20;
//	temp(&a, &b); //function calling
//	cout << "Value of a = " << a << endl;
//	cout << "Value of b = " << b << endl;4
//	cout << "OK" << endl;
//	
//	return 0;
//	
//}
//
//void temp(int* x, int* y){
//	
//	*x = *x + 100;
//	*y = *y + 100;
//	
//}

//=====================================================================

//int* abc(int& a){
//	int* p;
//	p = &a;
//	*p = (*p + *p) * *p - *p * *p;
//	return p;
//}
//
//int main(){
//	int x = 3;
//	int* p;
//	p = abc(x);
//	cout << "Value of p is changed by the function returned: " << *p << endl;
//	
//	return 0;
//}

//=====================================================================

//void ppp(char* sss){
//	while (*sss != '\0'){
//		cout << *sss << endl;
//		*sss++;
//	}
//}
//
//int main(){
//	char st[] = "Pakistan";
//	ppp(st); //calling function
//	cout << "OK";
//	
//	return 0;
//}

//===================================================================

int main(){
	//pointer initialization to NULL
	int* p = NULL;
	//request memory for the variable
	//using new operator
	
	p = new (nothrow) int;
	if (!p){
		cout << "Allocation of memory failed\n";
	}else{
		//Store value at allocated address
		*p = 29;
		cout << "Value of p: " << *p << endl;
	}
	//request block of memory
	//using new operator
	float* r = new float(75.25);
	cout << "Value of r: " << *r << endl;
	//request block of memory of size n
	int n = 5;
	int * q = new (nothrow) int[n];
	
	if(!q){
		cout << "allocation of memory failed\n";
	}else{
		for(int i = 0; i<n; i++){
			q[i] = i +1;
		}
		cout << "Value store in block of memory using index: ";
		for(int i = 0; i<n; i++){
			cout << q[i] << " "; 
		}
		cout << "Value store in block of memory using ptr: ";
		
		for (int i = 0; i<n ; i++){
			cout << *q << " ";
			q++;
		}
	}
	
	//freed the allocated memory
	delete p;
	delete r;
	//freed the block of allocated memory
	delete[] q;
	return 0;
}


