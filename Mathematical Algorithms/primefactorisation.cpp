#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pi 3.14159265358979
#define inf LLONG_MAX
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()
#define printv(v) for(auto it=v.begin();it!=v.end();++it) cout<<*it<<" ";
#define printm(m) for(auto it=m.begin();it!=m.end();++it) cout<<it->first<<" "<<it->second<<endl;
#define printvp(VP) for(auto it=VP.begin();it!=VP.end();++it) cout<<it->first<<" "<<it->second<<endl;
typedef long long ll;
typedef long double ld;
using namespace std;
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
map<int,int>m;
void primeFactors(int n) 
{ 
    while (n%2 == 0) 
    { 
        m[2]++;
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
           	m[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2) 
       m[n]++; 
}
int main()
{
fast();
int n;
cin>>n;
primeFactors(n);
for(auto it=m.begin();it!=m.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
return 0;
}