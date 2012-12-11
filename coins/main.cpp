#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define DN 22
using namespace std;

int bst[1<<DN],n,rez,nrb[1<<DN],s[DN];

int count(int nr) {
    if(nr==0) return 0;
    int r=0;
    do {
        ++r;
    }while(nr &= nr-1);
    return r;
}


int memo(int state) {
    int r=(1<<30);
    if(bst[state]!=-1) return bst[state];
    int lb=-1;
    for(int i=0; i<22; ++i)
        if(state&(1<<i)) {
            int ns=state;
            if(lb!=-1) {
                ns^=(1<<i);
                ns|=(1<<lb);
                r=min(r,memo(ns));
            }
        }else lb=i;
    if(r==(1<<30) || !r) {
        bst[state]=nrb[state];
        return nrb[state];
    }
    bst[state]=0;
    return 0;
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
    for(int i=0; i<(1<<DN); ++i) bst[i]=-1,nrb[i]=count(i);
    for(n=getInt();n;--n) {
        int si=0,x;
        for(int i=0; i<22; ++i) s[i]=getInt();
        reverse(s,s+22);
        for(int i=0; i<22; ++i) {
            si<<=1;
            if(s[i])si|=1;
        }
       // cout<<memo(si)<<'\n';
        rez+=memo(si);
    }
    g<<rez;
    return 0;
}
