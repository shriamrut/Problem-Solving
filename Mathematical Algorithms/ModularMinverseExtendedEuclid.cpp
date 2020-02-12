//Extended Euclid Algorithm for find modular multiplicative inverse
#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define MOD 10000000007
using namespace std;
int d,x,y;
void EE(int a,int b)
{
	if(b==0)
		{
			d=a;
			x=1;
			y=0;
		}
	else
	{
	EE(b,b%a);
	int temp=x;
	x=y;
	y=temp-a/b*y;
	}
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
EE(16,2);
cout<<"GCD: "<<d<<" x: "<<x<<" y: "<<y<<"\n";
return 0;
}
