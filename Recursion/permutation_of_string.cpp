#include <bits/stdc++.h>
using namespace std;
vector<string>ans;
void permutation(string s,string choosen) {
    if(s.empty()) {
        ans.push_back(choosen);
        return;
    }
    else {
        for(size_t i=0;i<s.length();i++) {
            char c=s[i];
            choosen+=c;
            s.erase(i,1);
            permutation(s,choosen);
            s.insert(i,1,c);
            choosen.erase(choosen.length()-1,1);
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ans.clear();
        string s;
        cin>>s;
        permutation(s,"");
        sort(ans.begin(),ans.end());
        for(size_t i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
