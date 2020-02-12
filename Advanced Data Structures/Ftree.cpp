#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void update(int ind,int val,vector<int>&ftree,int n) {
    ind=ind+1;
    while(ind<=n) {
        ftree[ind]+=val;
        ind+=ind&(-ind);
    }
}
void build(vector<int>&ftree,vector<int>&a) {
    for(size_t i=0;i<a.size();i++) {
        update(i,a[i],ftree,a.size());
    }
}
int query(int x,vector<int>&ftree) {
    int ind=x+1,ans=0;
    while(ind>0) {
        ans+=ftree[ind];
        ind-=ind&(-ind);
    }
    return ans;
}
int main() {
    vector<int>a={2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=a.size();
    vector<int>ftree(n+1,0);
    build(ftree,a);
    cout<<query(5,ftree)<<"\n";
    a[3]+=6;
    update(3,6,ftree,n);
    cout<<query(5,ftree);// for range query(r,ftree)-query(l-1)
    return 0;
}
