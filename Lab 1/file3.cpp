#include<iostream>
using namespace std;
//class Box{
//	public:
//		Box(){
//			cout << "Constructor called!" << endl;
//		}
//		~Box(){
//			cout << "Destructor called!" << endl;
//		}
//};
//
//int main(){
//	Box* myBoxArray = new Box[4];
//	delete[] myBoxArray; //delete array
//	
//	return 0;
//}

int main(){
	int num;
	cout << "Enter total number of students: ";
	cin >> num;
	float* ptr;
	//memory allocation of num number of floats
	ptr = new float[num];
	
	cout << "Enter GPA of students: " << endl;
	for(int i = 0; i < num ; ++i){
		cout << "Student" << i + 1 << ": ";
		cin >> *(ptr + i);
	}
	
	cout << "\nDisplaying GPA of students." << endl;
	for(int i = 0; i < num; ++i){
		cout << "Student" << i + 1 << ": " << *(ptr + i) << endl;
	}
	//ptr memory is released
	delete[] ptr;
	return 0;
}
