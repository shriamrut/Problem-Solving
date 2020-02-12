#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long int dp[251][51];
int main() {
    IOS;
    memset(dp,0,sizeof(dp));
    vector<int>c;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>x;
        c.push_back(x);
    }
    for(int i=0;i<m;i++) 
        dp[0][i]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(i-c[j]>=0)
                dp[i][j]=dp[i][j-1]+dp[i-c[j]][j];
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[n][m-1];
    return 0;
}
