#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 10000000007
using namespace std;
vector<char>c;
string s,t;
void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
int main()
{
fast();
cin>>s>>t;
int n=s.size();
int m=t.size();
int dp[n+1][m+1];
for(int i=0;i<=m;i++)
	dp[0][i]=0;
for(int i=0;i<=n;i++)
	dp[i][0]=0;
for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			{
				if(s[i-1]==t[j-1])
					{
						dp[i][j]=dp[i-1][j-1]+1;
					}
				else 
					{
						dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
					}
			}
	} 
/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
cout<<dp[n][m]<<"\n";
//printing the longest common subseqence using back tracking
int bti=n,btj=m;
while(c.size()!=dp[n][m])
	{
		if(s[bti-1]==t[btj-1])
			{
				c.pb(s[bti-1]);
				bti=bti-1;
				btj=btj-1;
			}
		else 
			{
				if(dp[bti-1][btj]>dp[bti][btj-1])
						bti=bti-1;
				else
					btj=btj-1;
			}
	}
reverse(c.begin(),c.end());
for(int i=0;i<c.size();i++)
cout<<c[i];
return 0;
}

