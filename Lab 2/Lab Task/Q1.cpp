#include<iostream>
using namespace std;
#define SIZE 10

class ArrayList{
	private:
		int count;
		int pos;
		char* Array;
		char* curr;
		
		void head(){
			curr = Array;
		}
		
		void tail(){
			curr = Array + count - 1;
		}
		
		void back(){
			curr = curr - 1;
		}
		
		void next(){
			curr = curr + 1;
		}
	public:
		ArrayList(){
			Array = new char[SIZE];
			count = 0;
			pos = 0;
			curr = Array;
		}
		~ArrayList(){
			delete[]Array;
			delete curr;
		}
		void printArray(){
			if(count > 0){
				head();
				for(int x = 0; x < count; x++){
					cout << *curr++ << "\t";
				}
			}else{
				cout << "Array is Empty" << endl;
			}
		}
		void InsertElement(int val){
			if(!IsFull()){
				head();
				curr = curr + count;
				*curr = val;
				count++;
			}else{
				cout << "Array is Full!" << endl;
			}
		}
		void InsertAtPos(int pos, int val){
			if(!IsFull()){
				if(pos <= count && pos > 0){
					tail();
					for(int i = count; i >= pos; i--){
						*(curr + 1) = *curr;
						back(); //curr = curr-1
					}
					next(); //curr = curr+1
					*curr = val;
					count++;
				}
			}else if(pos > count && pos < SIZE){
				head();
				curr = curr + pos -1;
				*curr = val;
				count++;
			}else{
				cout << "Invalid Position" << endl;
			}
		}
		bool IsFull(){
			if(count == SIZE){
				return true;
			}else{
				return false;
			}
		}
		bool IsEmpty(){
			if(count == 0){
				return true;
			}else{
				return false;
			}
		}
		int Count(){
			return count;
		}
		void emptylist(){
			head();
			for(int x = 0; x < SIZE; x++){
				*curr++ = 0;
			}
		}
		void compareArrays(ArrayList* obj1, ArrayList* obj2){
			obj1->head();
			obj2->head();
			
			for(int i = 0; i < obj1->Count(); i++){
				for(int j = 0; j < obj2->Count(); j++){
					if(*obj1->curr == *obj2->curr){
						this->InsertElement(*obj1->curr);
					}
					obj2->next();
				}
				obj2->head();
				obj1->next();
			}
		}
};

int main(){
	ArrayList* obj1 = new ArrayList();
	ArrayList* obj2 = new ArrayList();
	ArrayList* obj3 = new ArrayList();
	
	obj1->emptylist();
	obj1->InsertElement('a');
	obj1->InsertElement('b');
	obj1->InsertElement('g');
	obj1->InsertElement('w');
	obj1->InsertElement('k');
	obj1->InsertElement('s');
	obj1->InsertElement('z');
	obj1->InsertElement('y');
	
	obj2->emptylist();
	obj2->InsertElement('k');
	obj2->InsertElement('s');
	obj2->InsertElement('z');
	obj2->InsertElement('f');
	
	obj1->printArray();
	cout << endl;
	
	obj2->printArray();
	cout << endl;
	
	obj3->compareArrays(obj1, obj2);
	cout << endl;
	obj3->printArray();
	cout << endl;
	
}
