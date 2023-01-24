#include<iostream>
using namespace std;
#define SIZE 10

class arrayList{
	private:
		int count;
		int pos;
		int* array;
		int* curr;
		
		void head(){
			curr = array;
		}
		void tail(){
			curr = array + count - 1;
		}
		
		void back(){
			curr = curr - 1;
		}
		
		void next(){
			curr = curr + 1;
		}
	public:
		
		arrayList(){
			count = 0;
			pos = 0;
			array = new int[SIZE];
			curr = array;
		}
		~arrayList(){
			delete[] array;
			delete curr;
		}
		
		void print(){
			if(count > 0){
				head();
				for(int i = 0; i < count; i++){
					cout << *curr << "\t";
					next(); 
				}
			}else{
					cout << "Array is empty!\n";
			}
		}
		void insert(int x){
			if(count != SIZE){
				tail();
				curr = curr + 1;
				*curr = x;
				count++;
			}else{
				cout << "List is full! \n";
			}
		}
		void insertAt(int pos, int x){
			if(count != SIZE){
				if(pos <= count && pos > 0){
					tail();
					for(int i = count; i >= pos; i--){
						*(curr + 1) = *curr;
						back();
					} 
					next();
					*curr = x;
					count++;
				}else if(pos > count && pos < SIZE){
					tail();
					curr = curr + 1;
					*curr = x;
					count++;
				}else{
					cout << "Invalid Position! \n";
				}
			}else{
				cout << "List is full! \n";
			}
		}
		
		void deleteAt(int pos){
			int* temp;
			if(count != 0){
				if(pos <= count && pos > 0){
					head();
					curr = curr + pos;
					for(int i = pos; i <= count; i++){
						*curr = *(curr + 1);
						next();
					}
					count--;
					
				}else{
					cout << "Invalid Position! \n";
				}
			}else{
				cout << "List is empty! \n";
			}
		}
};

int main(){
	arrayList* obj = new arrayList;
	obj->insert(3);
	obj->insert(5);
	obj->insert(7);
	obj->insert(8);
	obj->insertAt(1,9);
	
	obj->deleteAt(2);
	
	obj->print();
		
	
	return 0;
}
