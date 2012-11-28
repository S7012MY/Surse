#include <iostream>
#include <fstream>
#define DN (1<<15)
using namespace std;

int t,n,h,l,g,a[13],b[13],hmin[DN],bst;

int bit(int n, int i) {
    if(n&(1<<i)) return 1;
    return 0;
}

int count(int n) {
    if(n==0) return 0;
    int num=0;
    do {
        ++num;
    } while(n&=(n-1));
    return num;
}

int lsb(int n) {
    return (n^(n-1))&n;
}

bool lm(int a, int b) {
    int ab=a&(~b),ba=b&(~a);
    return lsb(ab)<lsb(ba);
    return 0;
}

int main()
{
    ifstream f("carti2.in");
    ofstream out("carti2.out");
    for(f>>t;t;--t) {
        bst=0;
        f>>n>>h>>l>>g;
        for(int i=0; i<n; ++i) f>>a[i]>>b[i];
        for(int i=0; i<=(1<<n); ++i) hmin[i]=2000000;
        for(int i=1; i<(1<<n); ++i) {
            int lc=0,hm=0;
            for(int j=0; j<n; ++j) if(bit(i,j)) {
                lc+=b[j];
                hm=max(hm,a[j]);
            }
            if(lc<=l) hmin[i]=hm+g;
        }
        for(int sm=1; sm<(1<<n); ++sm)
            for(int j=sm; j>0; j=sm&(j-1)) {
                int s1=j,s2=sm^j;
                hmin[sm]=min(hmin[sm],hmin[s1]+hmin[s2]);
            }
        for(int i=1; i<(1<<n); ++i) {
            if(hmin[i]<=h && (count(i)>count(bst) || (count(i)==count(bst) && lm(i,bst)))) bst=i;
        }
        out<<count(bst)<<'\n';
        for(int i=0; i<n; ++i) if(bit(bst,i)) out<<i+1<<' ';
        out<<'\n';
    }
    return 0;
}
