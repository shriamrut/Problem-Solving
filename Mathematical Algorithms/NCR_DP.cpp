#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ll long long
#define ss second
#define mod 1000000007
using namespace std;
vector<ll>dp[1001];
int main() {
    ll t,n,r;
    dp[1]={1,1};
    for(ll i=2;i<1001;i++)
    {
        dp[i].pb(1);
        dp[i].pb(i);
        for(ll j=2;j<=i;j++)
        {
           ll a,b;
           if(i==j)
           {
               dp[i].pb(1);
               continue;
           }
           a=dp[i-1][j];
           b=dp[i-1][j-1];
           ll cmp=(a%mod+b%mod)%mod;
           dp[i].pb(cmp);
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        cout<<dp[n][r]<<endl;
    }
    return 0;
}
