#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string str)
    {
        if(str.length()==0)
        {
            root->isTerminal=true;
            return;
        }

        TrieNode* child;
        int idx = str[0]-'a';

        if(root->children[idx])
        child = root->children[idx];

        else
        {
            root->children[idx] = child = new TrieNode(str[0]);
        }

        insertUtil(child, str.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string str)
    {
        if(str.length()==0)
        {
            return root->isTerminal;
        }

        TrieNode* child;
        int idx = str[0]-'a';

        if(root->children[idx])
        child = root->children[idx];

        else
        {
            return 0;
        }

        return searchUtil(child, str.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("abcbcbc");
    cout<<"done"<<endl;

    cout<<t->searchWord("abcbc");
}