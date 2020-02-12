#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ll long long
#define ss second
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(v) (v).begin(),(v).end()
#define maxv(v) max_element(all(v))
#define minv(v) min_element(all(v))
#define bclock auto start=high_resolution_clock::now(); 
#define eclock auto stop = high_resolution_clock::now(); 
#define calctime auto duration=duration_cast<milliseconds>(stop-start); cout<<"\nTime "<<duration.count()<<endl;
using namespace std;
using namespace std::chrono;
void rv(vector<auto>&v,int n) {v.resize(n);for(int i=0;i<n;i++)	cin>>v[i]; }
void pv(vector<auto>&v) {for(size_t i=0;i<v.size();i++) cout<<v[i]<<" ";}
ll maxl(ll a,ll b) { if(a>b) return a; return b; }
ll minl(ll a,ll b) { if(a<b) return a; return b; }
int main() {
	IOS;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector <int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        bool dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) 
            dp[i][0]=true;
        for(int i=1;i<=k;i++)
            dp[0][i]=false;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=k;j++) {
                if(a[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
        cout<<dp[n][k]<<"\n";
    }
	return 0;
}
