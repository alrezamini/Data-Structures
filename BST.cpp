#include<iostream>
using namespace std;

// Binary Search Tree

class Node{
    friend class BST;
    private:int value;Node *left=NULL;Node *right=NULL;
    public:Node(int val){value=val;}
};

class BST{
    private:Node *root=NULL;
    public:
        int Add(int);
        string Check(Node *,Node *);
        void Recursive(Node *,Node *);
        int ReturnMax();
        int ReturnMin();
        void Search(int);
};

int main(){
    BST object;
    object.Add(9);
    object.Add(7);
    object.Add(8);
    object.Add(4);
    object.Add(5);
    cout<<"Maximum Number In BST : "<<object.ReturnMax()<<endl;
    cout<<"Minimum Number In BST : "<<object.ReturnMin()<<endl;
    object.Search(5);
}

int BST::Add(int val){
    Node *new_node=new Node(val);
    if(root!=NULL){
        Recursive(root,new_node);
    }
    else{root=new_node;}

}

void BST::Recursive(Node *r,Node *c){
    Node *temp_r=r;
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
    Node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->value;
}

int BST::ReturnMin(){
    Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->value;
}

void BST::Search(int val){
    Node *temp=root;
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