#include<iostream>
using namespace std;
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
    //BSTnode class

    //private data members and methods
    BSTnode* root;
    BSTnode* Insert( BSTnode* root, int val);
    BSTnode* Delete(BSTnode* root,int data);
    BSTnode* InOrderTraversal( BSTnode* root);
    BSTnode* PreOrderTraversal( BSTnode* root);
    BSTnode* PostOrderTraversal( BSTnode* root);
    BSTnode* FindMax(BSTnode* root);
    public:
    BinarySearchTree(){
        root= NULL;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   
    void    Delete(int val){
   Delete(this->root, val);
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
    tree1.Delete(10);
    cout<<"In Order Print (left--Root--Right)"<<endl;
    tree1.InOrderTraversal();
    cout<<"\n-----------------------"<<endl;
    cout<<"Pre Order Print (Root--left--Right)"<<endl;
    tree1.PreOrderTraversal();    
    cout<<"\n-----------------------"<<endl;
    cout<<"Post Order Print (left--Right--Root)"<<endl;
    tree1.PostOrderTraversal();
    return 0;
}
BSTnode* BinarySearchTree::Insert(BSTnode* r, int val ){
 if (r==NULL)
    {
        BSTnode* t= new BSTnode(val);
        if (r==root)
            root=t;
        else
        r=t;
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
BSTnode * BinarySearchTree::InOrderTraversal( BSTnode* r){
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
        r= r->right;
    }
    return r;    
}
BSTnode* BinarySearchTree::PreOrderTraversal( BSTnode* r){
     if (r == NULL)
        return NULL;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
BSTnode* BinarySearchTree::PostOrderTraversal(BSTnode* r){
     if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
}
