#include<iostream>
#include<assert.h>

using namespace std;

class MinHeap{
	private:
		struct node{
			int key;
		};
		node *arr;
		int capacity;
		int totalItems;
		
		void doubleCapacity(){
			if(this->arr == NULL){
				this->arr = new node[1];
				this->capacity = 1;
				return;
			}
			
			int newCapacity = capacity * 2;
			node *newArr = new node[newCapacity];
			for(int i = 0; i < this->totalItems; i++){
				newArr[i] = this->arr[i];
			}
			
			delete this->arr;
			this->capacity = newCapacity;
			this->arr = newArr;
		}
		
		void shiftUp(int index){
			if(index < 1){
				return;
			}
			int parent = (index-1)/2;
			if(this->arr[index].key < this->arr[parent].key){
				swap(this->arr[index], this->arr[parent]);
				shiftUp(parent);
			}
			return;
		}
		
		void shiftDown(int index){
			int maxIndex = -1;
			
			int lChildIndex = index * 2+1;
			int rChildIndex = (index * 2) + 2;
			
			if(lChildIndex < totalItems){
				if(arr[index].key > arr[lChildIndex].key){
					maxIndex = lChildIndex;
				}
			}
			
			if(rChildIndex < totalItems){
				int newindex = (maxIndex == -1 ? index : maxIndex);
				if(arr[newindex].key > arr[rChildIndex].key){
					maxIndex = rChildIndex;
				}
			}
			
			if(maxIndex == -1){
				return;	
			}
			swap(arr[index], arr[maxIndex]);
			shiftDown(maxIndex);
		}
	public:
		
		MinHeap(){
			this->arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;
		}
		
		MinHeap(int _capacity){
//			assert(_capacity >= 1);
			this->arr = new node[_capacity];
			this->capacity = _capacity;
			this->totalItems = 0;
		}
		
		void insert(int key){
			if(this->totalItems == this->capacity){
				doubleCapacity();
			}
			this->arr[totalItems].key = key;
			shiftUp(totalItems);
			this->totalItems++;
		}
		
		void getMin(int &key){
			assert(totalItems != 0);
			key = this->arr[0].key;
		}
		
		void deleteMin(){
			assert(totalItems != 0);
			swap(arr[0], arr[this->totalItems-1]);
			totalItems--;
			shiftDown(0);
		}
		
		bool isEmpty() const{
			return (totalItems == 0);
		}
		
		void deleteAll(){
			if(this->arr != NULL){
				delete[]arr;
				arr = NULL;
				this->capacity = 0;
				this->totalItems = 0;
			}
		}
		void InOrder(int index){
		
		if (index>=totalItems)
		return;
		InOrder(index*2 +1);
		cout<<this->arr[index].key<<" < " ;
		InOrder(index*2 +2);
	}
		~MinHeap(){
			deleteAll();
		}
};

class BSTnode {
    public:
    	int data;
    	BSTnode* left, *right;
   		BSTnode(int data){
        	this->data=  data;
        	left= right= NULL;
        	}
};

class BinarySearchTree{
    private:
    BSTnode* root;
    BSTnode* Insert( BSTnode* root, int val);
    BSTnode* Delete(BSTnode* root,int data);
    BSTnode* InOrderTraversal( BSTnode* root);
    BSTnode* PreOrderTraversal( BSTnode* root);
    BSTnode* FindMax(BSTnode* root);
	MinHeap BSTtoMinHeap(BSTnode* root);
	void BSTtoArr(BSTnode* root, int arr[]);
	
    public:
    int numOfNodes = 0;
    BinarySearchTree(){
        root= NULL;
    }
    void Insert(int val){
       Insert(this->root,  val);
  	}	
   
    void Delete(int val){
   		Delete(this->root, val);
   }
    void InOrderTraversal(){
        InOrderTraversal(this->root);
    }
    void PreOrderTraversal(){
        PreOrderTraversal(this->root);
    }
    MinHeap BSTtoMinHeap(){
        return BSTtoMinHeap(this->root);
    }
    void BSTtoArr(int arr[]){
    	BSTtoArr(this->root, arr);
	}
};

MinHeap ArrToHeap(int index, int arr[], int size);

int main(){

	BinarySearchTree tree1;
	tree1.Insert(4);
	tree1.Insert(2);
	tree1.Insert(6);
	tree1.Insert(1);
	tree1.Insert(3);
	tree1.Insert(5);
	tree1.Insert(7);
	tree1.InOrderTraversal();
	cout << endl;
	
//	MinHeap heap;
//	heap = tree1.BSTtoMinHeap();
//	
//	while (!heap.isEmpty())
//	{
//		int s;
//		heap.getMin(s);
//		cout << s << endl;
//		heap.deleteMin();
//	}
	int n = tree1.numOfNodes;
	int arr[n];
	int* p = arr;
	
	tree1.BSTtoArr(p);

	MinHeap heap;
	heap = ArrToHeap(0, arr, n-1);
//	while (!heap.isEmpty())
//	{
//		int s;
//		heap.getMin(s);
//		cout << s << endl;
//		heap.deleteMin();
//	}
	heap.InOrder(0);
}

BSTnode* BinarySearchTree::Insert(BSTnode* r, int val ){
 if (r==NULL)
    {
        BSTnode* t= new BSTnode(val);
        if (r==root){
            root=t;
            numOfNodes++;
        }else{
        r=t;
        numOfNodes++;
    	}
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}
BSTnode * BinarySearchTree::Delete(BSTnode* r, int data)
{
//    BSTnode * r= root1;
    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        //No child
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        //One child on left
        else if(r->right == NULL)
        {
            BSTnode* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            BSTnode* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            BSTnode* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
BSTnode * BinarySearchTree::InOrderTraversal(BSTnode* r){
     if (r == NULL)
        return NULL;
    //first recur on left child
    InOrderTraversal(r->left);
   //then print the data of BSTnode
    cout << " "<< r->data << " -> ";
  // now recur on right child
    InOrderTraversal(r->right);
}

BSTnode* BinarySearchTree::FindMax(BSTnode* r){    
    while(r->right!=NULL){
        r = r->right;
    }
    return r;    
}
BSTnode* BinarySearchTree::PreOrderTraversal(BSTnode* r){
    if (r == NULL)
    	return NULL;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
MinHeap BinarySearchTree::BSTtoMinHeap(BSTnode* r){
	static MinHeap heap;
	if (r == NULL)
    	return NULL;
    heap.insert(r->data);
    BSTtoMinHeap(r->left);
    BSTtoMinHeap(r->right);
    
    return heap;
}
void BinarySearchTree::BSTtoArr(BSTnode* r, int arr[]){
	static int i = 0;
	if (r == NULL)
    	return;
    arr[i] = r->data;
    i++;
    BSTtoArr(r->left, arr);
    BSTtoArr(r->right, arr);
    return;
}

MinHeap ArrToHeap(int index, int arr[], int size){
	static MinHeap heap;
	if(index > size)
		return NULL;
	heap.insert(arr[index]);
	ArrToHeap(index*2 +1, arr, size);
	ArrToHeap(index*2 +2, arr, size);
	
	return heap;
}
