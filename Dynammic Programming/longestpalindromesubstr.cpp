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
bool dp[n][n];
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		
		{
			if(i==j)
				dp[i][j]=1;
			else
			dp[i][j]=0;
		}
}
int maxe=0,start=0;
for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
			{
				dp[i][i+1]=1;
				maxe=2;
			}
	}
for(int len=2;len<=n;len++)
	{
		for(int i=0;i<=n-len-1;i++)
			{
				j=i+len;
				if(s[i]==s[j]&&dp[i+1][j-1])
					{
						dp[i][j]=1;
						start=i;
						if(len>maxe)
							maxe=len+1;
					}
			}
	}

/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
cout<<maxe<<"\n";                                                                                                                                  
return 0;
}
