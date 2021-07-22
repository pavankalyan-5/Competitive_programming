#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200001];
int vis[200001];
set<int>seen;
void dfs(int node,int par)
{
    for(int child:ar[node]){
        if(child!=par){
            dfs(child,node);
            
            if(seen.find(child)==seen.end() && seen.find(node)==seen.end()){
                seen.insert(child);
                seen.insert(node);
            }
        }
    }
    
  
   if(par!=-1 && seen.find(par)==seen.end() && seen.find(node)==seen.end()){
                seen.insert(node);
                seen.insert(par);
            }
    
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    dfs(1,-1);
    
    cout<<seen.size()/2;
}