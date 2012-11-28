#include <cstdio>

int euclide(int a,int b,int &x,int &y) {
    if(!b) {//calculam pana cand b=0 => x=1,y=0
        x=1,y=0;
        return a;
    }
    int  x0, y0, d;
    d = euclide( b, a % b, x0, y0 );
    x = y0;
    y = x0-(a/b)*y0;
    return d;
}

int main()
{
    int t,i,a,b,c;
    freopen("euclid3.in","r",stdin);
    freopen("euclid3.out","w",stdout);
    scanf("%d",&t);
    for(i=1; i<=t; i++) {
        int d,x,y;
        scanf("%d %d %d",&a ,&b,&c );
        d=euclide(a,b,x,y);
        if(c%d) printf("0 0\n");
        else printf("%d %d\n",x*(c/d),y*(c/d));

    }
    return 0;
}

