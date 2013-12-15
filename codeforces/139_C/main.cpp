#include <iostream>
#include <set>
#define DN 1005
using namespace std;

int n,m,x,y,cnt[DN],bst[2][DN],spg[DN],spar[DN];//cate trebuie schimbate in 0 pe coloana
char mt[DN][DN];
multiset<int> s,s0;

int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1; i<=n; ++i) cin>>mt[i]+1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) if('#'==mt[i][j]) ++cnt[j];
    }
    for(int i=1; i<=m; ++i) {
        spar[i]=spar[i-1]+cnt[i];
        spg[i]=spg[i-1]+(n-cnt[i]);
        bst[0][i]=bst[1][i]=(1<<30);
    }
    bst[0][0]=bst[1][0]=0;
    for(int i=0; i<m; ++i) {
        for(int j=x; j<=y; ++j) if(i+j<=m) {
            bst[0][i+j]=min(bst[0][i+j],bst[1][i]+spar[i+j]-spar[i]);
            bst[1][i+j]=min(bst[1][i+j],bst[0][i]+spg[i+j]-spg[i]);
        }
        //cout<<bst[0][i]<<' '<<bst[1][i]<<'\n';
    }
    cout<<min(bst[0][m],bst[1][m]);
    return 0;
}
