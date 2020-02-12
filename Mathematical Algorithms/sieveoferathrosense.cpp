#define ll long long
using namespace std;
int N=10000;
vector<int>prime(N+1,1);
void sieve()
{
    for(int i=2;i<=sqrt(N);i++)
    {
        if(prime[i]==1)
        {
            for(int j=2*i;j<=N;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main() {
    sieve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=2;i<=n;i++)
        {
			if(prime[i])
               cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
