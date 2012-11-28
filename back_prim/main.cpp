#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n;
bitset<1000005> isp;
vector<int> pr;

void back(int p,int pprim,vector<int> fct) {
    //cout<<p<<":\n";
    //for(int i=0;i<fct.size(); ++i) cout<<fct[i]<<' ';
   // cout<<'\n';
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
    vector<int> v;
    back(1,0,v);
    return 0;
}
