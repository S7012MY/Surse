#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#define DN 1005

int n,nrn,poz;
char sir[DN*DN],rez[DN][DN];

void divide(int x1,int y1, int x2, int y2) {
    if(x1>x2 || y1>y2) return;
    if('*'==sir[poz]) {
        int mx=(x1+x2)>>1,my=(y1+y2)>>1;
        ++poz;
        divide(x1,y1,mx,my);
        divide(x1,my+1,mx,y2);
        divide(mx+1,y1,x2,my);
        divide(mx+1,my+1,x2,y2);
    }else {
        for(;isdigit(sir[poz]);++poz);
        for(int i=x1; i<=x2; ++i)
            for(int j=y1; j<=y2; ++j) rez[i][j]=sir[poz];
        ++poz;
    }
}

int main()
{
    freopen("compresie.in","r",stdin);
    freopen("compresie.out","w",stdout);
    scanf("%s",sir);
    int sz=strlen(sir);
    int x=0,r1=0;
    for(int i=0; i<sz; )
        if(isdigit(sir[i])) {
            for(;isdigit(sir[i]) && i<sz;x=x*10+sir[i]-'0',++i);
            //fprintf(stderr,"%d ",x);
            nrn+=x;
            if(i>=sz) break;
        }else if(isalpha(sir[i])) {
            if(x==0) ++nrn;
            x=0;
            ++i;
        }else ++i,++r1;
    //fprintf(stderr,"%d ",nrn);
    n=sqrt(nrn);
    divide(1,1,n,n);
    printf("%d\n",r1);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) printf("%c",rez[i][j]);
        printf("\n");
    }
    return 0;
}
