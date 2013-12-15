#include <iostream>
#define DN 100005
using namespace std;

int n,m,a,v[DN],unde[DN];
long long ra,rb;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        unde[v[i]]=i;
    }
    cin>>m;
    for(int i=1; i<=m; ++i) {
        cin>>a;
        ra+=unde[a];
        rb+=(n-unde[a]+1);
    }
    cout<<ra<<' '<<rb;
    return 0;
}
