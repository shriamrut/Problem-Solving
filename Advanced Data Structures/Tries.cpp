#include <bits/stdc++.h>
#define asize 26
#define pb push_back
using namespace std;
class Node{
	public:
	Node *next[asize];
	bool end;
	Node() {
		for(int i=0;i<26;i++)
			next[i]=NULL;
		end=false;
	}
};
class Tries{
	public: 
		Node *root=new Node();
		//insert a vector<strings> into the trie
		void insert(vector<string>&v) {
			for(size_t i=0;i<v.size();i++) {
				Node *current=root;
				for(size_t j=0;j<v[i].length();j++) {
					int id=v[i][j]-'a';
					if(!current->next[id])
						current->next[id]=new Node();
					current=current->next[id];
				}
				current->end=true;
			}
		}
		void print(Node *node,char str[],int level) {
			if(node->end==true) {
				str[level]='\0';
				cout<<str<<"\n";
			}
			int i;
			for(i=0;i<asize;i++) {
				if(node->next[i]) {
					str[level]=(i+'a');
					print(node->next[i],str,level+1);
				}
			}
		}
		//obtaining a string with given prefix
		int prefix_search(string prefix) {
			Node *node=this->root;
			for(size_t i=0;i<prefix.length();i++) {
				if(node->next[prefix[i]-'a'])
					node=node->next[prefix[i]-'a'];
				else
					return -1;
			}
			cout<<"found\n";
			char str[20];//any size
			this->print(node,str,0);
			return 1;
		}
};
int main() {
	int n;
	freopen("input.txt","r",stdin);
	cin>>n;
	string s;
	vector<string>v;
	for(int i=0;i<n;i++) {
		cin>>s;
		v.pb(s);
	}
	Tries t;
	t.insert(v);
	char str[20];
	t.print(t.root,str,0);
	if(t.prefix_search("inter")==-1) 
		cout<<"Not found";
	return 0;
}
