#include <cstdio>
#include <vector>
#include <queue>
#define DN 105
#define DT 10005
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
int n,m,s,t,nr[DT];
vector<int> gr[DN];
queue<per> c;

int main()
{
    freopen("part.in","r",stdin);
    freopen("part.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1; i<=m; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        gr[a].push_back(b);
    }
    for(c.push(mp(s,0));c.size();c.pop()) {
        int frn=c.front().x,frt=c.front().y;
        ++nr[frt];
        for(it i=gr[frn].begin();i!=gr[frn].end();++i)
            if(frt+1<=t) c.push(mp(*i,frt+1));
    }
    printf("%d",nr[t]);
    return 0;
}
