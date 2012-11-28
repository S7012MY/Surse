#include <iostream>
#include <algorithm>
#include <cmath>
#define DN 10005
#define x first
#define y second
using namespace std;

typedef pair<double,double> per;

per p[DN],bst;
int n,ind[DN],sa;

bool cmp(const int &a,const int &b) {
    return atan2(p[a].y,p[a].x)<atan2(p[b].y,p[b].x);
}

int main()
{
    cin>>n;
    bst=make_pair(2000000000,2000000000);
    for(int i=1; i<=n; ++i) {
        cin>>p[i].x>>p[i].y;
        if(p[i]<bst) {
            bst=p[i];
            sa=i;
        }
        ind[i]=i;
    }
    swap(ind[1],ind[sa]);
    for(int i=1; i<=n; ++i) {
        p[i].x-=bst.x;
        p[i].y-=bst.y;
    }
    sort(ind+2,ind+n+1,cmp);
    cout<<sa<<' '<<ind[n/2+1];
    return 0;
}
