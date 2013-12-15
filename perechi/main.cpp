#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#define DN 20005
using namespace std;

int n;
vector<int> fct;
long long r=1;
bitset<DN> isp;

void c() {
    for(int i=2; i<DN; ++i) if(!isp[i]) {
        fct.push_back(i);
        for(int j=i*i; j<DN; j+=i) isp[j]=1;
    }
}

int main()
{
    ifstream f("perechi.in");
    ofstream g("perechi.out");
    c();
    f>>n;
    for(int i=0; i<fct.size(); ++i) {
        if(0==n%fct[i]) {
            int put=0;
            for(;n%fct[i]==0;n/=fct[i],++put);
            r*=(2LL*put+1LL);
        }
    }
    if(n>1) r*=3LL;
    g<<(r+1LL)/2LL;
    return 0;
}
