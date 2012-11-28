#include <iostream>
#include <algorithm>
using namespace std;

int v[500005];

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i];
    sort(v+1,v+n+1);
    int bs=1,bst=0,vl;
    for(int i=2; i<=n; ++i)
        if(v[i]==v[i-1]) ++bs;
        else {
            if(bst<bs) {
                bst=bs;
                vl=v[i-1];
            }
            bs=1;
        }
    if(bst<bs) {
        bst=bs;
        vl=v[n];
    }
    cout<<vl;
    return 0;
}
