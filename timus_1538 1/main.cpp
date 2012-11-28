#include <iostream>
#define DN  5005
#define x first
#define y second
using namespace std;

int n;
typedef pair<long long, long long> per;
per p[DN];

bool det(const per &a,const per &b, const per &c) {
	//| b.x b.y 1 |
	//| c.x c.y 1 |
	//| a.x a.y 1 |
	long long sum=b.x*c.y+c.x*a.y+a.x*b.y;
	long long dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	return (sum+dif)>0LL;
}

bool convex(int i1, int i2, int i3, int i4, int i5) {
    return (det(p[i1],p[i2],p[i3]) && det(p[i2],p[i3],p[i4]) && det(p[i3],p[i4],p[i5]) && det(p[i4],p[i5],p[i1]) && det(p[i5],p[i1],p[i2]));
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y;
    if(n>=12) n=12;
    for(int i1=1; i1<=n; ++i1) for(int i2=1; i2<=n; ++i2) for(int i3=1; i3<=n; ++i3) for(int i4=1; i4<=n; ++i4) for(int i5=1; i5<=n; ++i5)
        if(i1!=i2 && i1!=i3 && i1!=i4 && i1!=i5 && i2!=i3 && i2!= i4&& i2!=i5 && i3!=i4 && i3!=i5 && i4!=i5)
            if(convex(i1,i2,i3,i4,i5)) {
                cout<<"Yes\n"<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<' '<<i5;

                return 0;
            }
    cout<<"No";
    return 0;
}
