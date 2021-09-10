#include<iostream>
using namespace std;

class MaxHeap{
    private:int *array;int inc=0;int array_size;
    public:
        void CreateArray(int size);     //Defining The Array And Prefered Size Of It
        void CheckHeap();            // Checking If The Child Nodes Are Not Bigger Than Parent Node
        void Add(int val);
        void Print();
};

int main(){
    MaxHeap object;
    object.CreateArray(10);
    object.Add(12);
    object.Add(8);
    object.Add(15);
    object.Add(1);
    object.Add(5);
    object.Add(4);
    object.Add(19);
    object.Add(2);
    object.Print();
}

void MaxHeap::CreateArray(int size){
    array = new int[size];
    array_size=size;
}

void MaxHeap::Add(int val){
    if(inc!=array_size){
        *(array+inc)=val;
        ++inc;
        if(inc>1){CheckHeap();}
    }
    else{cout<<"Can Not Add Any More Elements To The Array";}
}

void MaxHeap::CheckHeap(){
    int temp_inc=inc-1;
    while( *(array+temp_inc) > *(array+(temp_inc/2)) ){
        int temp=*(array+temp_inc);
        *(array+temp_inc)=*(array+(temp_inc/2));
        *(array+(temp_inc/2))=temp;
        temp_inc=(temp_inc)/2;
    }
}

void MaxHeap::Print(){
    for(int x=0;x<inc;++x){
        cout<<*(array+x)<<"   ";
    }
    cout<<endl;
}