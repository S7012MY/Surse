#include <iostream>
#include <string>
#include <algorithm>
#define DN 20005
#define DK 15
using namespace std;

string a;

struct e{
    int cp,cu,poz;
} l[DN];

int t,n,suf[DK][DN];

bool cmp(const e &a, const e &b) {
    if(a.cp==b.cp) return a.cu<b.cu;
    return a.cp<b.cp;
}

int main()
{
    for(cin>>t;t;--t) {
        cin>>a;
        a.append(a);
        n=a.size();
        for(int i=0; i<n; ++i) suf[0][i]=a[i]-'0';
        for(int k=1; (1<<k)<n; ++k) {
            for(int i=0; i<n; ++i) {
                l[i].cp=suf[(1<<k)-1][i];
                if(i+(1<<k) <n) l[i].cc=p[(1<<k)-1][i+(1<<k)];
            }
        }
    }
    return 0;
}
