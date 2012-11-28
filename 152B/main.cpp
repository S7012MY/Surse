#include <iostream>
#include <string>
#include <vector>
#define DN 500005
using namespace std;

int n,t,h,ncas[DN],nshop[DN];
int cst[i];//costul de a termina de pe pozitia i ducandu-ma pana la sfarsit
string s;

void makec(int i) {
    for(int i)
}

bool check(int k) {
    int costI,fi=0;
    for(fi=0; k && fi<n; ++fi) if('H'==s[fi]) --k,++costI;
    if(fi>=n) return 1;
    for(;fi<n && s[fi]!='H';++fi);
    int ncase=0,li=0,ns=0,lasth,lasts;
    for(int i=fi; i<n; ++i) if('H'==s[i]) {
        ++ncase,li=i;
        lasth=i;
    }
    for(int i=fi; i<n; ++i) if('S'==s[i]) {
        ++ns,li=max(li,i);
        lasts=i;
        if(ns==ncase) break;
    }
    cout<<fi<<' '<<li<<'\n';
    if(ns<ncase) return 0;
    int r=(1<<30);
    for(int i=fi; i<=li; ++i) if(ncas[i]<=nshop[i]){
        int cc=2*(i-fi)+cst[i];
        if(lasts<lasth) cc+=lasth-lasts;
        r=min(r,cc);
    }
    return r<=t;
}

int main()
{
    cin>>n>>t;
    cin>>s;
    int lsth=0;
    for(int i=0; i<n; ++i)
        if('H'==s[i]) {
            ++h; ++ncas[i];
        }else if('S'==s[i]) {
            ++nshop[i];
        }
    for(int i=1;i<n; ++i) ncas[i]+=ncas[i-1],nshop[i]+=nshop[i-1];
    for(int i=0; i<n; ++i) makec(i);
    nexth[n-1]=n-1;
    if(t<=lsth) {
        cout<<-1;
        return 0;
    }
    //cout<<check(1); cout.flush();
    //cout<<"----------";
    int ls=0,ld=5000005,m;
    for(;ls<=ld;) {
        m=(ls+ld)>>1;
        cout<<ls<<' '<<m<<' '<<ld<<' '<<check(m)<<'\n';
        if(check(m)) ld=m-1;
        else ls=m+1;
    }
    for(;!check(ld);++ld);
    for(;check(ld) && ld>=0;--ld);
    cout<<ld+1;
    return 0;
}
