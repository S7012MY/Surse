#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define DN 2000005
using namespace std;

char s[DN],rs[DN];
int pi[DN],n;

void p() {
    for(int i=2,q=0; i<=n; ++i) {
        for(;rs[i]!=rs[q+1] && q!=0;q=pi[q]);
        if(rs[i]==rs[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    ifstream f("palindrom.in");
    ofstream g("palindrom.out");
    f>>(s+1);
    n=strlen(s+1);
    memcpy(rs,s,sizeof(s));reverse(rs+1,rs+n+1);
    int i,j;
    p();
    for(i=1,j=0; i<=n; ++i) {
        for(;s[i]!=rs[j+1] && j!=0;j=pi[j]);
        if(s[i]==rs[j+1]) ++j;
    }
    for(i=n+1,++j;j<=n; ++i,++j) s[i]=rs[j];
    g<<s+1;
    cout<<s+1;
    return 0;
}
