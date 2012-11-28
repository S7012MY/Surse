#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
#define DN 505
using namespace std;

typedef pair<int,int> per;
typedef vector<int>::iterator it;

int n,dist[DN],pre[DN],r,br;
per s[DN];
vector<int> gr[DN],sol;

void dfs(int s) {
    int m=0,pr=s;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) {
        if(0==dist[*i]) dfs(*i);
        if(m<dist[*i]) {
            m=dist[*i];
            pr=*i;
        }
    }
    pre[s]=pr;
    dist[s]=m+1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d %d",&s[i].x,&s[i].y);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j && s[i].x<s[j].x && s[j].y<s[i].y)
        gr[i].push_back(j);
    for(int i=1; i<=n; ++i) if(0==dist[i]) {
        dfs(i);
        if(dist[i]>r) {
            r=dist[i];
            br=i;
        }
    }
    //for(int i=1; i<=n; ++i) printf("%d ",pre[i]);
    //printf("\n");
    int j;
    for(j=br;pre[j]!=j;j=pre[j]) sol.push_back(j);
    sol.push_back(j);
    /*for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) dist[j]=0,pre[j]=j;
        dfs(i);
        int m=0,bi;
        for(int j=1; j<=n; ++j) if(m<dist[j]) {
            m=dist[j];
            bi=j;
        }
        if(m>sol.size()) {
            sol.clear();
            int j;
            for(j=i;pre[j]!=j;j=pre[j]) sol.push_back(j);
            sol.push_back(j);
        }
    }*/
    printf("%d\n",sol.size());
    reverse(sol.begin(),sol.end());
    for(int i=0; i<sol.size(); ++i) printf("%d ",sol[i]);
    return 0;
}
