#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    Node* left;
    Node* right;
    int data;
    Node(int data)
    {
        this->data==data;
        this->left=NULL;
        this->right=NULL;
    }

    Node* insert(Node* root, int data)
    {
        if(root==NULL)
        {
            root=new Node(data);
            return root;
        }
        
        if(data<root->data)
            root->left=insert(root->left,data);

        else
            root->right=insert(root->left,data);

        return root;
    }
};

int main()
{

}