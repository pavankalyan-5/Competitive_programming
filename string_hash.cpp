#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll inv[100001];
ll dp[100001];
ll mod=1000000007;
ll power(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        res*=a;
        
        b/=2;
        a*=a;
    }
    return res;
}
void init(string s)
{
    ll p=31;
    ll p_pow=1;
    inv[0]=1;
    dp[0]=(s[0]-'a'+1);
    for(int i=1;i<s.size();i++)
    {
        p_pow=(p_pow * p)%mod;
        inv[i]=power(p_pow, mod-2);
        dp[i]=(dp[i-1]+(s[i]-'a'+1)*p_pow) % mod;
    }
}
ll substring(int L,int R)
{
    ll res=dp[R];
    if(L > 0)
    res-=dp[L];
    
    res=(res*inv[L])%mod;
    
    return res;
}

int main() {
    
    string s;
    cin>>s;
    init(s);
    cout<<substring(0,0);
    
}
