#include <cstdio>
#include <set>
#define x first
#define y second
using namespace std;

typedef pair<long long, int> per;

multiset<per> s;
int n,k;
long long rez;

int main()
{
    freopen("tarabe.in","r",stdin);
    freopen("tarabe.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; ++i) {
        per a;
        scanf("%d %lld",&a.y,&a.x);
        s.insert(a);
    }
    int i;
    for(i=1; i<=k; ++i) {
        per a=*s.begin();
        rez+=a.x;
        s.erase(s.begin());
        s.insert(make_pair(a.x+a.y,a.y));
    }
    printf("%lld",rez);
    return 0;
}
