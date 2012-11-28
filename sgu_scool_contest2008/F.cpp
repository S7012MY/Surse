#include <cstring>
#include <cstdio>
#include <queue>
#define inf (1<<30)
#define DN 102
using namespace std;

struct info
{
    int ki,ti,wi,pos;
}name[DN];

queue <int> Q[DN];
int num[DN];
bool vis[DN];
int m,n,cnt,tot;

void init() {
    memset(num,0,sizeof(num));
    memset(vis,false,sizeof(vis));
    cnt = tot = 0;
    for(int i=1;i<=m;i++) {
        while(!Q[i].empty()) Q[i].pop();
    }
    return;
}

void clear(int b)
{
    for(int i=0;i<b;i++)
    {
        if(vis[i] == false) name[i].wi++;
    }
    for(int i=1;i<=m;i++)
    {
        if(num[i] > 0)
        {
            int cur = Q[i].front();
            name[cur].wi--;
            if(name[cur].wi + name[cur].ti == tot)
            {
                Q[i].pop();
                vis[cur] = true;
                num[i]--;
                cnt--;
            }
        }
    }
    return;
}

void read()
{
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&name[i].ki,&name[i].ti);
    }
    return;
}

void go(int bj)
{
    int t = inf,p = -1;
    for(int i=1;i<=m;i++)
    {
        if(num[i] < t)
        {
            t = num[i];
            p = i;
        }
    }
    Q[p].push(bj);
    cnt++;
    num[p]++;
    name[bj].pos = p;
    name[bj].wi = tot;
    return;
}

void solve()
{
    int l = 0;
    while(true)
    {
        clear(l);
        while(l < n && name[l].ki <= tot)
        {
            go(l);
            l++;
        }
        if(cnt == 0 && l == n) break;
        tot++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",name[i].pos , name[i].wi + name[i].ti);
    }
    return;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        init();
        read();
        solve();
    }
    return 0;
}
