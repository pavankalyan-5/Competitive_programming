#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>ar[200001];
int vis[200001];
int subco[200001];

int dfs(int src){
    
    vis[src]=1;
    
    for(int child:ar[src]){
        if(!vis[child]){
            subco[src]+=dfs(child);
        }
    }
    subco[src]+=1;
    return subco[src];
}
int main() {
    int n,x;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        ar[x].push_back(i);
        ar[i].push_back(x);
    }
    
    dfs(1);
    for(int i=1;i<=n;i++)
    cout<<subco[i]-1<<" ";
}