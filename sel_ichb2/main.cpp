#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int n;
string s;

string check(string s) {
    int i;
    if('.'==s[0]) return "NO";
    for(i=0; i<s.size() && s[i]!='@'; ++i)
        if(!isdigit(s[i]) && !isalpha(s[i]) && s[i]!='_' && s[i]!='-' && s[i]!='.') return "NO";

    if(i==s.size()) return "NO";
    if(s[i-1]=='.') return "NO";
    ++i;
    if('.'==s[i]) return "NO";
    string d1;
    d1.clear();

    int lp=-1;
    for(int j=1; j<s.size(); ++j) {
        if(s[j]=='.') lp=j;
        if(s[j]==s[j-1] && s[j]=='.') return "NO";
    }
    if(lp==-1) return "NO";

    for(;i<s.size() && i!=lp; ++i) {
        if(!isdigit(s[i]) && !isalpha(s[i]) && s[i]!='_' && s[i]!='-' && s[i]!='.') return "NO";
    }
    if(i==s.size()) return "NO";
    ++i;
    for(;i<s.size(); ++i) {
        if(!isalpha(s[i])) return "NO";
        d1+=s[i];
    }
    if(d1.size()<2 || d1.size()>3) return "NO";
    return "YES";
}

int main()
{
    cin>>n;
    cin.get();
    for(int i=1; i<=n; ++i) {
        getline(cin,s);
        cout<<check(s)<<'\n';
    }
    return 0;
}
