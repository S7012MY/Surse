#include <iostream>
#include <fstream>
#define DN 22
using namespace std;

int bst[1<<DN],n,rez,nrb[1<<DN];

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
}


int main()
{
    ifstream f("coins.in");
    ofstream g("coins.out");
    for(int i=0; i<(1<<DN); ++i) bst[i]=-1,nrb[i]=count(i);
    for(f>>n;n;--n) {
        int si=0,x;
        for(int i=0; i<22; ++i) {
            f>>x;
            si<<=1;
            if(x)si|=1;
        }
        rez+=memo(si);
    }
    g<<rez;
    return 0;
}
