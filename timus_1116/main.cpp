#include <iostream>
using namespace std;

struct f{
    int x,y,vl;
} v1[15000],v2[15000],sol[15000];

int n1,n2,sz;//dim sol;

int main()
{
    cin>>n1;
    for(int i=1; i<=n1; ++i) cin>>v1[i].x>>v1[i].y>>v1[i].vl;
    cin>>n2;
    for(int i=1; i<=n2; ++i) cin>>v2[i].x>>v2[i].y>>v2[i].vl;
    int i1,i2;
    i1=i2=1;
    for(;;) {
        f ic;

    }
    return 0;
}
