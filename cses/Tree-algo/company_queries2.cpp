#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200001];
int depth[200001];
int n,q,m=20,x;
int dp[200001][20];


void dfs(int node,int par){
    depth[node]=1+depth[par];
    
    for(int child:ar[node]){
        if(child!=par){
            dp[child][0]=node;
            for(int i=1;i<m;i++){
                dp[child][i]=dp[dp[child][i-1]][i-1];
            }
             dfs(child,node);
        }
    }
}
int main()
{
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        ar[x].push_back(i);
        ar[i].push_back(x);
    }
    
    dfs(1,0);
    
    while(q--){
        int node1 , node2;
        cin>>node1>>node2;
        
        if(depth[node1] < depth[node2])
            swap(node1,node2);
        
       int k=depth[node1]-depth[node2];
       
       
       for(int i=m-1;i>=0;i--){
            if(k&(1<<i)){
                node1=dp[node1][i];
            }
        }
        
       
        
        if(node1==node2){
            cout<<node1<<endl;
            continue;
        }
        for(int i=m-1;i>=0;i--){
            if(dp[node1][i]!=dp[node2][i]){
                 node1=dp[node1][i];
                 node2=dp[node2][i];
            }
        }
       cout<<dp[node1][0]<<endl;
    }
}
