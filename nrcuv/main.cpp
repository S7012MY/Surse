#include <cstdio>
#define DN 1005
#define MOD 104659

int n,m,ic[26][26],nr[DN][26];

int main()
{
    freopen("nrcuv.in","r",stdin);
    freopen("nrcuv.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=1; i<=m; ++i) {
        char a,b;
        scanf("%c %c\n",&a,&b);
       // fprintf(stderr,"%c %c\n",a,b);
        ic[a-'a'][b-'a']=ic[b-'a'][a-'a']=1;
    }
    for(int i=0; i<26; ++i) nr[1][i]=1;
    for(int i=2; i<=n; ++i)
        for(int c1=0; c1<26; ++c1) for(int c2=0; c2<26; ++c2) if(!ic[c1][c2]) {
            nr[i][c2]+=nr[i-1][c1];
            if(nr[i][c2]>=MOD) nr[i][c2]-=MOD;
        }
    int rez=0;
    for(int i=0; i<26; ++i) {
        rez+=nr[n][i];
        if(rez>=MOD) rez-=MOD;
    }
    printf("%d",rez);
    return 0;
}
