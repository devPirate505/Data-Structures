#include<iostream>
using namespace std;

class node{
    	public:
        	node* next;
        	node* previous;
        	int data;
        	node(int val){
          	  	data = val;
          	  	next = NULL;
      	  	}
	};

class DoubleLinkedList{
	private:
		node* head;
		int length;
		
	public:
		DoubleLinkedList(){
			head = NULL;
			length = 0;
		}
		int size(){
			return length;
		}
		void setSize(int l){
			this->length = l;
		}
		node* getHead(){
			node* curr = head;
			return curr;
		}
		void insert(int val){
			node* t = new node(val);
			if(head == NULL){
				head = t;
				length++;
			}else{
				node* curr = head;
				while(curr->next != NULL){
					curr = curr->next;
				}
				curr->next = t;
				t->previous = curr;
				length++;
			}
		}
		void insertAt(int pos, int val){
			if(pos<1 || pos>length+1){ 
				cout << "Invalid position." << endl;
				return;
			}
			node* t = new node(val);
			if(pos == 1){
				if(head == NULL){	//Head is empty
					head = t;
					length++;
				}else{	//Head already exist
				t->next = head;
				head->previous = t;
				head = t;
				length++;
				}
			}else{ 		//position can be centre or in last
				node* curr = head;
					//cout << curr->data << " here" <<endl;
				for(int i = 1; i < pos-1; i++){
					curr = curr->next;
				}
					//cout << curr->data << " here" <<endl;
				t->next = curr->next;
				t->previous = curr;
				if(curr->next != NULL){ 	// if it is not a Last
					curr->next->previous = t;
				}
				curr->next = t;
				length++;
			}
		}
		
		void removeAt(int pos){
			node* curr = head;
			if(head == NULL){
				cout << "List is empty." << endl;
			}
			if(pos == 1){
				head = curr->next;
				head->previous = NULL;
				delete curr; curr = NULL;
				length--;
			}else{
				node* temp = NULL;
				for(int i = 0; i < pos - 1; i++){
					temp = curr;
					curr = curr->next;
				}
				temp->next = curr->next;
				if(curr->next != NULL){
					curr->next->previous = temp;
				}
				delete curr; curr = NULL;
				length--;
			}
		}
		
		void print(){
			node* curr = head;
			while(curr->next){
				cout << curr->data << "\t" <<endl;
				curr = curr->next;
			}
			cout << curr->data << "\t" <<endl;
		}
};

int main(){
	
	DoubleLinkedList list;
	list.insert(100);
	list.insertAt(1,1);
	list.insertAt(2,2);
	list.insertAt(3,3);
	list.insertAt(4,4);
	list.removeAt(4);
	list.print();
	
	return 0;
}
