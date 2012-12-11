#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define DN 22
using namespace std;

int bst[1<<DN];
int n,rez,s[DN];

int count(int nr) {
    if(nr==0) return 0;
    int r=0;
    do {
        ++r;
    }while(nr &= nr-1);
    return r;
}


int memo(int state) {
    if(bst[state]!=-1) return bst[state];
    int lb=-1,r=1;
    for(int i=0; i<22; ++i)
        if(state&(1<<i)) {
            if(lb!=-1) {
                int ns=state^(1<<i)|(1<<lb);
                r&=memo(ns);
            }
        }else lb=i;
    r=1-r;
    bst[state]=r;
    return r;
}

//<parsing>
FILE* fin=fopen("coins.in","r");
const unsigned maxb=30000192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
    while(buf[ptr]<'0'||'9'<buf[ptr])
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    while('0'<=buf[ptr]&&buf[ptr]<='9'){
        nr=nr*10+buf[ptr]-'0';
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    }
    return nr;
}
//</parsing>

int main()
{
    ofstream g("coins.out");
    for(int i=0; i<(1<<DN); ++i) bst[i]=-1;
    for(n=getInt();n;--n) {
        int si=0,x,cnt=0;
        for(int i=0; i<22; ++i) s[i]=getInt();
        reverse(s,s+22);
        for(int i=0; i<22; ++i) {
            si<<=1;
            if(s[i]) {
                si|=1;
                ++cnt;
            }
        }
        cout<<memo(si)<<'\n';
        if(memo(si)) rez+=cnt;
    }
    g<<rez;
    return 0;
}
