/*
Problem: Minimum Element in Range [l,r] with multiple queries
Time Complexity for Segment Tree:
    Query: O(log(n))
    Update: O(log(n))
    Build: O(nlog(n))
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int get_size(int n) {
    int t=(int)ceil(log2(n));
    return 2*pow(2,t)-1;
}
int build(vector<int>&tree,vector<int>&a,int id,int l,int r) {
    if(l==r) {
        tree[id]=a[l];
        return a[l];
    }
    else {
        int mid=(l+r)/2;//
        tree[id]=min(build(tree,a,2*id+1,l,mid),build(tree,a,2*id+2,mid+1,r));
        return tree[id];
    }
}
int query(vector<int>&tree,int ql,int qr,int l,int r,int id) {
    if(ql<=l && qr>=r) {
        return tree[id];
    }
    else if(ql > r || qr <l)
        return INT_MAX;
    else {
        int mid=(l+r)/2;
        return min(query(tree,ql,qr,l,mid,2*id+1),query(tree,ql,qr,mid+1,r,2*id+2));
    }
}
void update(vector<int>&tree,vector<int>&a,int pos,int val,int l,int r,int id) {
    if(pos < l || pos >r) {
        return;
    }
    else if(l==r) {
        tree[id]=val;
        a[pos]=val;
        return;
    }
    else  {
        int mid=(l+r)/2;
        if(pos>=l && pos<=mid)
            update(tree,a,pos,val,l,mid,2*id+1);
        else
            update(tree,a,pos,val,mid+1,r,2*id+2);
        tree[id]=min(tree[2*id+1],tree[2*id+2]);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int s=get_size(n);
    vector<int>tree(s,INT_MAX);
    build(tree,a,0,0,n-1);
    int q;
    cin>>q;
    while(q--) {
        int ql,qr,type,x,val;
        cin>>type;
        if(type==0) {
            cin>>ql>>qr;
            int ans=query(tree,ql,qr,0,n-1,0);
            cout<<ans<<"\n";
        }
        else {
            cin>>x>>val;
            update(tree,a,x,val,0,n-1,0);
        }
    }
    return 0;
}
