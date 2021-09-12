#include<iostream>
#include"Explicit-Stack.h"
using namespace std;

// Binary Search Tree

class BST{
    public:BSTnode *root=NULL;Stack stobject;
    public:
        int Add(int);
        string Check(BSTnode *,BSTnode *);
        void Recursive(BSTnode *,BSTnode *);
        int ReturnMax();
        int ReturnMin();
        void Search(int);
        void Inorder(BSTnode *);
};

int main(){
    BST object;
    object.Add(100);object.Add(98);
    object.Add(150);object.Add(95);
    object.Add(99);object.Add(149);
    object.Add(151);object.Add(92);
    object.Add(140);object.Add(139);
    object.Add(142);
    cout<<"Maximum Number In BST : "<<object.ReturnMax()<<endl;
    cout<<"Minimum Number In BST : "<<object.ReturnMin()<<endl;
    object.Search(5);
    cout<<"Inorder Traversal (Sort) : "<<endl;
    object.Inorder(object.root);
}

int BST::Add(int val){
    BSTnode *new_node=new BSTnode(val);
    if(root!=NULL){
        Recursive(root,new_node);
    }
    else{root=new_node;}

}

void BST::Recursive(BSTnode *r,BSTnode *c){
    BSTnode *temp_r=r;
    if(c->value>temp_r->value){
        if(temp_r->right==NULL){
            r->right=c;
            return;
        }
        Recursive(temp_r->right,c);
    }
    if(c->value<temp_r->value){
        if(temp_r->left==NULL){
            r->left=c;
            return;
        }
        Recursive(temp_r->left,c);
    }
}

int BST::ReturnMax(){
    BSTnode *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->value;
}

int BST::ReturnMin(){
    BSTnode *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->value;
}

void BST::Search(int val){
    BSTnode *temp=root;
    string path;
    while(temp!=NULL){
        if(val==temp->value){cout<<"Your Number Found , The Path Is : "<<path<<endl;return;}
        if(val>temp->value){
            temp=temp->right;
            path+="->Right";
            continue;
        }
        else{temp=temp->left;path+="->Left";continue;}
    }
    cout<<"Your Number Not Found !"<<endl;
}

void BST::Inorder(BSTnode *r){
    BSTnode *temp=r;
    for(temp;temp!=NULL;temp=temp->left){
        stobject.Push(temp);
    }
    while(stobject.CheckStatus()=="not_empty"){
        BSTnode *b=stobject.Pop();
        cout<<b->value<<"  ";
        if(b->right!=NULL){Inorder(b->right);}
        else{continue;}
    }
}