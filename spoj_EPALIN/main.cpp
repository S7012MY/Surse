#include <iostream>
#include <algorithm>
#include <cstring>
#define DN 1000005
using namespace std;

char s[DN],rs[DN];
int n,pi[DN];

void p() {
    for(int i=2,q=0;i<=n; ++i) {
        for(;rs[i]!=rs[q+1] && q!=0;q=pi[q]);
        if(rs[i]==rs[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    cin>>(s+1);
    n=strlen(s+1);
    memcpy(rs,s,sizeof(s)); reverse(rs+1,rs+n+1);
    p();
    int i,j;
    for(i=2,j=0;i<=n; ++i) {
        for(;s[i]!=rs[j+1] && j!=0;j=pi[j]);
        if(s[i]==rs[j+1])++j;
    }
    for(i=n+1,++j;j<=n; ++i,++j) s[i]=rs[j];
    cout<<s+1;
    return 0;
}
