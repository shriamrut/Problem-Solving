/*Graph Algorithms 
 * DFS (OK) 
 * BFS (OK)
 * Degrees of each vertex Of Graph (OK)
 * Finding number of Shortest paths to a particular node from src(OK)
 * Connected Components(OK)
 * Cycle detection Undirected Graph (OK)
 * Intime and Outime (OK)
 * Edge Classification based intime and outtime for DG(First do dfs,then classify) (OK)
 * Cycle detection Directed Graph (OK)
 * Biparted Graphs (OK)
 * Dijistra using Heap (OK)
 * Topological Sort-v1 (OK)
 * Topological Sort-v2,Kahn's Algorithm,using queue (OK)
 * AP Normal
 * AP Tarjan's Algorithm
 * Bidirected Components of a Graph
 * Bridges
 * SCC Kosaraju's Algorithm
 * Kriskal's Algorithm for MSP 
 * Prime's Algorithm for MSP
 * Longest Path in DAG
 * Bellman Ford
 * Floyd Warshall
 * MaxFlow Problems
 * Euler Tour
 * Euler Circuit(NP)
 * Euler Path
 * Hamilton Circuit
 * Hamilton Path
 */
#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define inf 1e9
#define clv(v) memset(v,0,sizeof(v))
using namespace std;
//All Variables are global
const int maxs=1e5;
vector< vector<pair<int,int>> >adj;
int n,m,x,y,w,connectedcmp=0,cycleUG=0,cycleDG=0,counts=0;
int vis[maxs];
int in_time[maxs];
int out_time[maxs];
int ind[maxs],outd[maxs];
int shortest_path[maxs], dis[maxs];
stack<int>s_top_dfs;

