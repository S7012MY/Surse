#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#define DN 1000005
#define LL long long
using namespace std;

int n;
LL nr;
vector<LL> pr;

bitset<DN> isp;

void c() {
    for(int i=2; i<DN; ++i) if(!isp[i]) {
        pr.push_back(i);
        for(LL j=i*1LL*i; j<DN; j+=i) isp[j]=1;
    }
}

int main()
{
    c();
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>nr;
        long long rd=sqrt(nr);
        if(nr<4 || rd*rd!=nr) {
            cout<<"NO\n";
            continue;
        }
        if(isp[rd]==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
