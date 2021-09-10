#include<iostream>
using namespace std;
class Stack;
class TreeNode;

class StackNode{
    friend class Stack;
    friend class TreeNode;
    private: StackNode *next=NULL; StackNode *pre; TreeNode *tnode;
    public: StackNode(TreeNode *tn){tnode=tn;}
};

class TreeNode{
    friend class Stack;
    public: 
        int value; 
        TreeNode *left=NULL; 
        TreeNode *right=NULL;
        TreeNode(int val){value=val;}
};


class Stack{
    private: StackNode *top; StackNode *tail=NULL;
    public:
        void Push(TreeNode *val);
        TreeNode *Pop(){
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



void Stack::Push(TreeNode *val){
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