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
	node* FindSibling(node* root, int val);
	node* Ancestors(node* root, int val);
	node* Decendent(node* root, int val);
	public:
	void Insert(int val){
		Insert(this->root,  val);
   }
   
	void Delete(int val){
		Delete(this->root, val);
	}
   
	void InOrderTraversal(){
        InOrderTraversal( this->root);
	}
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
	}
    void PostOrderTraversal(){
        PostOrderTraversal(this->root);
	}
	node* FindSibling(int val){
		FindSibling(this->root, val);	
	}
	
	node* Ancestors(int val){
		Ancestors(this->root, val);
	}
	node* Decendent(int val){
		Decendent(this->root, val);
	}
};
int main (){
	BinarySearchTree tree1;
  	tree1.Insert(50);
    tree1.Insert(17);
    tree1.Insert(72);
    tree1.Insert(12);
    tree1.Insert(23);
    tree1.Insert(54);
    tree1.Insert(76);
    tree1.Insert(9);
    tree1.Insert(14);
    tree1.Insert(19);
    tree1.Insert(67);
    
    tree1.InOrderTraversal();
    tree1.FindSibling(50);
    
    tree1.Ancestors(23);
    cout << endl;
    tree1.Decendent(17);
    
    
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

node* BinarySearchTree :: FindSibling(node* r, int val){
	if (r == NULL)
    	return NULL;
    
    if(r->data == val){
    	cout << endl << val << " is the root!\n";
    	return NULL;
	}
    if(r->left != NULL && r->left->data == val){
    	if(r->right != NULL){
    		cout << "\nSibling of " << val << " is " << r->right->data << endl;
			return NULL;	
		}else{
			cout << endl << val << " doesn't have any sibling!\n";
			return NULL;
		}
	}else if(r->right != NULL && r->right->data == val){
		if(r->left != NULL){
    		cout << "\nSibling of " << val << " is " << r->left->data << endl;
			return NULL;	
		}else{
			cout << endl << val << " doesn't have any sibling!\n";
			return NULL;
		}
	}
	FindSibling(r->left, val);
	FindSibling(r->right, val);
}

node* BinarySearchTree :: Ancestors(node* r, int val){
	static node* root = r;
	if (r == NULL)
    	return NULL;
    if(r->data == val){
    	return NULL;
	}
	
	if(r->left->data == val || r->right->data == val){
		cout << endl << r->data << " is an ancestor.";
		val = r->data;
		Ancestors(root, val);
		return NULL;
	}
	
	if(val < r->data){
		Ancestors(r->left, val);
	}
	
	if(val > r->data){
		Ancestors(r->right, val);
	}

}

node* BinarySearchTree :: Decendent(node* r, int val){
	if (r == NULL)
    	return NULL;
    	
    if(r->data == val){
    	if(r->left != NULL){
    		cout << endl << r->left->data << " is decendent of " << val;
		}
		if(r->right != NULL){
    		cout << endl << r->right->data << " is decendent of " << val;
		}
    	return NULL;
	}
	Decendent(r->left, val);
	Decendent(r->right, val);
}
