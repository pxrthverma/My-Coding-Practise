#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    
    Node(int x)
    {
        data=x;
        this->next=NULL;
        this->prev=NULL;
    }
};



void print(Node* temp)
{
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<"    ";
        temp=temp->next;
    }
    cout<<endl;
}

void push(Node* &top,Node* &mid,int data,int &count)
{
    Node*newNode = new Node(data);
    top->next=newNode;
    top=newNode;
    newNode->prev=top;
    count++;
    if(count&1)
    mid=mid->next;
}

void pop(Node* &head,Node*&mid,int &count)
{
    Node*temp=head;
    head=head->prev;
    delete(temp);
    head->next=NULL;
    count--;

    if(!count&1)
    mid=mid->prev;
}

int main()
{
    int count=0;

    Node*dummy=new Node(-1);
    Node*top=dummy;
    Node*bottom=dummy;
    Node*mid=top;
    
    push(top,mid,10,count);
    bottom=bottom->next;
    push(top,mid,20,count);
    push(top,mid,30,count);

    pop(top,mid,count);
    print(bottom);
    cout<<endl<<"count: "<<count;
    cout<<endl<<"mid: "<<mid->data;
}

