#include <bits/stdc++.h> 
using namespace std; 
  
  
struct trienode 
{ 
    struct trienode *child[26]; 
    int count;
    int end; 
}; 
  
struct trienode *getNode() 
{ 
    struct trienode *newnode =  new trienode; 
    newnode->count=newnode->end=0;
    for (int i = 0; i < 26; i++) 
    {
        newnode->child[i] = NULL;
    }
    return newnode; 
} 
  
void insert(struct trienode *root, string word) 
{ 
    struct trienode *curr = root; 
    
    int index;
    for(char x: word)
    {
        index=x-'a';
        if(curr->child[index]==NULL)
            curr->child[index]=getNode();
        curr->child[index]->count+=1;
        curr=curr->child[index];
    }
    curr->end+=1;
} 
  
int search(struct trienode *root, string word) 
{ 
     struct trienode *curr = root; 
    
    int index;
    for(char x: word)
    {
        index=x-'a';
        if(curr->child[index]==NULL)
            return false;
         curr=curr->child[index];
    }
    return curr->count ;
} 
  
int main() 
{ 
    int n;
    cout<<"enter no of strings:";
    cin>>n;
    string s;
    
    struct trienode *root = getNode(); 
    for (int i = 0; i < n; i++)
    {
        cin>>s;
       insert(root,s); 
    }
    cout<<"enter string to be searched for:";
    cin>>s;
    cout<<"the string "<< s <<" is occured "<<search(root,s)<<" times";
    return 0; 
} 

