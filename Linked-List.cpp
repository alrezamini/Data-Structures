#include<iostream>
using namespace std;
class LinkList;

class Node{
    friend class LinkList;
    private: int value; Node *next=NULL;
    public: Node(int val){value=val;}
};

class LinkList{
    private:
        Node *current=NULL; Node *tail;
    public:
        void AddToList(int);
        void Print();
        void AddBetween(int,int);
        void Search(int);
        void Delete(int);
};

int main(){
    LinkList obj;
    obj.AddToList(3);
    obj.AddToList(4);
    obj.AddToList(5);
    obj.AddToList(6);
    obj.AddToList(7);
    obj.AddBetween(10,5);
    obj.Search(22);
    obj.Delete(6);
    obj.Print();
}

void LinkList::AddToList(int val){
    Node *new_node=new Node(val);
    if(current!=NULL){
        while(current!=NULL){
            if(current->next==NULL){break;}
            current=current->next;
        }
        current->next=new_node;
    }
    else{
        current=new_node;
        tail=new_node;
    }
}

void LinkList::Print(){
    while(tail!=NULL){
        cout<<tail->value<<"\t"<<"->\t";
        tail=tail->next;
    }
    cout<<"\n";
}

void LinkList::AddBetween(int val,int target){
    Node *new_node=new Node(val);
    Node *temp_tail=tail;
    while(temp_tail!=NULL){
        if(temp_tail->value==target){
            Node *temp_next=temp_tail->next;
            temp_tail->next=new_node;
            new_node->next=temp_next;
            break;
        }
        temp_tail=temp_tail->next;
    }
}

void LinkList::Search(int target){
    Node *temp_tail=tail;
    while(temp_tail!=NULL){
        if(temp_tail->value==target){cout<<"Number That Found Is "<<temp_tail->value<<endl;break;}
        temp_tail=temp_tail->next;
    }
    cout<<"Nothing Found !\n";
}

void LinkList::Delete(int target){
    Node *temp_tail=tail;
    while(temp_tail!=NULL){
        if(temp_tail->next->value==target){
            Node *temp_next = temp_tail->next->next;
            delete temp_tail->next;
            temp_tail->next=temp_next;
            cout<<"Deletion Successfully Done !\n";
            break;
        }
        temp_tail=temp_tail->next;
    }
}
