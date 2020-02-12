#include <bits/stdc++.h>
#include<stdint.h>
#define pb push_back
#define mp make_pair
#define sqrt sqrtl
#define cbrt cbrtl
#define MOD 1000000007
#define pi 3.14159265358979
#define inf LLONG_MAX
#define ff first
#define ss second
#define DEBUG freopen("input.txt", "r", stdin);
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef long double ld;
ll maxl(ll a,ll b){  if(a>b) return a;	else return b;	}
const ll bitwidth = 32;
vector<vector<int>>adj;
vector<int>vis;
vector<int>dis;
vector<int>nosp;
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=-1;//-1 black,0 white,1 grey
		for(auto v:adj[u])
		{
			if(vis[v]==0)
			{
				q.push(v);
				vis[v]=1;
				dis[v]=dis[u]+1;
				nosp[v]++;
			}
			else if(vis[v]==1&&dis[v]==dis[u]+1)//only grey
			{
				nosp[v]++;
			}
			//ignore vertices which are black
		}
	}
}
int main()
{
	//IOS;
	int n,m;
	cout<<"Enter number of vertices and edges: ";
	cin>>n>>m;
	adj.resize(n+1);
	vis.resize(n+1);
	dis.resize(n+1);
	nosp.resize(n+1);
	int i,x,y;
	cout<<"Enter edges: "<<endl;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int t,src,des;
	cout<<"Enter number of test cases: ";
	cin>>t;
	while(t--)
	{
		vis.assign(n+1,0);
		dis.assign(n+1,INT_MAX);
		nosp.assign(n+1,0);
		cout<<"Enter source and destination: ";
		cin>>src>>des;
		bfs(src);
		cout<<"Number"<<" "<<"distance"<<endl;
		cout<<nosp[des]<<" "<<dis[des]<<endl;
	}
	return 0;
}
