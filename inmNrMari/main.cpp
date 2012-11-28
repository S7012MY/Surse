#include <iostream>
#include <cstdio>
#define DV 100000
#define BASE 1000
using namespace std;

typedef int huge[DV];
int ok;

void inm(huge a,int n) {
    int i,t=0,cp,ca;
    for(i=1; i<=a[0] || t; ++i) {
        ca=a[i];
        if(i>a[0]) ca=0;
        cp=(ca*(n%BASE)+t)%BASE;
        t=(ca*(n%BASE)+t)/BASE;
        n/=BASE;
        a[i]=cp;
    }
    a[0]=i-1;
}

void sub(huge a, huge b) {
    int t=0,i,cp,ca,cb;
    for(i=1; i<=a[0] || i<=b[0] || t; ++i) {
        ca=a[i]; cb=b[i];
        if(i>a[0]) ca=0;
        if(i>b[0]) cb=0;

        cp=(ca-cb)%BASE;
        t=(ca-cb)/BASE;
        a[i]=cp;
    }
    a[0]=i-1;
}

void print(huge a) {
    if(ok) printf("-");
    printf("%d",a[a[0]]);
    for(int i=a[0]-1; i; --i) printf("%03d",a[i]);
}

void atrib(huge a, int nr) {
    a[0]=0;
    for(;nr;nr/=BASE) a[++a[0]]=nr%BASE;
}

huge x,y,rez;

int main()
{
    int a,b;
    cin>>a>>b;

    if(a<b) {
        swap(a,b);
        ok=1;
    }
    atrib(x,a);
    atrib(y,b);
    inm(x,b);
    print(x);
    return 0;
}
