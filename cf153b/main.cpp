#include <iostream>
#define DN 105
using namespace std;

int n,k,p[DN],q[DN],f[DN],np[DN];

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i) {
        cin>>q[i];
        p[i]=i;
    }
    for(;k;) {
        for(int i=1; i<=n; ++i) np[i]=p[q[i]];
        for(int i=1; i<=n; ++i) p[i]=np[i];
        --k;
        int ok=1;
        for(int i=1; i<=n; ++i) if(p[i]!=q[i]) ok=0;
        if(ok && (k%2)==0) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
