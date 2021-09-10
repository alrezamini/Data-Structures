#include<iostream>
#include"Explicit-Stack.h"
using namespace std;

// EXplicit Stack Used In Traversing Tree (Postorder)

class TreeTraversals{
    private: Stack stack_object;
    public:
        void Postorder(TreeNode *r);
};

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    TreeTraversals object;
    object.Postorder(root);

}

void TreeTraversals::Postorder(TreeNode *r){
    if((r->left!=NULL)||(r->right!=NULL)){
        while(r!=NULL){
            stack_object.Push(r);
            if(r->left==NULL){break;}
            r=r->left;
        }
        while(stack_object.CheckStatus()!="empty"){
            TreeNode *t = stack_object.Pop();
            if(t->right!=NULL){cout << t->right->value<<"   ";} 
            cout<<t->value<<"   ";
        }
    }
    cout<<endl;
}