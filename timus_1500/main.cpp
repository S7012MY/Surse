#include <iostream>
#include <vector>
#include <bitset>
#define DN 35
#define bit(n, i) ((n >> i) & 1)
using namespace std;

typedef pair<int, int> per;
bitset<DN> viz;
int n,m,k,bs=999999,bi,sm,ok,tip[DN][DN];

int count(long n) {
    int num = 0;
    if (n)
        do num++; while (n &= n - 1);
    return num;
}

void dfs(int s) {
    if(1==s) {
        ok=1;
        return;
    }
    viz[s]=1;
    for(int i=0;!ok && i<n; ++i) if(0==viz[i] && (sm&tip[s][i])) dfs(i);
}

int main()
{
    cin>>k>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        tip[a][b]|=(1<<c);
        tip[b][a]|=(1<<c);
    }
    for(sm=1; sm<(1<<k); ++sm) if(bs>count(sm)){
        ok=0;
        dfs(0);
        if(ok) {
            bs=count(sm);
            bi=sm;
        }
        viz&=0;
    }
    cout<<bs<<'\n';
    for(int i=0; i<k; ++i) if(bit(bi,i)) cout<<i<<' ';
    return 0;
}
