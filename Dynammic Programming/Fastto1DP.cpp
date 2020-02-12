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
ll maxl(ll a,ll b) { if(a>b) return a; return b; }
ll minl(ll a,ll b) { if(a<b) return a; return b; }
int main() {
   IOS;
   int n;
   cin>>n;
   int dp[n+1]={INT_MAX};
   dp[1]=0;
   for(int i=2;i<=n;i++) {
		dp[i]=dp[i-1]+1;
		if(i%2==0) 
			dp[i]=min(dp[i/2]+1,dp[i]);
		if(i%3==0)
			dp[i]=min(dp[i/3]+1,dp[i]);
   }
   cout<<dp[n];
   return 0;
}
