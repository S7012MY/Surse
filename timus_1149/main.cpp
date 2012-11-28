#include <iostream>
using namespace std;

void a(int n) {
    for(int i=1; i<=n; ++i) {
        if(i==n) cout<<"sin("<<i;
        else {
            if(i%2) cout<<"sin("<<i<<"-";
            else cout<<"sin("<<i<<"+";
        }
    }
    for(int i=1; i<=n;++i) cout<<")";
}

void s(int n) {
    for(int i=1;i<n; ++i) cout<<"(";
    for(int i=1; i<n; ++i) {
        a(i);
        cout<<"+"<<n-i+1<<")";
    }
    a(n);
    cout<<"+1";
}

int main()
{
    int n;
    cin>>n;
    s(n);
    return 0;
}
