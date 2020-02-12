#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,w,t;
    cin>>t;
    while(t--) {
        cin>>n>>w;
        int weights[n],values[n];
        int dp[n+1][w+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            cin>>values[i];
        for(int i=0;i<n;i++)
            cin>>weights[i];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=w;j++) {
                if(j==0||i==0)
                    dp[i][j]=0;
                else if(weights[i-1]>w)
                    dp[i][j]=dp[i-1][j];
                else {
                    dp[i][j]=max(dp[i-1][w-weights[i-1]]+values[i-1],dp[i-1][j]);
                }
            }
        }
        cout<<dp[n][w]<<"\n";
    }
}
