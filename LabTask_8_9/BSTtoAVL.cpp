#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* left, *right;
	node(int data){
		this->data=  data;
		left= right= NULL;
		}
};

class AVLnode{
	public:
	int data;
	AVLnode* left, *right;
    int height;
	AVLnode(int data){
		this->data=  data;
		left= right= NULL;
		height=0;
		}
};

class AVLTree{
	private: 
    //private data member and methods
	AVLnode* root;
	AVLnode* Insert( AVLnode* root, int val);
	AVLnode* PreOrderTraversal( AVLnode* root);
	AVLnode* FindMax(AVLnode* root);
		// Rotation
    AVLnode* singleRightRotate(AVLnode* &t);
    AVLnode* singleLeftRotate(AVLnode* &t);
    AVLnode* doubleRightLeftRotate(AVLnode* &t);
    AVLnode* doubleLeftRightRotate(AVLnode* &t);
    int getBalance(AVLnode* t);
	public:
	AVLTree(){
		root= NULL;
	}
	void	Insert(int val){
   	root= Insert(this->root,  val);
   }
   
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
	}
	 int height(AVLnode* t)
    {
        return (t == NULL ? -1 : t->height);
    }
     
	int length(AVLnode* r){
    	int  lh=0,rh=0;
    	if(r==NULL)
		 return -1;
    	if(r->left!=NULL){
    		lh++;
    		lh+=length(r->left);
		}
		if(r->right!=NULL){
    		rh++;
    		rh+=length(r->right);
		}
		if(rh>lh) return rh;
		else return lh;
	}
	
	int treeHeight(AVLnode *t)
	{
	int static l_height=0;
	int static r_height=0;
    if (t == NULL)
        return -1;
    else
    {
    l_height = treeHeight(t->left);
       r_height = treeHeight(t->right);
        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
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
	node* FindMax(node* root);
	AVLTree BSTtoAVL(node* root);
	public:
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
	
	AVLTree BSTtoAVL(){
		BSTtoAVL(this->root);
	};
};



int main (){
	BinarySearchTree tree1;
	AVLTree t;
  	tree1.Insert(2);
    tree1.Insert(1);
    tree1.Insert(4);
    tree1.Insert(5);
    tree1.Insert(7);
    tree1.Insert(3);
    tree1.Insert(10);
    tree1.Insert(9);
	tree1.Insert(8);
	tree1.Insert(6);
	
	cout << "In BST form: ";
    tree1.PreOrderTraversal();
    t = tree1.BSTtoAVL();
    cout << endl;
    cout << "\nIn CBT form: ";
    t.PreOrderTraversal();
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

node* BinarySearchTree::PreOrderTraversal(node* r){
	 if (r == NULL)
        return NULL;
    
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);	
}

node* BinarySearchTree::FindMax(node* r){	
	while(r->right!=NULL){
		r = r->right;
	}
	return r;	
}

AVLnode* AVLTree::Insert(AVLnode* t, int val ){
 if (t==NULL)
	{
		 t= new AVLnode(val);
	}
	else if (t->data== val){
		cout<<"Record already exist"<<val<<endl;
	}
	else if (val < t->data) // insert on left s
	{
		t->left = Insert(t->left , val );
		 int bf= height(t->left) - height(t->right);
			if(bf == 2)
            {
                if(val < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleLeftRightRotate(t);
            }
	}
	else if (val > t->data) // Right side
		{
		t->right= Insert( t->right,val);
		
		int bf=height(t->right) - height(t->left);
		   
		    if(bf == 2)
            {
                if(val > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleRightLeftRotate(t);
            }
	}
	t->height = max(height(t->left), height(t->right))+1;
	return t;
}

AVLnode* AVLTree::doubleRightLeftRotate(AVLnode* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    
    
AVLnode* AVLTree::doubleLeftRightRotate(AVLnode* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
    
AVLnode* AVLTree::singleRightRotate(AVLnode* &t)
    {
        AVLnode* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }
AVLnode* AVLTree::singleLeftRotate(AVLnode* &t)
    {
        AVLnode* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->right), t->height)+1 ;
        return u;
    }
    
AVLnode* AVLTree::FindMax(AVLnode* r){	
	while(r->right!=NULL){
		r= r->right;
	}
	return r;	
}
AVLnode* AVLTree::PreOrderTraversal(AVLnode* r){
	 if (r == NULL)
        return NULL;
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);	
}

AVLTree BinarySearchTree::BSTtoAVL(node* r){
	AVLTree static t;
	if (r == NULL)
    	return t;
	t.Insert(r->data);
	
    BSTtoAVL(r->left);
    BSTtoAVL(r->right);
    return t;
}

