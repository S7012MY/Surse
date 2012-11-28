#include <iostream>
#define DN 2050005
using namespace std;

int n,pi[DN];
char a[DN],b[DN];

void pr() {
    for(int i=2,q=0;i<=n; ++i) {
        for(;q!=0 && a[q+1]!=a[i];q=pi[q]);
        if(a[q+1]==a[i]) ++q;
        pi[i]=q;
    }
}

int main() {
    cin>>n>>(a+1)>>(b+1);
    for(int i=1; i<=n; ++i) b[i+n]=b[i];
    pr();
    for(int i=1,q=0;i<=2*n; ++i) {
        for(;q!=0 && b[i]!=a[q+1];q=pi[q]);
        if(a[q+1]==b[i]) ++q;
        if(q==n) {
            cout<<i-n;
            return 0;
        }
    }
    cout<<"-1";
}
