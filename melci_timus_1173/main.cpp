#include <iostream>
#include <algorithm>
#include <cmath>
#define x first
#define y second
#define DN 1005
using namespace std;

typedef pair<int,int> per;

per g;
pair<per,int> p[DN];
int n;

int main()
{
    cin>>g.x>>g.y>>n;
    for(int i=0; i<n; ++i) {
        cin>>p[i].x.x>>p[i].x.y>>p[i].y;
        p[i].x.x-=g.x; p[i].x.y-=g.y;
    }
    return 0;
}
