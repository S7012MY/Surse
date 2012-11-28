#include <cstdio>
#include <cassert>
#include <bitset>
#include <vector>
#include <iostream>
#define LM 1000005
using namespace std;

int n,a,b;
bitset<LM> isp;
vector<int> pr;

void c() {
    for(int i=2; i<LM; ++i) if(0==isp[i]) {
        pr.push_back(i);
        for(int j=i+i; j<LM; j+=i) isp[j]=1;
    }
}

bool ispr(int n) {
    for(int i=2; i*i<=n; ++i) if(0==n%i)return 0;
    return 1;
}

int main()
{
    c();
    for(scanf("%d",&n);n--;) {
        scanf("%d %d",&a,&b);
        int r=1;
        if(a==0 || b%a || a>b) {
            printf("0\n");
            continue;
        }
        b/=a;
        int d;
        if(!ispr(b))
        for(d=0;b!=1 && d<pr.size(); ++d) {
            if(0==b%pr[d]) {
                for(;0==b%pr[d];) {
                    //assert(d>=pr.size());
                    ++r;b/=pr[d];
                }
            }
        }
        if(b>1) ++r;
        printf("%d\n",r);
    }
    return 0;
}
