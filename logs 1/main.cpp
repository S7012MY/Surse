#include <cstdio>
#include <list>
#define DN 1502
#define x first
#define y second
using namespace std;

typedef pair<short,short> per;

short n,m;
int rez;
per s[DN+DN];
char inp[DN];

inline int max(int a,int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("logs.in","r",stdin);
    freopen("logs.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=0; i<m; ++i) s[i]=make_pair(i,0);
    for(int i=1; i<=n; ++i) {
        fgets(inp,DN,stdin);
        int ist=-1,jst=m,act=i&1,pre=(i&1)^1;
        for(int j=0; j<m; ++j)
            if('0'!=inp[s[j].x]) {
                s[++ist]=s[j];
                ++s[ist].y;
            }else s[++jst]=s[j];
        for(int j=m+1; j<=jst; ++j)if('0'==inp[s[j].x]) {
            s[++ist].y=0;
            s[ist].x=s[j].x;
        }
        for(int j=0; j<m; ++j)
            rez=max(rez,s[j].y*(j+1));
    }
    printf("%d",rez);
    return 0;
}
