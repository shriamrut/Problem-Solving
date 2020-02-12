ll solve(ll x) {
	ll ef=0;
	vector<ll>ofs;
	while(x%2==0) {
		x=x/2;
		ef++;
	}
	for(ll i=3;i<=sqrt(x);i++) {
		ll f=0;
		while(x%i==0) {
			f++;
			x=x/i;
		}
		if(f>0) {
			ofs.pb(f);
		}
	}
	if(x>2) 
		ofs.pb(1);
	ll evenf=0,oddf=1;
	for(size_t i=0;i<ofs.size();i++) {
		oddf*=(ofs[i]+1);
	}
	if(ef>0) 
		evenf=(ef)*(oddf);
	cout<<oddf<<" "<<evenf<<"\n";
	
}
