#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string s;
int sc,sf;

int main()
{
    cin>>s;
    if(s.size()<=1){
        cout<<"-1";
        return 0;
    }
    bool ok=1;
    for(int i=0; i<s.size(); ++i) sc+=(s[i]-'0');
    for(int i=1; i<s.size(); ++i) if(s[i]!=s[i-1]) ok=0;
    if(ok && (s[0]=='0' || s[0]=='9')) {
        cout<<"-1";
        return 0;
    }
    int lp=s.size()-1,fp,sum=0;
    for(;s[lp]<'1';--lp);
    fp=lp-1;
    assert(fp>=0);
    for(;s[fp]=='9';--fp);
    ++s[fp];
    --sum;
    for(int i=fp+1; i<s.size(); ++i) sum+=s[i]-'0',s[i]='0';
    for(int i=s.size()-1; sum>0;--i)
        if(sum>9) {
            s[i]='9';
            sum-=9;
        }else {
            s[i]=sum+'0';
            sum=0;
        }
    for(int i=0; i<s.size(); ++i) sf+=(s[i]-'0');
    if(sf!=sc) {
        cout<<-1;
        return 0;
    }
    cout<<s;
    return 0;
}
