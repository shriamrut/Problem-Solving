#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define MOD 10000000007
using namespace std;
bool prime[1000005];
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
}
 
// Driver Program to test above function
int main()
{
    int n = 1000000;
    SieveOfEratosthenes(n);
    int t,k,p;
    cin>>t;
    while(t--)
    {
    	cin>>k;
   		 for (p=k;; p++)
       		{
       			if (prime[p]&&(p-1)%11==0)
       				break;
       		}
        cout<<p<<"\n";
  	}
    return 0;
}
