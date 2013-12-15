#include <iostream>
#include <fstream>
#include <bitset>
#include <map>
#include <cassert>
#define DM 2000005
using namespace std;

bitset<DM> am;
long long n,x0,a,b,m,sz,q,init;
int nr[100005],qu[1005];
map<int, int> mp;
string c;

void conv() {
    for(int i=0; i<c.size(); ++i)
        nr[c.size()-i]=c[i]-'0';
    nr[0]=c.size();
}

int div(int X) {
    int r=0,i;
    for (i=nr[0];i;i--) {
        nr[i]=(r=10*r+nr[i])/X;
        r%=X;
    }
    return r;
}


int main()
{
    ifstream f("sir4.in");
    ofstream g("sir4.out");
    f>>init>>a>>b>>m>>q;
    am[init]=1;
    long long nou,prc=init;
    for(;1;) {
        nou=(a*prc+b)%m;
        if(!am[nou]) {
            ++sz;
            am[nou]=1;
        }else break;
        prc=nou;
    }
    for(int i=1; i<=q; ++i) {
        f>>c;
        conv();
        qu[i]=div(sz+1);
        mp[qu[i]]=0;
    }
    sz=0;
    am&=0;
    am[init]=1;
    prc=init;
    mp[0]=init;
    for(;1;) {
        nou=(a*prc+b)%m;
        if(!am[nou]) {
            ++sz;
            am[nou]=1;
            if(mp.find(sz)!=mp.end()) mp[sz]=nou;
        }else break;
        prc=nou;
    }
    for(int i=1; i<=q; ++i) g<<mp[qu[i]]<<' ';
    return 0;
}
