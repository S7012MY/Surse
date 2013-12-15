#include <cstdio>
#include <vector>
#include <set>
#define DN 305
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
typedef multiset<int>::iterator is;

int n,m,k,bst;
vector<per> gr[DN],gt[DN];
multiset<int> mmin,mmax;

int main()
{
    freopen("kgraf.in","r",stdin);
    freopen("kgraf.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        gr[a].push_back(make_pair(b,c));
        gt[b].push_back(make_pair(a,c));
    }
    printf("%d",bst);
    return 0;
}
