#define pb push_back
#define ff first
#define ll long long
#define ss second
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using namespace std::chrono;
bool cmp(const pair<int,int>&p1,const pair<int,int>&p2) {
	if(p1.ff<p2.ff)
		return true;
	else if(p1.ff==p2.ff)
	{
		if(p1.ss<=p2.ss)
			return true;
		else
			return false;
	}
	else
		return false;
}
int dist(pair<int,int> p1,pair<int,int>p2) {
	return sqrt(pow((p1.ff-p2.ff),2)+pow((p1.ss-p2.ss),2));
}
int main() {
   IOS;
   int t,x,y;
   cin>>t;
   while(t--) {
		vector<pair<int,int>>v;
		for(int i=0;i<4;i++) {
			cin>>x>>y;
			v.pb({x,y});
		}
		sort(v.begin(),v.end(),cmp);
		int fd=dist(v[0],v[1]);
		if(dist(v[2],v[3])==fd && dist(v[0],v[2])==fd && dist(v[3],v[1])==fd && fd!=0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
   }
   return 0;
}
 //auto start=high_resolution_clock::now(); 
 //auto stop = high_resolution_clock::now(); 
 //auto duration=duration_cast<microseconds>(stop-start);
 //cout<<endl<<"Time "<<duration.count()<<endl;
