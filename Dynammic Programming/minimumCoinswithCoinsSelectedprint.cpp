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
/*int memo[100000][10]; set base case
int mincostMemo(int cst,vector<int>&den,int pos) {
    if(pos<0 || cst<=0)
        return 0;
    else if(memo[cst][pos]!=-1) {
        return memo[cst][pos];
    }
    else if(den[pos]>cst) {
        memo[cst][pos]=mincostMemo(cst,den,pos-1);
        return memo[cst][pos];
    }
    else {
        memo[cst][pos]=min(mincostMemo(cst-den[pos],den,pos),mincostMemo(cst-den[pos],den,pos-1))+1;
        return memo[cst][pos];
    }
} */
vector<int> mincostdp(int cst,vector<int>&den) {
    int dp[den.size()+1][cst+1];
    for(int i=0;i<=den.size();i++) {
        for(int j=0;j<=cst;j++) {
            if(j==0)
                dp[i][j]=0;
            else
                dp[i][j]=INT_MAX;
        }
    }
    vector<int>ans;
    for(size_t i=1;i<=den.size();i++) {
        for(int j=0;j<=cst;j++) {
            if(den[i-1]<=j)
                dp[i][j]=min(dp[i][j-den[i-1]],dp[i-1][j-den[i-1]])+1;
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int i=den.size(),j=cst;
    cout<<dp[i][j]<<"\n";
    while(i>=1 && j>=0) {
        //cout<<i<<" "<<j<<"\n";
        if(den[i-1]<=j) {
            ans.pb(den[i-1]);
            if(dp[i][j-den[i-1]] <= dp[i-1][j-den[i-1]]) {
                j=j-den[i-1];
            }
            else {
                i=i-1;
                j=j-den[i-1];
            }
        }
        else {
            i=i-1;
        }
    }
    return ans;
}
int main() {
    vector<int>den={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t;
    cin>>t;
    while(t--) {
        int cst;
        cin>>cst;
        vector<int>ans=mincostdp(cst,den);
        pv(ans);
        cout<<"\n";
    }
    return 0;
}
