#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 10000000007
using namespace std;
ll binaryexp(ll x,ll n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return binaryexp((x*x)%MOD,n/2);
	else
		return (x*binaryexp((x*x)%MOD,(n-1)/2))%MOD;
}
void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
int main()
{
fast();
ll x,n;
cin>>x>>n;
ll res=binaryexp(x,n);
cout<<res<<"\n";
return 0;
}
