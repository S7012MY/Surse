#include <cstdio>
#define LIM (1<<10)

int nr[15],bs1,bs2,nrs,smax;

int main()
{
    freopen("numere8.in","r",stdin);
    freopen("numere8.out","w",stdout);
    for(int i=0; i<10; ++i) scanf("%d",&nr[i]);
    int s1,s2;
    for(int sm1=1; sm1<LIM; ++sm1) {
        s1=0;
        for(int i=0; i<10; ++i)
            if(sm1&(1<<i)) s1+=nr[i];
        for(int sm2=sm1+1; sm2<LIM; ++sm2) {
            if(sm1&sm2) continue;
            s2=0;
            for(int i=0; i<10; ++i)
                if(sm2&(1<<i)) s2+=nr[i];
            if(s1==s2) {
                ++nrs;
                if(s1>smax) {
                    smax=s1;
                    bs1=sm1;
                    bs2=sm2;
                }
            }
        }
    }
    printf("%d %d\n",nrs,smax);
    for(int i=0; i<10; ++i) if(bs1&(1<<i)) printf("%d ",nr[i]);
    printf("\n");
    for(int i=0; i<10; ++i) if(bs2&(1<<i)) printf("%d ",nr[i]);
    return 0;
}
