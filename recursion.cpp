#include<iostream>
using namespace std;


int fun(int x){
	
	if(x==1){
		cout << x << " ---" << endl;
		return;
	}else{
		
		cout << x << " + func(" << x-1 << ")" << endl;
		return x+fun(x-1); 
	}
}

//int even(int x){
//	if(x == 1){
//		return x;
//	}else{
//		if()
//		
//		
//	}
//	
//	
//	
//}
