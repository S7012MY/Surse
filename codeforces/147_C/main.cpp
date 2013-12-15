#include <iostream>
#define DN 1000005
#define LL long long
using namespace std;

int a,b,k,isp[DN],rez=(1<<30);

bool check(int l) {
    for(int i=a; i+l-1<=b; ++i) {
        if(isp[i+l-1]-isp[i-1]<k) return 0;
    }
    return 1;
}

int main()
{
    cin>>a>>b>>k;
    for(int i=2; i+i<=b; ++i) if(!isp[i]) {
        for(LL j=i*1LL*i; j<=b; j+=i) isp[j]=1;
    }
    isp[0]=isp[1]=1;
    for(int i=0; i<=b; ++i) isp[i]=1-isp[i];
    for(int i=1; i<=b; ++i) {
        isp[i]+=isp[i-1];
        //cout<<isp[i]<<' ';
    }
    int ls=1,ld=(b-a+1),m;
    if(check(ld))
    for(;ls<=ld;) {
        m=(ls+ld)/2;
       // cout<<ls<<' '<<m<<' '<<ld<<'\n';
        //cout.flush();
        if(check(m)) {
            rez=m;
            ld=m-1;
        }else ls=m+1;
    }
    if(rez==(1<<30)) {
        cout<<-1;
        return 0;
    }
    for(;check(rez) ;--rez);
    if(!check(rez)||rez<a) ++rez;
    cout<<rez;
    return 0;
}
