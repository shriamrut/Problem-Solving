#include <bits/stdc++.h>
#define index size_t
#define counts(s,x) count(all(s),x)
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(v) (v).begin(),(v).end()
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define bclock auto start=high_resolution_clock::now(); 
#define eclock auto stop = high_resolution_clock::now(); 
#define calctime auto duration=duration_cast<milliseconds>(stop-start); cout<<"\nTime "<<duration.count()<<endl;
using namespace std;
using namespace std::chrono;
void rv(vector<auto>&v,int n) {v.resize(n);for(int i=0;i<n;i++)	cin>>v[i]; }
void pv(vector<auto>&v) {for(size_t i=0;i<v.size();i++) cout<<v[i]<<" ";}
ll maxl(ll a,ll b) { if(a>b) return a; return b; }
ll minl(ll a,ll b) { if(a<b) return a; return b; }
void permute(vector<int>&a,vector<int>&select) {
    if(a.empty()) {
        pv(select);
        cout<<"\n";
        return;
    }
    else {
        for(index i=0;i<a.size();i++) {
            int sel=a[i];
            select.pb(sel);
            a.erase(a.begin()+i);
            permute(a,select);
            select.erase(select.begin()+select.size()-1);
            a.insert(a.begin()+i,sel);
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector < int >a;
        vector < int >select;
        rv(a,n);
        cout<<"Vector is ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        permute(a,select);
    }
    return 0;
}
