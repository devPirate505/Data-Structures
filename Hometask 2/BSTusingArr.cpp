#include<iostream>

using namespace std;

class BST{
	private:
		struct node{
			int key;	
		};
		node *arr;
		int capacity;
		int totalItems;
		
		
		
		void doubleCapacity(){
			
			int newCapacity = capacity * 2;
			node *newArr = new node[newCapacity];
			
			for(int i = 0; i <= newCapacity; i++){
				newArr[i].key = -1;
			}
			
			for(int i = 0; i <= this->capacity; i++){
				newArr[i].key = this->arr[i].key;
			}
			
			delete this->arr;
			this->capacity = newCapacity;
			this->arr = newArr;
		}
		
		int search(int key, int index = 0){
			static int x = NULL;
			if(index > this->capacity || this->arr[index].key == -1){
				return NULL;
			}
			
			if(this->arr[index].key == key){
				x = index;
				return index;
			}
			if(key < this->arr[index].key)
				search(key, ((index*2)+1));
			if(key > this->arr[index].key)
				search(key, ((index*2)+2));
			
			return x;
				
		}
		
	public:
		
		BST(){
			this->arr = new node[1];
			this->arr[0].key = -1;
			this->capacity = 1;
			this->totalItems = 0;
		}
		
		int FindMax(int index){    
			cout << this->capacity << endl;
    		while(this->arr[(index * 2)+2].key != -1 && index < (this->capacity)/2){
				index = (index * 2)+2;
   	 		}
   	 		cout << this->arr[index].key << " at " << index << endl;
    		return index;    
		}
		
		void insert(int key, int index = 0){
			if(this->totalItems == this->capacity || index >= this->capacity){
				doubleCapacity();
			}
			
			if(this->arr[index].key == -1){
				this->arr[index].key = key;
				this->totalItems++;
				return;
			}
			
			if(key > this->arr[index].key){
				insert(key, (index*2)+2);
			}
			
			if(key < this->arr[index].key){
				insert(key, (index*2)+1);
			}
			return;
		}
		
		void check(){
			for(int i = 0; i < this->capacity; i++){
				if(this->arr[i].key != -1)
					cout << i << "--->" << this->arr[i].key << endl;
			}
			cout << "Number of items = " << this->totalItems << endl;
			return;
		}
		
		void searchNum(int key){
			int x = search(key);
			if(x == NULL){
				cout << "Number not found!" << endl;
			}else{
				cout << key << " found at index " << x << endl;
			}
		}
		
		
		int deleteNum(int key, int index = 0){
			static int x = search(key);
			
			if(index > this->capacity || this->arr[index].key == -1){
				return NULL;
			}else if(key < this->arr[index].key)
        		deleteNum(key, ((index*2)+1));
    		else if (key > this->arr[index].key)
        		deleteNum(key, ((index*2)+2));
    		else{
        //No child
        		if(this->arr[((index*2)+2)].key == -1 && this->arr[((index*2)+1)].key == -1){
            		this->arr[index].key = -1;
            		return NULL;
        	}
        //One child on left
        	else if(this->arr[((index*2)+2)].key == -1){
            	this->arr[index] = this->arr[((index*2)+1)];
            	this->arr[((index*2)+2)].key = -1;
        	}
        //One child on right
        	else if(this->arr[((index*2)+1)].key == -1){
            	this->arr[index] = this->arr[((index*2)+2)];
            	this->arr[((index*2)+2)].key = -1;
        	}
        //two child
        	else
        	{
            	int y = FindMax(index*2+1);
            	this->arr[x] = this->arr[y];
            	this->arr[x].key = -1;
        	}
			return NULL;
		}
	}
		
		void InOrder(int index = 0){
			if(index > this->capacity || this->arr[index].key == -1){
				return;
			}
			InOrder((index*2)+1);
			if(this->arr[index].key != -1)
				cout << this->arr[index].key << endl;
			InOrder((index*2)+2);
				
			return;
		}
		
};

int main(){
	BST tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(5);
	tree.insert(0);
	tree.insert(4);
	tree.insert(6);
	tree.insert(7);
	tree.insert(3);
	//tree.insert(8);
	tree.check();
	//tree.FindMax(2);
	//tree.InOrder();
	//tree.searchNum(7);
	tree.deleteNum(5);
	tree.check();
	tree.InOrder();
	
	
	
	return 0;
}
