/*
KMP or Knuth Morris Pratt Algorithm 
Time Complexity= O(m+n) , where m is the length of text and n is the length of the pattern 
*/
#include <bits/stdc++.h>
using namespace std;
void generatelps(vector<int>&lps,string &pattern) {
    int i=1, j=0;
    lps[0]=0;
    while(i<pattern.length()) {
        if(pattern[j]==pattern[i]) {
            j++;
            lps[i]=j;
            i++;
        }
        else {
            if(j>0)
                j=lps[j-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMP(string &text,string &pattern,vector<int>&lps) {
    int i=0,j=0;
    while(i<text.length()) {
        if(text[i]==pattern[j]) {
            i++;
            j++;
        }
        if(j==pattern.length()) {
            cout<<"Found at "<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(i<text.length() && pattern[j]!=text[i]) {
            if(j==0) {
                i++;
            }
            else {
                j=lps[j-1];
            }
        }
    }
}
int main() {
    //cout<<"Hello World";
    string pattern,text;
    cin>>text>>pattern;
    vector<int>lps(pattern.length());
    generatelps(lps,pattern);
    cout<<"Longest Prefix Suffix Array Count\n";
    for(int i=0;i<pattern.length();i++)
        cout<<lps[i]<<" ";
    cout<<"\n";
    KMP(text,pattern,lps);
    return 0;
}
