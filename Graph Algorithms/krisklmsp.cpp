#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define pi 3.14159265358979
using namespace std;
typedef long long ll;
int nodes,edges,x,y;
ll wt;
pair<ll,pair<int,int>>p[100000];
int parent[10000];
void intialize()
{
	for(int i=0;i<10000;i++)
		parent[i]=i;
}
int find(int x)
{
	while(parent[x]!=x)
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void Union(int x,int y)
{
	int p=find(x);
	int q=find(y);
	parent[p]=parent[q];
}
ll kriskal()
{
	ll minc=0;
	for(int i=0;i<edges;i++)
	{
		int x=p[i].second.first;
		int y=p[i].second.second;
		if(find(x)!=find(y))
		{
			minc+=p[i].first;
			Union(x,y);
		}
	}
	return minc;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
intialize();
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>wt;
		p[i]=mp(wt,mp(x,y));
	}
sort(p,p+edges);
ll minc=kriskal();
cout<<minc;
return 0;
}