int vn[maxs],low[maxs],ap[maxs],count=0;
void in_and_out_time(int s)
{
	vis[s]=1;
	in_time[s]=++counts;
	for(auto x:adj[s]) {
		if(vis[x.ff]==0) {
			in_and_out_time(x.ff);
		}
	}
	out_time[s]=++counts;
}
void dijistra(int s)
{
	vector<int>disd(n+1,inf);
	disd[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	while(!pq.empty()) {
		pair<int,int>u=pq.top();
		pq.pop();
		vis[u.ss]=1;
		for(auto x:adj[u.ss]) {
			if(!vis[x.ff] && disd[u.ss]+x.ss < disd[x.ff])
			{
				disd[x.ff]=disd[u.ss]+x.ss;
				pq.push({disd[x.ff],x.ff});
			}
		}
	}
	cout<<"Distance from source "<<s<<endl;
	for(int i=1;i<=n;i++)
		cout<<disd[i]<<" ";
}
void edge_classifier(int s) {
	vis[s]=1;
	for(auto x:adj[s]) {
		if(vis[x.ff]==0) {
			cout<<"Tree Edge  "<<s<<"->"<<x.ff<<endl;
			edge_classifier(x.ff);
		}
		else if(in_time[s]>=in_time[x.ff] && out_time[s]<=out_time[x.ff]) 
		{
			cout<<"Back Edge  "<<s<<"->"<<x.ff<<endl;
		}
		else if(in_time[x.ff]>=in_time[s] && out_time[x.ff]<=out_time[s])
		{
			cout<<"Forward Edge "<<s<<"->"<<x.ff<<endl;
		}
		else
		{
			cout<<"Cross Edge "<<s<<"->"<<x.ff<<endl;
		}
	}
}
void dfs(int s)//Working properly
{
	vis[s]=1;
	cout<<s<<" ";
	for(auto x:adj[s])
	{
		int v=x.ff;
		ind[v]++;
		outd[s]++;
		if(!vis[v])
			dfs(v);
	}
}
void detect_cycle_for_DG(int s) {
	vis[s]=1;
	for(auto x:adj[s]) {
		if(vis[x.ff]==0) {
			detect_cycle_for_DG(x.ff);
		}
		else if(in_time[s]>=in_time[x.ff] && out_time[s]<=out_time[x.ff]) 
		{
			cycleDG=1;
			return;
		}
	}
}
void topological_sort_dfs(int s)
{
	vis[s]=1;
	for(auto x:adj[s]) {
		if(!vis[x.ff])
			topological_sort_dfs(x.ff);
	}
	s_top_dfs.push(s);
	
}
void topological_sortutil()
{
	detect_cycle_for_DG(1);
	if(cycleDG)
		cout<<"\n\nTopological order doesnot exist";
	else
	{
		cout<<"\n\nTopological Sorted Order\n";
		clv(vis);
		for(int i=1;i<=n;i++)	
		{
			if(!vis[i])
				topological_sort_dfs(i);
		}
		while(!s_top_dfs.empty())
		{
			cout<<s_top_dfs.top()<<" ";
			s_top_dfs.pop();
		}
	}
}
void detect_cycle_for_UG(int s)
{
	vis[s]=1;
	for(auto x:adj[s]) {
		if(!vis[x.ff])	{
			detect_cycle_for_UG(x.ff);
		}
		else
		{
			cycleUG=1;
			return;
		}
	}
	
}
void dfs_for_cc(int s)
{
	vis[s]=1;
	for(auto x:adj[s]) {
		if(vis[x.ff]==0)
			dfs_for_cc(x.ff);
	}
}
void bfs(int s)
{
	queue<pair<int,int>>q;
	vis[s]=1;
	q.push({s,0});
	while(!q.empty())
	{
		pair<int,int>up=q.front();
		q.pop();
		int u=up.ff;
		cout<<u<<" ";
		//int w=up.ss;
		for(auto v:adj[u])
		{
			if(vis[v.ff]==0)
			{
				vis[v.ff]=1;
				q.push({v.ff,u});
			}
		}
	}
}
void number_of_shortestpaths(int s)
{
	queue<pair<int,int>>q;
	q.push({s,0});
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		pair<int,int>u=q.front();
		vis[u.ff]=-1;
		q.pop();
		for(auto v: adj[u.ff])
		{
			if(vis[v.ff]==0)
			{
				q.push({v.ff,u.ff});
				dis[v.ff]=dis[u.ff]+v.ss;
				shortest_path[v.ff]++;
				vis[v.ff]=1;
			}
			else if(vis[v.ff]==1 && dis[v.ff]==dis[u.ff]+v.ss)
			{
				shortest_path[v.ff]++;
			}
		}
	}
}
void read_adj_UG(fstream &f)
{
	f>>n>>m;
	adj.resize(n+1);
	for(int i=0;i<m;i++) 
	{
		f>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
}
void read_adj_DG(fstream &f)
{
	f>>n>>m;
	adj.resize(n+1);
	for(int i=0;i<m;i++) 
	{
		f>>x>>y>>w;
		adj[x].push_back({y,w});
	}
}
bool biparted_or_not(int src)
{
	vis[src]=1;
	int color[n+1];
	memset(color,-1,sizeof(color));
	queue<int>q;
	q.push(src);
	color[src]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:adj[u])
		{
			if(vis[v.ff]==0)
			{
				vis[v.ff]=1;
				if(color[u]==1)
					color[v.ff]=0;
				else
					color[v.ff]=1;
				q.push(v.ff);
			}
			else
			{
				if(color[u]==color[v.ff])
					return false;
			}
		}
	}
	return true;
}
void topological_sortutil2() {
	int id[n+1]={0};
	vector<int>order;
	queue<int>q;
	for(int i=1;i<=n;i++) {
		for(auto x:adj[i]) {
			id[x.ff]++;
		}
	}
	for(int i=1;i<=n;i++) {
		if(id[i]==0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		order.pb(x);
		for(auto v:adj[x]) {
			if(--ind[v.ff]==0)
				q.push(v.ff);
		}
	}
	if(n==int(order.size())) {
		cout<<"\nOrder exists, its a DAG\n";
		for(int i=0;i<n;i++) {
			cout<<order[i]<<" ";
		}
	}
	else {
		cout<<"\nOrder doesn't exists, its not a DAG\n";
	}
	
}
void AP_detect(int s) {
	vis[s]=1;
	vn[s]=++count;
	low[s]=count;
	for(auto x:adj[s]) {
		if(!vis[x.ff]) {
			AP_detect(x.ff);
		}
		low[s]=min(low[x.ff],low[s]);
	
	}
	
} 
void AP_util() {
	for(int i=1;i<=n;i++) {
		if(!vis[i])
			AP_detect(i);
	}
}
int main()
{
	fstream f("input.txt");
	read_adj_DG(f);
	cout<<"DFS"<<endl;
	clv(vis);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
		
	}
	clv(vis);
	cout<<"\nBFS"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bfs(i);
		}
	}
	cout<<"\n\nIndegree  and Outdegree of Vertexes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<ind[i]<<" "<<outd[i]<<endl;
	clv(vis);
	clv(shortest_path);
	clv(dis);
	cout<<"Number of shortest paths from the src"<<endl;
	number_of_shortestpaths(1);
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<shortest_path[i]<<" "<<dis[i]<<endl;
	clv(vis);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs_for_cc(i);
			connectedcmp++;
		}
	}
	cout<<"\nConnected components "<<connectedcmp<<endl;
	clv(vis);
	detect_cycle_for_UG(1);
	cout<<endl;
	if(cycleUG)
		cout<<"Cycle exist "<<endl;
	else
		cout<<"Cycle does not exist"<<endl;
	clv(vis);
	cout<<"\nVertex Intime and Outtime "<<endl;
	in_and_out_time(1);
	for(int i=1;i<=n;i++) {
		cout<<i<<" "<<in_time[i]<<" "<<out_time[i]<<endl;
	}
	cout<<endl;
	clv(vis);
	cout<<"\nEdge Classification"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
			edge_classifier(i);
	}
	clv(vis);
	detect_cycle_for_DG(1);
	if(cycleDG)
		cout<<"Cycle exist for DG"<<endl;
	else
		cout<<"Cycle doesnot exist for DG"<<endl;
	clv(vis);
	if(biparted_or_not(1))
		cout<<"The Graph is Biparted"<<endl;
	else
		cout<<"The Graph is not Biparted"<<endl;
	cout<<"\n";
	clv(vis);
	dijistra(1);
	clv(vis);
	topological_sortutil();
	clv(vis);
	cout<<"\nTopological Sorting using Kahn's Algorithm";
	topological_sortutil2();
	clv(vis);
	return 0;
}
