#include <algorithm>
#include <cstdio>
using namespace std;

#define MOD 30103
#define MAX 2005
#define DIM 705

int aib[DIM][MAX];
int a[DIM];
int n,nr_max,nrt;

void read ()
{
    int i;

    scanf ("%d",&n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d",&a[i]);
        nr_max=max (nr_max,a[i]);
    }
}

int lsb (int x)
{
    return x&(x-1)^x;
}

int query (int x,int y)
{
    int i,j,sum;

    for (sum=0, i=x; i; i-=lsb (i))
        for (j=y; j; j-=lsb (j))
            sum=(sum+aib[i][j])%MOD;

    return sum;
}

void update (int x,int y,int val)
{
    int i,j;

    for (i=x; i<=n; i+=lsb (i))
        for (j=y; j<=nr_max; j+=lsb (j))
            aib[i][j]=(aib[i][j]+val)%MOD;
}

void solve ()
{
    int i,j;

    for (nr_max*=2, i=n; i; --i)
    {
        for (j=i-1; j; --j)
            nrt=(nrt+1+query (j-1,nr_max-a[i]-a[j]-1))%MOD;
        for (j=i-1; j; --j)
            update (j,nr_max-a[i]-a[j],(1+query (j-1,nr_max-a[i]-a[j]-1))%MOD);
    }
    printf ("%d",nrt);
}

int main ()
{
    freopen ("evantai.in","r",stdin);
    freopen ("evantai.out","w",stdout);

    read ();
    solve ();

    return 0;
}
