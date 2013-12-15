#include <iostream>
using namespace std;

int n,k,v[300005],sz,fr[100005],cnt;

int main()
{
    cin>>n>>k;
    sz=n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        if(!fr[v[i]]) ++cnt;
        ++fr[v[i]];
    }
    for(int i=0; i<=3*n; ++i) {
        if(cnt==1) {
            cout<<i;
            return 0;
        }
        v[++sz]=v[i+k];
        ++fr[v[i+k]];
        --fr[v[i+1]];
        if(!fr[v[i+1]]) --cnt;
    }
    cout<<-1;
    return 0;
}
