#include <cstdio>
#include <set>
using namespace std;

typedef set<int>::iterator is;

int m,n,dc;
multiset<int> s;

int main()
{
    freopen("strung.in","r",stdin);
    freopen("strung.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=0; i<m; ++i) s.insert(0);
    for(int i=0; i<n; ++i) {
        scanf("%d",&dc);
        int nou=*s.begin()+dc;
       // fprintf(stderr,"%d ",nou);
        s.erase(s.begin());
        s.insert(nou);
    }
    int rez=0;
    for(is i=s.begin(); i!=s.end(); ++i) rez=max(rez,*i);
    printf("%d",rez);
    return 0;
}
