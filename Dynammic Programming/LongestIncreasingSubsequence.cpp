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
  // freopen("input.txt","r",stdin);
   ll n;
   cin>>n;
   ll a[n];
   for(ll i=0;i<n;i++)
		cin>>a[i];
    ll li[n]={0};
    li[0]=1;
    for(ll i=0;i<n;i++) {
		for(ll j=i-1;j>=0;j--) {
			if(a[i]>a[j]) {
				li[i]=max(li[j]+1,li[i]);
			}
		}
	}
	cout<<*max_element(li,li+n);;
   return 0;
}
