#include<iostream>
using namespace std;

class MaxHeap{
    private:int *array;int inc=0;int array_size;
    public:
        void CreateArray(int size);     // Defining The Array And Prefered Size Of It
        void CheckHeap();              // Checking If The Parent Node Is Bigger Than Child Nodes
        void Add(int val);
        void Print();
        int HeapSort();              // It Retuens The Maximum Number
        void Swap(string,int *,int);
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
    int num = object.HeapSort();
    cout<<"The Maximum Number In Heap Array : "<<num<<endl;
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
    cout<<"MaxHeap Array : "<<endl;
    for(int x=0;x<inc;++x){
        cout<<*(array+x)<<"   ";
    }
    cout<<endl;
}

int MaxHeap::HeapSort(){
    int temp_root=*(array+0);
    *(array+0)=*(array+(inc-1));
    *(array+(inc-1))=temp_root;
    inc--;

    int temp_inc=0;
    while( (2*temp_inc+1)<=(inc-1) && *(array+temp_inc)<*(array+(2*temp_inc+1)) ){
        int max=*(array+(2*temp_inc+1));
        int temp;
        if((2*temp_inc+2)<=inc-1){
            if(*(array+(2*temp_inc+2))>max){
                max=*(array+(2*temp_inc+2));
                Swap("child2",&temp_inc,max);
            }
            else{
                Swap("child1",&temp_inc,max);
            }
        }
        else{
            Swap("child1",&temp_inc,max);
        }
    }
    return temp_root;
}


void MaxHeap::Swap(string st,int *temp_inc,int max){
    int t=*(temp_inc);
    if(st=="child2"){
        *(array+(2*t+2))=*(array+(t));
        *(array+(t))=max;
        *temp_inc=(2*t+2);
    }
    else{
        *(array+(2*t+1))=*(array+(t));
        *(array+(t))=max;
        *temp_inc=(2*t+1);
    }
}