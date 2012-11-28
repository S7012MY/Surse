#include <iostream>
#include <bitset>
#define DN 105
using namespace std;


int n,m,ma[DN][DN],lg[DN];
bitset<DN> elim,final;


void dfs(int s) {
    elim[s]=1;
    for(int i=1; i<=n; ++i) if(!elim[i] && ma[s][i]) {
        lg[i]=lg[s]+1;
        dfs(i);
        break;
    }
}

void parc(int s) {
    final[s]=1;
    for(int i=1; i<=n; ++i) if(!final[i] && ma[s][i]) {
        parc(i);
        break;
    }
}

int main()
{
    int rez=0;
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        cin>>a>>b;
        ma[a][b]=ma[b][a]=1;
    }
    for(int i=1; i<=n; ++i) if(!elim[i]) {
        lg[i]=1;
        dfs(i);
        for(int j=1; j<=n; ++j) if(ma[i][j] && lg[j]&1) {
            ++rez;
            parc(i);
        }
    }
    int add=(n-final.count())&1;
    cout<<rez+add;
}
