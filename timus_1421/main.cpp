#include <cstdio>
#include <vector>
#include <queue>
#define DN 205
#define MULT 320000
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN];
int n,d,st[DN],dr[DN],pre[DN],fl[DN][DN],cap[DN][DN],sl[DN],sc[DN],bst[DN];

bool bfs() {
    queue<int> c;
    pre[0]=0;
    bst[0]=MULT;
    for(int i=1;i<=d; ++i) pre[i]=-1;
    for(c.push(0);c.size();c.pop()) {
        int fr=c.front();
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i)
            if((-1==pre[*i] && cap[fr][*i]>fl[fr][*i]) || bst[*i]<min(bst[fr],cap[fr][*i]-fl[fr][*i])) {
                c.push(*i);
                pre[*i]=fr;
                bst[*i]=min(bst[fr],cap[fr][*i]-fl[fr][*i]);
            }
    }
    return pre[d]!=-1;
}

int main()
{
    scanf("%d",&n);
    d=n+n+1;
    for(int i=1; i<=n; ++i) scanf("%d",&st[i]);
    for(int i=1; i<=n; ++i) scanf("%d",&dr[i]);
    for(int i=1; i<=n; ++i) {
        gr[0].push_back(i);
        gr[i].push_back(0);
        cap[0][i]=cap[i][0]=st[i];
        for(int j=1; j<=n; ++j) {
            gr[i].push_back(j+n);
            gr[j+n].push_back(i);
            cap[i][j+n]=100;
            cap[j+n][i]=0;
        }
        gr[i+n].push_back(d);
        gr[d].push_back(i+n);
        cap[i+n][d]=cap[d][i+n]=dr[i];
    }

    for(;bfs();) {
        int c=MULT;
        for(int y=d;y;y=pre[y])
            c=min(c,cap[pre[y]][y]-fl[pre[y]][y]);
        for(int y=d;y; y=pre[y]) {
            fl[pre[y]][y]+=c;
            fl[y][pre[y]]-=c;
        }
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        sl[i]+=fl[i][j+n];
        sc[j]+=fl[i][j+n];
    }
    for(int i=1; i<=n; ++i) if(sl[i]!=st[i] || sc[i]!=dr[i]) {
       // cout<<sl[i]<<' '<<st[i]<<' '<<sc[i]<<' '<<dr[i]<<' '<<i;
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) printf("%d ",fl[i][j+n]);
        printf("\n");
    }
    return 0;
}
