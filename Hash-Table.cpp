#include<iostream>
using namespace std;

// Using Chaining Method In Hashing In Order To Avoid Collision

class Node{
    friend class HashTable;
    Node *next=NULL;int value=0;
    Node(int val){value=val;}
    Node(){}
};

class HashTable{
    Node *array=new Node[10];
    public:
        void Hash(int);        // Insert Your Value To Get The Key
        int Print(int val);
};

int main(){
    HashTable obj;
    obj.Hash(15);       // ِYour Value = Your Key % 10
    obj.Hash(35);       // ِYour Value = Your Key % 10
    obj.Hash(11);
    obj.Hash(1);
    obj.Print(12);
}

void HashTable::Hash(int val){
    int result=val%10;
    if(array[result].value!=0){
        if(array[result].next==NULL){array[result].next=new Node(val);return;}
        Node *temp_array=array[result].next;
        for(temp_array;temp_array->next!=NULL;temp_array=temp_array->next){
            continue;
        }
        array[result].next=new Node(val);
    }
    else{array[result]=Node(val);}
}

int HashTable::Print(int val){
    int cell = val%10;
    if(array[cell].value==0){cout<<"Your Hashed Key Not Found"<<endl;return 0;}
    if(array[cell].next==NULL){cout<<"Your Hashed Key Is "<<array[cell].value<<endl;return 0;}
    else{
        cout<<"Your Hashed Key Is "<<cell<<"     ->  "<<array[cell].value<<"  ";
        Node *temp_array=array[cell].next;
        while(temp_array!=NULL){
            cout<<"  ->  "<<temp_array->value<<"  ";
            temp_array=temp_array->next;
        }
    }
    cout<<endl;
}