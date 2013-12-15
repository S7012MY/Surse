#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#define LL long long
using namespace std;

int a,b;
string c;
int vl[]={1,5,10,50,100,500,1000};
char sb[]={'I','V','X','L','C','D','M'};
int pos[55555];

int getd(char c) {
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

LL conv(string nr,LL base) {
    LL ret=0;
    reverse(nr.begin(),nr.end());
    for(LL i=0,pt=1; i<nr.size(); ++i,pt*=base) ret+=getd(nr[i])*pt;
    return ret;
}

string roman(LL nr) {
    string ret;
    for(int i=6; i>=0; --i) {
        for(;nr>=vl[i];nr-=vl[i],ret+=sb[i]);
        for(int j=0; j<i; ++j) {
            for(;nr>=vl[i]-vl[j] && !pos[vl[i]-vl[j]]; nr-=(vl[i]-vl[j]),ret+=sb[j],ret+=sb[i]);// cout<<i<<' '<<j;
        }
    }
    return ret;
}

char chr(int nr) {
    if(nr<10) return nr+'0';
    else return nr-10+'A';
}

string baza(LL nr, LL base) {
    string ret;
    for(;nr;ret+=chr(nr%base),nr/=base);
    reverse(ret.begin(),ret.end());
    return ret;
}

int main() {
    pos[1000]=pos[500]=pos[100]=pos[50]=pos[10]=pos[5]=pos[1]=1;
    cin>>a>>c;
    if('R'==c[0]) b=-1;
    else {
        c[0]-='0';
        if(c.size()>1) {
            c[1]-='0';
            b=c[0]*10+c[1];
        }else b=c[0];
    }
    cin>>c;
    LL nr=conv(c,a);
    //cerr<<nr<<'\n';
    if(b==-1) {
        cout<<roman(nr);
        return 0;
    }
    else cout<<baza(nr,b);
}
