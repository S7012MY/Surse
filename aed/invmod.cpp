#include <cstdio>

void euclide(long long a,long long b, long long &x,long long &y) {
    if(!b) x=1, y=0;
    else {
        long long x0,y0;
        euclide(b,a%b,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;

    }
}

int main()
{
    freopen("inversmodular.in","r",stdin);
    freopen("inversmodular.out","w",stdout);
    long long a,n,x,y;
    scanf("%lld %lld",&a ,&n );
    euclide (a,n,x,y);
    x=(x+n)%n;
    printf("%lld\n",x);
    return 0;
}

