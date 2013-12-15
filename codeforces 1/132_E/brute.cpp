#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long l,d,cnt;

int main()
{
    for(int i=1; i<=1000; ++i) {
        int cp=i;
        string s;
        for(;cp;cp>>=1)
            if(cp&1) s+='1';
            else s+='0';
        reverse(s.begin(),s.end());
        int sz=s.size(),gok=0;
        for(int k=1; k<sz; ++k) if(sz%k==0) {
            //cout<<i<<' '<<k<<'\n';
            int ok=1;
            for(int i=k; i<sz; ++i) if(s[i]!=s[i-k]) ok=0;
            gok|=ok;
        }
        if(gok) ++cnt,cout<<i<<'\n';
        //cout<<cnt<<'\n';
    }
    cout<<cnt;
    return 0;
}
