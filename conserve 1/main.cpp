#include <iostream>
#include <fstream>
#include <set>
#define DN 1000005
using namespace std;

int n,p,pre[DN],ok[DN],w[5005];
long long sum;
set<int> s;

int main()
{
    ifstream f("conserve.in");
    ofstream g("conserve.out");
    f>>n>>p;
    for(int i=1; i<=p; ++i) {
        f>>w[i];
        sum+=w[i];
    }
    ok[0]=1;
    for(int i=1; i<=p; ++i)
        for(int g=1000000; g>=w[i]; --g)
            if(ok[g-w[i]]) {
                ok[g]=1;
                if(!pre[g]) pre[g]=w[i];
            }
    for(int r=sum%n;r<=1000000;r+=n) if(ok[r]) {
        g<<sum-r<<'\n';
        for(;pre[r];s.insert(pre[r]),r-=pre[r]);
        s.insert(r);
        break;
    }
    g<<p-s.size()+1<<'\n';
    for(int i=1; i<=p; ++i) if(s.find(w[i])==s.end())g<<i<<' ';
    return 0;
}
