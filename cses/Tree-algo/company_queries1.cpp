#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ar[200001];
int n,q,m;
int dp[200001][20];
int parent[200001];

void binarylifting(){
    dp[1][0]=-1;
    for(int i=2;i<=n;i++){
        dp[i][0]=parent[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    
}
int main()
{
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        cin>>parent[i];
    }
    
    
    m=int(log2(n));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    
    binarylifting();
    
    while(q--){
        int node , k;
        cin>>node>>k;
        
        while(k > 0 && node!=-1){
            int j=int(log2(k));
            node=dp[node][j];
            k-=(1<<j);
        }
        cout<<node<<endl;
    }
}