#include <iostream>
using namespace std;

int n,fr[10],sum=0;

void af() {
    int ok=0;
    for(int i=9; i; --i) for(int j=1; j<=fr[i]; ++j) {
        cout<<i;
        ok=1;
    }
    if(ok) for(int i=1; i<=fr[0]; ++i) cout<<0;
    else cout<<0;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int a; cin>>a; ++fr[a]; sum+=a;
    }
    if(0==fr[0]) {
        cout<<-1;
        return 0;
    }
    if(sum%3==0) {
        af();
        return 0;
    }
    for(int i=1; i<=9; ++i) if((sum-i)%3==0 && fr[i] && n>2) {
        --fr[i];
        af();
        return 0;
    }
    for(int i=1; i<=9; ++i) for(int j=1; j<=9; ++j) if((sum-i-j)%3==0 && n>3) {
        if(i!=j && fr[i] && fr[j]) {
            --fr[i]; --fr[j]; af();
            return 0;
        }else if(i==j && fr[i]>1) {
            fr[i]-=2;
            af();
            return 0;
        }
    }
    cout<<0;
    return 0;
}
