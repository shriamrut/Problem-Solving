/*https://practice.geeksforgeeks.org/problems/max-length-chain/1*/
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}/*This is a function problem.You only need to complete the function given below*/
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
bool cmp(const struct val &p1,struct val &p2) {
    if(p1.first<p2.first)
        return true;
    else
        return false;
}
int maxChainLen(struct val p[],int n)
{
    vector<int>dp(n,1);
    int maxs=1;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(p[i].first>p[j].second) {
                dp[i]=max(dp[j]+1,dp[i]);
                maxs=max(dp[i],maxs);
            }
        }
    }
    return maxs;
}
