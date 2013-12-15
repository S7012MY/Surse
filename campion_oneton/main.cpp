#include <cstdio>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,r=1;

int main()
{
    freopen("oneton.in","r",stdin);
    freopen("oneton.out","w",stdout);
    //for(int i=1; i<=4; ++i) {
        r=1;
        scanf("%d",&n);
        /*if(n<=1000) {
            for(int i=1; i<=2*n; ++i) v[i]=i;
        }else {*/
            int i=2;
            if(!(i&1)) i=2*n-i/2+1;
            else i=i/2+1;
            for(;i!=2;++r) {
                if(!(i&1)) i=2*n-i/2+1;
                else i=i/2+1;

                //deb(i);
            }
        printf("%d\n",r);
        //deb(r)
        //}
    return 0;
}
