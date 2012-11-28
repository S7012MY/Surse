#include <iostream>
#define DN 2005
using namespace std;

int n,v[DN],s1[DN],s2[DN];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i];
    for(int i=1; i<=n; ++i) {
        int cnt=0;
        for(int j=1; j<i; ++j) if(v[j]>v[i]) ++cnt;
        s1[v[i]]=cnt+1;
        cnt=0;
        for(int j=i+1; j<=n; ++j) if(v[j]<v[i]) ++cnt;
        s2[v[i]]=n-cnt;
    }
    for(int i=1; i<=n; ++i) cout<<s1[i]<<' '<<s2[i]<<'\n';
    return 0;
}
