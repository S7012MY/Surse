#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;

int t,n,s=1;
per p[500005];

bool cmp(const per &a, const per &b) {
    return a.y<b.y;
}

int main()
{
	s=1;
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y;
        sort(p+1,p+n+1,cmp);
        int j=1;
        for(int i=2; i<=n; ++i) if(p[i].x>p[j].y) {
            ++s;
            j=i;
        }
        cout<<s<<'\n';
    return 0;
}
