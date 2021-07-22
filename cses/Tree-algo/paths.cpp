#include <bits/stdc++.h>
using namespace std;
const int N=3e5+20;
int n,m,u,v,i,vis[N],dp[26][N],ans;
vector <int> adj[N];
char a[N];
bool cycle;
 
void dfs(int node)
{
	vis[node]=1;
	dp[a[node]-'a'][node]++;
	for(auto child:adj[node])
	{
		if(vis[child]==1) cycle=true;
		else if(not vis[child]) dfs(child);
		for(int i=0;i<26;i++) dp[i][node]=max(dp[i][node],(a[node]==i+'a')+dp[i][child]);
	}
	for(int i=0;i<26;i++) ans=max(ans,dp[i][node]);
	vis[node]=2;
}
 
int main()
{
	scanf("%d%d %s",&n,&m,a+1);
	
	while(m--) scanf("%d%d",&u,&v),adj[u].push_back(v);
	
	for(i=1;i<=n;i++)
		if(not vis[i]) dfs(i);
	
	if(cycle) printf("-1");
	else printf("%d",ans);
}