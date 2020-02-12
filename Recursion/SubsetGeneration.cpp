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
vector<int>subset;
int ans=0;
void search(int k,int n) {
    if(k==n) {
        for(int i=0;i<subset.size();i++) 
            cout<<subset[i]<<" ";
        cout<<"\n";
        ans++;
    }
    else {
        subset.pb(k);
        search(k+1,n);
        subset.pop_back();
        search(k+1,n);
    }
}
int main() {
    IOS;
    int n;
    cin>>n;
    search(0,n);
    cout<<"Ans "<<ans<<"\n";
    return 0;
}
