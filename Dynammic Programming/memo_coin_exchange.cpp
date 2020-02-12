#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long int dp[251][51];
long int mem_getways(int n,int m,vector<int>&v) {
    if(n==0)    
        return 1;
    else if(n<0)
        return 0;
    else if(n>=1 && m<=0)
        return 0; 
    {
        if(dp[n][m]==-1) 
            dp[n][m]=mem_getways(n,m-1,v)+mem_getways(n-v[m-1],m,v);
        return dp[n][m];
    }
}
int main() {
    IOS;
    memset(dp,-1,sizeof(dp));
    vector<int>c;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>x;
        c.push_back(x);
    }
    cout<<mem_getways(n,m,c);
    return 0;
}
