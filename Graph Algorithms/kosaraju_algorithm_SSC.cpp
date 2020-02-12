#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
const ll bitwidth = 32;

int edist(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return (pow((p1.ff - p2.ff), 2) + pow((p1.ss - p2.ss), 2));
}
vector<vector<ll>> adj;
vector<vector<ll>> adjr;
vector<ll> vis;
vector<ll> outs;
vector<ll> component;
void dfs1(ll s)
{
    vis[s] = 1;
    for (auto x : adj[s])
    {
        if (!vis[x])
        {
            dfs1(x);
        }
    }
    outs.push_back(s);
}
void dfs2(ll s)
{
    vis[s] = 1;
    //cout<<"in dfs2"<<s<<endl;
    component.push_back(s);
    for (auto x : adjr[s])
    {
        if (!vis[x])
        {
            dfs2(x);
        }
    }
}
int main()
{
    IOS;
    //DEBUG;
    ll n, m, x, y;
    cin >> n >> m;
    adj.resize(n + 1);
    adjr.resize(n + 1);
    vis.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adjr[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    vis.assign(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        if (!vis[outs[i]])
        {
            dfs2(outs[i]);
            if (!component.empty())
            {
                for (ll i = 0; i < ll(component.size()); i++)
                {
                    cout << component[i] << " ";
                }
                cout << endl;
            }
            component.clear();
        }
    }
    return 0;
}
