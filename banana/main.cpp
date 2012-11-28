#include <fstream>
#include <map>
#include <algorithm>
#define DN 16005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,k,pre[DN],vl[DN],top[DN],sz;
per p,pnou;
map<per,int> mp;

int find(int n) {
    if(pre[n]==n) return n;
    pre[n]=find(pre[n]);
    return pre[n];
}

void unite(int x, int y) {
    pre[x]=y;
}

int main()
{
    ifstream f("banana.in");
    ofstream g("banana.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) pre[i]=i;
    for(int i=1; i<=n; ++i) {
        f>>p.x>>p.y;
        mp[p]=i;
        for(int d=0; d<4; ++d) {
            pnou.x=p.x+dx[d]; pnou.y=p.y+dy[d];
            if(pnou.x<1 || pnou.y<1 || mp.find(pnou)==mp.end()) continue;
            unite(find(i),find(mp[pnou]));
        }
    }
    for(int i=1; i<=n; ++i) ++vl[find(i)];
    for(int i=1; i<=n; ++i) if(vl[i]) top[++sz]=vl[i];
    sort(top+1,top+sz+1);
    int rez=0;
    for(int i=sz; i>sz-k; --i) rez+=top[i];
    g<<rez;
    return 0;
}
