#include <iostream>

using namespace std;

int n,h[2000005],m[2000005],rez,c=1;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>h[i]>>m[i];
    for(int i=1; i<n; ++i) {
        if(h[i]==h[i+1] && m[i]==m[i+1]) {
            ++c;
            rez=max(rez,c);
        }
        else {
            c=1;
        }
    }
    rez=max(rez,c);
    cout<<rez;
    return 0;
}
