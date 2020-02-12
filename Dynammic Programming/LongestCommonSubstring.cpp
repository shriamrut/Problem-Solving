#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int res=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
