#include <fstream>
#include <algorithm>
#define DN 200005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n,sol[DN],nc=1;
per v[DN];

bool cmp(const per &a, const per &b) {
    if(a.x==b.x) return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    ifstream f("invsc.in");
    ofstream g("invsc.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>v[i].x,v[i].y=i;
    sort(v+1,v+n+1,cmp);
    for(int i=1; i<=n; ++i) sol[v[i].y]=i;
    for(int i=1; i<=n; ++i) g<<sol[i]<<'\n';
    return 0;
}
