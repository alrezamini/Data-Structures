#include<iostream>
using namespace std;
class Stack;
class BSTnode;

class StackNode{
    friend class Stack;
    friend class BSTnode;
    private: StackNode *next=NULL; StackNode *pre; BSTnode *tnode;
    public: StackNode(BSTnode *tn){tnode=tn;}
};

class BSTnode{
    friend class BST;
    friend class Stack;
    private:int value;BSTnode *left=NULL;BSTnode *right=NULL;
    public:BSTnode(int val){value=val;}
};

class Stack{
    private: StackNode *top; StackNode *tail=NULL;
    public:
        void Push(BSTnode *val);
        BSTnode *Pop(){
            if(top->pre!=NULL){
                StackNode *pre = top->pre;
                delete pre->next;
                StackNode *top_temp = top;
                top=pre;
                return top_temp->tnode;
            }else{tail=NULL;return top->tnode;}
        }
        string CheckStatus();
};



void Stack::Push(BSTnode *val){
    StackNode *new_node=new StackNode(val);
    if(tail!=NULL){
        new_node->pre=top;
        top->next=new_node;
        top=new_node;
    }
    else{top=new_node;tail=new_node;new_node->pre=NULL;}
}

string Stack::CheckStatus(){
    string result=(tail!=NULL)?"not_empty":"empty";
    return result;
}