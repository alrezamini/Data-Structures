#include<iostream>
using namespace std;

class Node{
    friend class Queue;
    private: int value; Node *next=NULL;
    public: Node(int val){value=val;}
};

class Queue{
    private: Node *head=NULL; Node *tail=NULL;
    public: 
        void Enqueue(int);
        void Dequeue();
        void QueueStatus();
        void Print();
};

int main(){
    Queue object;
    object.Enqueue(12);
    object.Enqueue(14);
    object.Enqueue(16);
    object.Dequeue();
    object.Print();
}

void Queue::Enqueue(int val){
    Node *new_node=new Node(val);
    if((head!=NULL)&&(tail!=NULL)){
        tail->next=new_node;
        tail=new_node;
    }
    else{
        head=new_node;
        tail=new_node;
    }
}

void Queue::Dequeue(){
    if(head!=NULL){
        Node *temp=head->next;
        delete head;
        head=temp;
    }
    else{QueueStatus();}
}

void Queue::Print(){
    if(head!=NULL){
        cout<<"Front Of The Queue Is : "<<head->value<<endl;
        cout<<"Rear Of The Queue Is : "<<tail->value<<endl;
    }
    QueueStatus();
}

void Queue::QueueStatus(){
    string result=(head!=NULL)?"Queue Is Not Empty":"Queue Is Empty";
    cout<<result<<endl; 
}