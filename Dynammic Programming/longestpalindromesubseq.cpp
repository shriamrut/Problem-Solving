//lOnGeSt PaLlInDrOmE sUbseq
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 10000000007
using namespace std;
void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
int main()
{
fast();
int j;
string s;
cin>>s;
int n=s.size();
int dp[n+1][n+1];
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		dp[i][j]=0;
}
for(int i=0;i<n;i++)
	dp[i][i]=1;
for(int len=1;len<=n;len++)
	{
		for(int i=0;i<=n-len-1;i++)
			{
				j=i+len;
				if(s[i]==s[j]&&len==1)
					dp[i][j]=2;
				else if(s[i]==s[j])
					dp[i][j]=dp[i+1][j-1]+2;
				else
					{
						dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
					}
			}
	}
for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
cout<<dp[0][n-1]<<"\n";                                                                                                                                  
return 0;
}
