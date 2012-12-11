#include <cstdio>
#define DN 22

char bst[1<<DN];
int n,rez,s[DN];

int memo(int state) {
    if(bst[state]!=-1) return bst[state];
    int lb=-1,r=1;
    for(int i=0; i<22; ++i)
        if(state&(1<<i)) {
            if(lb!=-1) {
                int ns=state^(1<<i)|(1<<lb);
                r&=memo(ns);
            }
        }else lb=i;
    r^=1;
    bst[state]=r;
    return r;
}

int main()
{
    freopen("coins.in","r",stdin);
    freopen("coins.out","w",stdout);
    for(int i=0; i<(1<<DN); ++i) bst[i]=-1;
    for(int i=1; i<23; ++i) bst[(1<<i)-1]=1;
    for(scanf("%d",&n);n;--n) {
        int si=0,x,cnt=0;
        for(int i=21; i>=0; --i) scanf("%d",&s[i]);
        for(int i=0; i<22; ++i) {
            si<<=1;
            if(s[i]) {
                si|=1;
                ++cnt;
            }
        }
        //cout<<memo(si)<<'\n';
        if(memo(si)) rez+=cnt;
    }
    printf("%d",rez);
    return 0;
}
