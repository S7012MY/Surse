#include <iostream>
#include <string>
using namespace std;

string s,rez[205];

int main()
{
    for(int i=1; i<=200; ++i) rez[i]="";
    cin>>s;
    int n=s.size(),i,sz=0;
    for(i=0; i+2<s.size(); ++i)
        if('W'==s[i] && 'U'==s[i+1] && 'B'==s[i+2]) {
            if(rez[sz]!="") ++sz;
            i+=2;
        }else rez[sz]+=s[i];
    for(;i<s.size(); ++i) rez[sz]+=s[i];
    for(int i=0; i<=sz; ++i) cout<<rez[i]<<" ";
    return 0;
}
