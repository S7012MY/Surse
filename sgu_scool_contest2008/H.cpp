#include <iostream>
using namespace std;

int s,nrsol,a[100],ns;
long long dp[3][25][10],rez;

void back(int nr) {
    for(int i=2; i<nr; ++i) if(a[i])
    if(nr==s+1) {
        ++nrsol;
    }
    for(int i=0; i<=9; ++i) {
        a[nr]=i;
        back(nr+1);
    }
}

int main() {
    cin>>s;
    for(int i=0; i<10; ++i) dp[1][1][i]=1;
    for(int lg=2; lg<=s; ++lg) {
        for(int i=0; i<10; ++i) for(int j=0; j<=i; ++j) dp[1][lg][i]+=dp[1][lg-1][j];
        for(int i=0; i<10; ++i) for(int j=9; j>=i; --j) dp[2][lg][i]+=dp[2][lg-1][j];
        for(int i=0; i<10; ++i) for(int j=i+1; j<10; ++j) dp[2][lg][i]+=dp[1][lg-1][j];
    }
    for(int i=0; i<10; ++i) rez+=dp[1][s][i]+dp[2][s][i];
    cout<<rez;
}
