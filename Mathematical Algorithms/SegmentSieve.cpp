#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void sieve(vector<int>&primes,int n) {
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    for(int i=2;(i*i)<=n;i++) {
        if(isprime[i]) {
            for(int j=2*i;j<=n;j+=i) {
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++) {
        if(isprime[i])
            primes.pb(i);
    }
}   
void segment_sieve(int l,int r) {
    vector<int>primes;
    int bound=(int)sqrt(r);
    sieve(primes,bound);
    int n=(r-l)+1;
    cout<<n<<"a df\n";
    vector<int>marked(n+1,1);
    if(l==1)
        l++;
    for(size_t i=0;i<primes.size();i++) {
        int nlow=ceil((float)l/primes[i])*primes[i];
        if(nlow<l)
            nlow+=primes[i];
        if(nlow==primes[i])
            nlow+=primes[i];
        for(int j=nlow;j<=r;j+=primes[i]) {
            //cout<<j<<" "<<j-l<<"\n";
            marked[j-l]=0;
        }
    }
    for(int i=l;i<=r;i++) {
        if(marked[i-l])
            cout<<i<<" ";
    }
    
}
int main() {
    int l,r;
    segment_sieve(l,r);
    return 0;
}
