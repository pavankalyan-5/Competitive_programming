#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200001];
int vis[200001];
int maxd,maxnode;
void dfs(int node,int d)
{
    vis[node]=1;
    if(d>maxd)
    maxd=d,maxnode=node;
    for(int child: ar[node])
    {
        if(vis[child]==0)
        {
            dfs(child,d+1);
        }
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
    maxd=-1;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    vis[i]=0;
    maxd=-1;
    dfs(maxnode,0);
    cout<<maxd;
}