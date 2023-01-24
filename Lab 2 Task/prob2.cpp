#include<iostream>
using namespace std;

class node{
    public:
        node* next;
        int data;
        node(int val){
            data = val;
            next = NULL;
        }
};

class SingleLinkedList{
    private:
        node* head;
        int length;
    public:
        SingleLinkedList(){
            head = NULL;
            length = 0;
        }
        //Insertion
        void insert(int val){
            node* t = new node(val);
            if (head == NULL) {
                head = t;
                length++;
            }else{
                node* curr = head;
                while (curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = t;
                length++;
                
            }
        }
        void insertAt(int pos, int val){
            if(pos < 1 || pos > length + 1){
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if(pos == 1){
                if(head == NULL){
                    head = t;
                }else{
                    t->next = head;
                    head = t;
                }
                length++;
            }else{
                node* curr = head;
                node*pre = head;
                for(int i = 1; i<pos-1; i++){
                    pre = curr;
                    curr = curr->next;
                }
                pre->next = t;
                if(curr != NULL){
                    t->next = curr;
                }
                length++;
            }
        }
        void printing(){
            cout << "Printing the single Linked List" << endl;
            cout << "Head---> ";
            node* curr = head;
            while(curr != NULL){
                cout << curr->data << "---> ";
                curr = curr->next;
            }
            cout << "NULL";
        }
        
        SingleLinkedList reverse(){
        	SingleLinkedList obj;
        	node* temp = head;
			
			for(int i = 0; i < this->length; i++){
				
				obj.insertAt(1, temp->data);
				temp = temp->next;
				
			}
        	
        	return obj;
        	
		}
        
};

int main(){
	
    SingleLinkedList obj;
    obj.insert(11);
    obj.insert(12);
    obj.insert(13);
    obj.insert(14);
    obj.insert(15);
    obj.insert(16);
	obj.printing();
	cout << endl << endl;
	obj.reverse().printing();


    return 0;
}

