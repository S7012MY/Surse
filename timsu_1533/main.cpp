#include <iostream>
#define DN 105
using namespace std;

int n,it[DN][DN],viz[DN],sol[DN],sz;

void dfs(int s) {
    viz[s]=1;
    for(int i=1; i<=n; ++i) if(it[s][i] && !viz[i]) dfs(i);
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        int x;
        cin>>x;
        if(x) it[j][i]=1;
    }
    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(it[i][k] && it[k][j]) it[i][j]=1;
    for(int i=1; i<=n; ++i) {
        int ok=0;
        for(int j=1; j<=n; ++j) ok|=it[j][i];
        if(ok || viz[i]) continue;
        sol[++sz]=i;
        dfs(i);
    }
    cout<<sz<<'\n';
    for(int i=1; i<=sz; ++i) cout<<sol[i]<<' ';
    return 0;
}
