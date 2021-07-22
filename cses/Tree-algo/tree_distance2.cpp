
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
vector<int>ar[200001];
int vis[200001];
int subco[200001];
int dis[200001];
long long int ans[200001];
int n,a,b;
int dfs(int src,int p){
    
    vis[src]=1;
    dis[src]=dis[p]+1;
    
    for(int child:ar[src]){
        if(!vis[child]){
            subco[src]+=dfs(child,src);
        }
    }
    subco[src]+=1;
    return subco[src];
}

void dfs1(int node,int par){
    for(int child:ar[node]){
        if(child!=par){
            ans[child]=ans[node]-subco[child]+n-subco[child];
            dfs1(child,node);
        }
    }
}
int main() {
    long long int parent_sum=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dis[0]=-1;
    dfs(1,0);
    
    for(int i=1;i<=n;i++)
    {
        parent_sum+=dis[i];
    }
    
    ans[1]=parent_sum;
    
    dfs1(1,0);
    
    for(int i=1;i<=n;i++)
    {
       cout<<ans[i]<<" ";
    }
    
    
    
}
