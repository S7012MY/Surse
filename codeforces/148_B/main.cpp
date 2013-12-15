#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

string s,c;
int n,q,fr[12];

void inter(int l, int r) {
    int cp=l,dp=1;
    c=s;
    for(;cp>=l && cp<r;) {
        if(c[cp]=='#') {
            cp+=dp;
            continue;
        }
        if(isdigit(c[cp])) {
            ++fr[c[cp]-'0'];
            //cout<<c[cp]<<' ';cout.flush();
            if(c[cp]=='0') c[cp]='#';
            else --c[cp];
            cp+=dp;
            continue;
        }
        if(c[cp]=='<' || c[cp]=='>') {
            if(c[cp]=='<') dp=-1;
            else dp=1;
            if(cp<l || cp>=r) continue;
            int ncp=cp+dp;
            for(;c[ncp]=='#' && ncp>=l && ncp<r; ncp+=dp);
            if(ncp<l || ncp>=r) {
                cp=ncp;
                continue;
            }
            if(c[ncp]=='>' || c[ncp]=='<') c[cp]='#';
            cp+=dp;
        }
    }
    for(int i=0; i<=9; ++i) cout<<fr[i]<<' ';
    cout<<'\n';
    memset(fr,0,sizeof(fr));
}

int main()
{
    cin>>n>>q;
    cin>>s;
    for(int i=1; i<=q; ++i) {
        int a,b;
        cin>>a>>b;
        inter(a-1,b);
    }
    return 0;
}
