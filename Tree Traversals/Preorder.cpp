#include<iostream>
#include"Explicit-Stack.h"
using namespace std;

// EXplicit Stack Used In Traversing Tree (Preorder)

class TreeTraversals{
    private: Stack stack_object;
    public:
        void Preorder(TreeNode *r);
};

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    TreeTraversals object;
    object.Preorder(root);

}

void TreeTraversals::Preorder(TreeNode *r){
    if((r->left!=NULL)||(r->right!=NULL)){
        while(r!=NULL){
            stack_object.Push(r);
            cout<<r->value<<"   ";
            r=r->left;
        }
        while(stack_object.CheckStatus()!="empty"){
            TreeNode *t = stack_object.Pop();
            if(t->right!=NULL){cout << t->right->value<<"   ";} 
        }
    }
    cout<<endl;
}