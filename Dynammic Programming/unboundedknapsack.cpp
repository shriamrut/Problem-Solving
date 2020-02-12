#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define pi 3.14159265358979
using namespace std;
typedef long long ll;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,k,t;
//int m;
cin>>t;
while(t--)
{
cin>>n>>k;
int a[n],dp[k+1];
for(int i=0;i<k+1;i++)
	dp[i]=0;
for(int i=0;i<n;i++)
	cin>>a[i];
for(int j=0;j<k+1;j++)
{
	//m=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(j>=a[i])
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
	}

}
cout<<dp[k]<<"\n";
}
return 0;
}