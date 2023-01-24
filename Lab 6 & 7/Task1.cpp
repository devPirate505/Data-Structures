// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
	class node {
	public:
	int data;
	node* left, *right;
	node(int data){
		this->data=  data;
		left= right= NULL;
		}
	};
	
class BinarySearchTree{
	private: 
    //private data member and methods
	node* root;
	node* Insert( node* root, int val);
	node* Delete(node* root,int data);
	node* InOrderTraversal( node* root);
	node* PreOrderTraversal( node* root);
	node* PostOrderTraversal( node* root);
	node* FindMax(node* root);
	int numOfNode(node* root, int val);
	public:
	int nodeCount = 0;
	BinarySearchTree(){
		root= NULL;
	}
	void Insert(int val){
		
   	Insert(this->root,  val);
   }
   
	void	Delete(int val){
   Delete(this->root, val);
   }
   
   int numOfNode(int val){
		return numOfNode(this->root, val);
   }
	void InOrderTraversal(){
        InOrderTraversal( this->root);
	}
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
	}
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
	}
};
int main (){
	BinarySearchTree tree1, tree2;
  	tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
    
    int n = 2;
    cout << "Nodes at height " << n << " are: ";
    cout << tree1.numOfNode(n);
}
node* BinarySearchTree::Insert(node* r, int val ){
 if (r==NULL)
	{
		node* t= new node(val);
		if (r==root)
			root=t;
		else
		r=t;
	}
	else if (r->data== val){
		cout<<"Record already exist" << val;
	}
	else if (val < r->data) // insert on left s
	r->left = Insert(r->left , val );
	else if (val > r->data)
		r->right= Insert( r->right,val);
	return r;
}
node * BinarySearchTree::Delete(node* r, int data)
{
//	node * r= root1;
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
            node* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
node * BinarySearchTree::InOrderTraversal( node* r){
	 if (r == NULL)
        return NULL;
    //first recur on left child 
    InOrderTraversal(r->left);
   //then print the data of node 
    cout << " "<< r->data << " -> ";
  // now recur on right child 
    InOrderTraversal(r->right);
}

node* BinarySearchTree::FindMax(node* r){	
	while(r->right!=NULL){
		r = r->right;
	}
	return r;	
}
node* BinarySearchTree::PreOrderTraversal(node* r){
	 if (r == NULL)
        return NULL;
    
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);	
}
node* BinarySearchTree::PostOrderTraversal(node* r){
	 if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);	
    cout << " "<< r->data << " -> ";
}

int BinarySearchTree::numOfNode(node* r, int val){
	static int h = 0;
	if(val == 0){
		if(r != NULL){
			nodeCount == 1;
		}else{
			nodeCount == 0;
		}
		return nodeCount;
	}else{
		if(h == val){
			nodeCount += 1;
			
			return nodeCount;
		} 
		
		if(r->left != NULL){
			h++;
			numOfNode(r->left, val);
			h--;
		}
		if(r->right != NULL){
			h++;
			numOfNode(r->right, val);
			h--;
		}
	}
	return nodeCount;
}

