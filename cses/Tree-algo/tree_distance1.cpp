#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200001];
int vis[200001];
int dis1[200001],dis2[200001];
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

void distance1(int node,int p)
{
    dis1[node]=1+dis1[p];
    
    for(int child:ar[node])
        if(child!=p)
            distance1(child,node);
}

void distance2(int node,int p)
{
    dis2[node]=1+dis2[p];
    
    for(int child:ar[node])
        if(child!=p)
            distance2(child,node);
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
    
    dis1[0]=dis2[0]=-1;
    
    int firstend=maxnode;
    dfs(maxnode,0);
    
    int secondend=maxnode;
    
    distance1(firstend,0);
    
    distance2(secondend,0);
    
    for(int i=1;i<=n;i++)
    cout<<max(dis1[i],dis2[i])<<" ";
    
    
}