#include <cstdio>
#define DN 105
#define MULT 4000000
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,dmin[DN][DN],tmin=MULT,a,b;

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

void rf() {
    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if (i!=j && j!=k && dmin[i][k]+dmin[k][j]<dmin[i][j])
                dmin[i][j]=dmin[i][k]+dmin[k][j];
}

int main()
{
    freopen("megascoala.in","r",stdin);
    freopen("megascoala.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        scanf("%d",&dmin[i][j]);
        if(!dmin[i][j] && i!=j) dmin[i][j]=MULT;
    }
    rf();
    /*for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) deb(dmin[i][j])
        debnl
    }*/
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) {
        int tmax=0;
        for(int s=1; s<=n; ++s) if(tmax<min(dmin[s][i],dmin[s][j]))
            tmax=min(dmin[s][i],dmin[s][j]);
        //deb(tmax)
        if(tmax<tmin) {
            tmin=tmax;
            a=i;b=j;
            //deb(tmin) deb(i) deb(j)
        }
    }
    printf("%d %d %d",a,b,tmin);
    return 0;
}
