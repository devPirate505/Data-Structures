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
        
        
        SingleLinkedList mode(){
        	SingleLinkedList obj;
        	int c;
        	int cg = 0;
        	node* curr = head;
        	node* temp;
        	while(curr != NULL){
        		temp = head;
        		c = 0;
        		while(temp != NULL){
        			
        			if(curr->data == temp->data){
        				c++;
					}
        			
        			temp = temp->next;
				}
				if(c >= cg){
					cg = c;
					obj.insert(curr->data);
				}
        		curr = curr->next;	
			}
			
			return obj;
		}
		
		int median(){
			int m;
			node* curr = this->head;
			for(int i = 0; i <(this->length/2); i++){
				curr = curr->next;
			}
			m = curr->data;
			return m;
		}
};

int main(){
	
	SingleLinkedList obj;
	
//	for(int i = 0; i < 15; i++){
//		obj.insert(rand()%100);
//	}
	
	obj.insert(3);
    obj.insert(4);
    obj.insert(3);
    obj.insert(5);
    obj.insert(6);
    obj.insert(7);
    obj.insert(7);
	obj.printing();
	cout << endl << endl;
	obj.mode().printing();
	cout << endl << endl;
	cout << obj.median();
	
	
	return 0;
}
