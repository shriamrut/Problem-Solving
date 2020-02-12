#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define pi 3.14159265358979
using namespace std;
typedef long long ll;
ll power(ll,ll,ll);
void minverse(ll x,ll y)
{
	if(__gcd(x,y)!=1)
		cout<<"Inverse does not excist";
	else
	{
		ll ans=power(x,y-2,y);
		cout<<"Modular multplicative inverse of "<<x<<" under "<<y<<": "<<ans;
	}
}
ll power(ll x,ll y,ll p)
{
	if(y==0)
	return 1;
	if(y%2==0)
	return power((x*x)%p,y/2,p);
	else
	return (x*power((x*x)%p,(y-1)/2,p))%p;
	
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll x,y;
cin>>x>>y;
minverse(x,y);
return 0;
}

