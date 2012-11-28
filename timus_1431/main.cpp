#include <iostream>
#include <algorithm>
using namespace std;

int n,v[20],fol[20],cnt;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i];
    sort(v+1,v+n+1);
    for(int i=1; i<=n; ++i) if(!fol[i]) {
        ++cnt;
        for(int j=i+1; j<=n; ++j) if(!fol[j] && v[j]==v[i]+1) {
            fol[j]=1;
            break;
        }
    }
    cout<<cnt;
    return 0;
}
