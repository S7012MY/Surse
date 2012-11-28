#include <iostream>
#include <bitset>
#define DN 10005
#define MOD 1000000009
using namespace std;

bitset<1000> isp;
int dp[DN][99];

bool hasZ(int nr) {
    for(;nr;nr/=10) if(0==nr%10) return 1;
    return 0;
}

void c() {
    for(int i=2; i<=999; ++i) if(0==isp[i]) {
        if(hasZ(i)||i<100) isp[i]=1;
        for(int j=i+i; j<=999; j+=i) isp[j]=1;
    }
}

int main()
{
    int rez=0,n;
    cin>>n;
    if(3==n) {
        cout<<143;
        return 0;
    }
    c();
    for(int i=100; i<=999; ++i) if(0==isp[i]) ++dp[3][i%100];
    for(int i=4; i<=n; ++i) for(int j=100; j<=999; ++j) if(0==isp[j]) {
        dp[i][j%100]+=dp[i-1][j/10];
        if(dp[i][j%100]>=MOD) dp[i][j%100]-=MOD;
        dp[i][j%100]+=dp[i-2][j/100];
        if(dp[i][j%100]>=MOD) dp[i][j%100]-=MOD;
    }
    for(int i=10; i<100; ++i) {
        rez+=dp[n][i];
        if(rez>=MOD) rez-=MOD;
    }
    cout<<rez;
    return 0;
}
