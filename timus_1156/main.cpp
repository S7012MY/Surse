#include <iostream>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <algorithm>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n,m,dp[DN][DN],cnt[2],pa[DN],pb[DN];
int cul[DN],fin[DN];
vector<int> gr[DN];
bitset<DN> viz;

void dfs(int s,int c) {
    viz[s]=1;
    cul[s]=c;
    ++cnt[c];
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) {
        if(0==viz[*i]) dfs(*i,c^1);
        if(cul[s]==cul[*i]) {
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
}

void col(int s, int c) {
    viz[s]=1;
    fin[s]=c;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(0==viz[*i]) col(*i,c^1);
}

void reconst(int i, int j) {
    //cout<<'\n'<<i<<' '<<j<<'\n';
    if(i<=0 && j<=0) return;
    int s=abs(dp[i][j]);
    if(dp[i][j]<0) col(s,1);
    else col(s,0);
    //cout<<k<<' '<<dp[i][j][k]<<"\n";
    int c1,c2;
    c1=pa[s];
    c2=pb[s];
    if(dp[i][j]<0) swap(c1,c2);
    reconst(i-c1,j-c2);
   // while(1);
    //cout<<"IMPOSSIBLE";
   // cout<<"aici";
   // exit(0);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dp[0][0]=1000;
    for(int i=1; i<=2*n; ++i) if(0==viz[i]) {
        cnt[0]=cnt[1]=0;
        dfs(i,0);
        pa[i]=cnt[0]; pb[i]=cnt[1];
        for(int i1=n; i1>=0; --i1) for(int i2=n; i2>=0; --i2) if(dp[i1][i2]) {
            if(0==dp[i1+cnt[0]][i2+cnt[1]] && 0==dp[i1+cnt[1]][i2+cnt[0]]) {
                dp[i1+cnt[0]][i2+cnt[1]]=i;
                dp[i1+cnt[1]][i2+cnt[0]]=-i;
            }
        }
    }

    if(!dp[n][n]) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    viz&=0;
    reconst(n,n);
    /*for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/
    for(int i=1; i<=2*n; ++i) if(fin[i]==0) cout<<i<<' ';
    cout<<'\n';
    for(int i=1; i<=2*n; ++i) if(fin[i]) cout<<i<<' ';
    return 0;
}
