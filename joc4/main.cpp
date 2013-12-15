#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#define DN 505
using namespace std;

short n,m,s,d,cap[DN][DN],pre[DN],a,b;

bool bfs(){
    for(int i=1; i<=2*n; ++i) pre[i]=-1;
    pre[s+n]=0;
    queue<short> c;
    for(c.push(s+n);c.size();c.pop()) {
        int fr=c.front();
        for(int i=2*n; i; --i) if(-1==pre[i] && cap[fr][i]>0) {
            c.push(i);
            pre[i]=fr;
        }
    }
    return pre[d]!=-1;
}

int main()
{
    ifstream f("joc4.in");
    ofstream g("joc4.out");
    f>>n>>m>>s>>d;
    if(s==d) while(1);
    for(int i=1; i<=n; ++i) cap[i][i+n]=1;
    for(int i=1; i<=m; ++i) {
        f>>a>>b;
        ++cap[a+n][b];
        ++cap[b+n][a];
    }
    int rez=0;
    for(;bfs();++rez) for(int y=d;pre[y];--cap[pre[y]][y],y=pre[y]);
    g<<rez;
    return 0;
}
