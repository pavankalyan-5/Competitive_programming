
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
vector<int>ar[200001];
int vis[200001];
int c[200001];
int dis[200001];
set <int>*st[200001];
int ans[200001];
int n,a,b;

void dfs(int node,int par){
    
    int mx = 0;
	int mxnode = -1;
    
    for(int child:ar[node]){
        if(child!=par){
            dfs(child,node);
            
            if( st[child]->size() > mx )
		        mx = st[child]->size() , mxnode = child;
        }
    }
        
        if(mxnode == -1) st[node] = new set<int>();
	    else			 st[node] = st[mxnode];
	    
	st[node] -> insert(c[node]);
	
	for(int child : ar[node])
	if(child != par && child != mxnode)
	{
		for(int color : *st[child])
		st[node]->insert(color);
	}
	
	ans[node] = st[node] -> size();
	    
	    
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    
    for(int i=1;i<n;i++){
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    dfs(1,-1);
    
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
