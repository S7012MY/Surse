#include <iostream>
#include <bitset>
#include <vector>
#define MOD 1000000007
#define DN 1000005
using namespace std;

int n,fib[DN],put[DN];
bitset<DN> isp;
vector<int> pr,desc[DN],v;

void back(int p,int pprim,vector<int> &fct) {
    desc[p]=fct;
    for(int i=pprim; i<pr.size(); ++i) {
        if(p*1LL*pr[i]>n) break;
        fct.push_back(pr[i]);
        back(p*pr[i],i,fct);
        fct.pop_back();
    }
}

int main()
{
    cin>>n;
    for(int i=2; i*i<=n; ++i) if(0==isp[i]) {
        for(int j=i*i; j<=n; j+=i) isp[j]=1;
    }
    for(int i=2; i<=n; ++i) if(0==isp[i]) pr.push_back(i);
    back(1,0,v);
    fib[1]=1;
    for(int i=2; i<n+5; ++i) fib[i]=(fib[i-1]+fib[i-2])%MOD;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<desc[i].size(); ++j) {
            int fp=desc[i][j];
            //cout<<i<<' '<<fp<<' '<<pt<<' '<<fib[n-i+1]<<'\n';
            put[fp]=(put[fp]+fib[n-i+1])%MOD;
        }
        //for(int i=0; i<pr.size(); ++i) if(put[pr[i]]) cout<<pr[i]<<' '<<put[pr[i]]<<'\n';
        //cout<<'\n';
    }
    int r=1;
    for(int i=0; i<pr.size(); ++i) if(put[pr[i]]) {
       // cout<<pr[i]<<' '<<put[pr[i]]<<'\n';
        r=(1LL*r*(put[pr[i]]+1))%MOD;
    }
    cout<<r;
    return 0;
}
