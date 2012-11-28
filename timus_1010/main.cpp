#include <iostream>
#define LL long long
#define DN 100005
using namespace std;

LL n,bst,p,v[DN];

LL abbs(LL a) {
    if(a<0) return -a;
    return a;
}

int main()
{

    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i];
    bst=abbs(v[1]-v[2]); p=2;
    for(int i=3; i<=n; ++i) if(bst<abbs(v[i-1]-v[i])) {
        bst=abbs(v[i-1]-v[i]);
        p=i;
    }
    cout<<p-1<<' '<<p;
    return 0;
}
