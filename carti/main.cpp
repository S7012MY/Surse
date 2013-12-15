#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#define DN 20
using namespace std;

int t,n,k,conf[DN],dp[1<<DN],viz[1<<DN];
string crt;

int memo(int state) {
    if(viz[state]) return dp[state];
    viz[state]=1;
    dp[state]=1;
    int ok=0;
    for(int i=0; i<n; ++i) if(!(state&(1<<i))) {
        int sn=state;
        ok=1;
        for(int j=0; !(state&(1<<(i+j)) )&& j<k && i+j<n &&
           (j==0 || conf[i+j]==conf[i+j-1]+1); ++j) {
            sn|=(1<<(i+j));
            dp[state]=min(dp[state],memo(sn));
        }
    }
    dp[state]^=1;
    return dp[state];
}

int main()
{
    ifstream f("carti.in");
    ofstream g("carti.out");
    for(f>>t;t;--t) {
        f>>n>>k;
        for(int i=0; i<n; ++i) {
            f>>crt;
            if(crt.size()==1) {
                if(isdigit(crt[0])) conf[i]=crt[0]-'0';
                else if(crt[0]=='A') conf[i]=1;
                else if(crt[0]=='J') conf[i]=11;
                else if(crt[0]=='Q') conf[i]=12;
                else conf[i]=13;
            }else conf[i]=10;
        }
        sort(conf,conf+n);
        for(int i=0; i<=(1<<n); ++i)
            viz[i]=dp[i]=0;
        if(memo(0)) g<<"Alice\n";
        else g<<"Bob\n";
        //for(int i=0; i<(1<<n); ++i) cout<<i<<' '<<dp[i]<<'\n';
        //cout<<'\n';
    }
    return 0;
}
