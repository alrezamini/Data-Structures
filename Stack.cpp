#include<iostream>
using namespace std;
class Stack;

class Node{
    friend class Stack;
    private: int value; Node *next=NULL; Node *pre;
    public: Node(int val){value=val;}
};

class Stack{
    private: Node *top; Node *tail=NULL;
    public:
        void Push(int);
        int Pop();
        void Print();
};

int main(){
    Stack obj;
    obj.Push(2);
    obj.Push(3);
    obj.Push(4);
    cout<<obj.Pop();
}

void Stack::Push(int val){
    Node *new_node=new Node(val);
    if(tail!=NULL){
        new_node->pre=top;
        top->next=new_node;
        top=new_node;
    }
    else{top=new_node;tail=new_node;new_node->pre=NULL;}
}

/*void Stack::Print(){
    while(tail!=NULL){
        cout<<"\t"<<"|"<<"\t"<<tail->value<<"\t"<<"|"<<"\n";
        tail=tail->next;
    }
}
*/

int Stack::Pop(){
    Node *pre = top->pre;
    delete pre->next;
    top=pre;
    return top->value;
}