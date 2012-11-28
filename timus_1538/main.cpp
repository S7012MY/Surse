#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#define DN  5005
#define x first
#define y second
using namespace std;

int n,ind[DN];
typedef pair<int, int> PER;
PER p[DN];

bool det(PER a, PER b, PER c) {
    int dx1 = b.x-a.x;
    int dy1 = b.y-a.y;
    int dx2 = c.x-b.x;
    int dy2 = c.y-b.y;
    int zcrossproduct = dx1*dy2 - dy1*dx2;
    return zcrossproduct>0;
}

bool convex(int i1, int i2, int i3, int i4, int i5) {
    bool semn=det(p[i1],p[i2],p[i3]);
    if(semn==det(p[i2],p[i3],p[i4]) && semn==det(p[i3],p[i4],p[i5]) && semn==det(p[i4],p[i5],p[i1]) && semn==det(p[i5],p[i1],p[i2])) return 1;
    return 0;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y;
    if(n>=9) n=9;
    for(int i1=1; i1<=n; ++i1) for(int i2=1; i2<=n; ++i2) for(int i3=1; i3<=n; ++i3) for(int i4=1; i4<=n; ++i4) for(int i5=1; i5<=n; ++i5)
        if(i1!=i2 && i1!=i3 && i1!=i4 && i1!=i5 && i2!=i3 && i2!= i4&& i2!=i5 && i3!=i4 && i3!=i5 && i4!=i5)
            if(convex(i1,i2,i3,i4,i5)) {
                cout<<"Yes\n"<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<' '<<i5;
                return 0;
            }
    cout<<"No";
    return 0;
}
