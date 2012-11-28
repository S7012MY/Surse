#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#define LL long long
using namespace std;

vector<int> f1;
vector<LL> fp;
LL  n,b=(1ll<<62);

int main()
{
    ifstream f("pitagora2.in");
    ofstream g("pitagora2.out");
    f>>n;
    for(int i=1; i*1ll*i<=n; ++i) if(n%i==0) {
        f1.push_back(i);
        f1.push_back(n/i);
    }
    for(int i=0; i<f1.size(); ++i) for(int j=0; j<f1.size(); ++j) fp.push_back(f1[i]*f1[j]);

    n*=n;
    for(int i=0; i<fp.size(); ++i) {
        LL dif=min(n/fp[i],fp[i]),sum=max(n/fp[i],fp[i]);
        LL c=sum-dif;
        LL cat=sqrt((c/2)*(c/2)+n);
        if(c>0 && c%2==0 && cat*cat==n+(c/2)*(c/2)) b=min(b,c/2);
    }
    if(b==(1ll<<62)) {
        g<<"-1";
        return 0;
    }
    g<<b;
    return 0;
}
