#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 2000005
#define LL long long
#define x first
#define y second
using namespace std;


typedef pair<int,int> per;

int n,k;
per v[DN];

int main()
{
    ifstream f("triangles.in");
    ofstream g("triangles.out");
    f>>n>>k;
    n=min(n,150000);
    for(int i=1; i<=n; ++i) {
        f>>v[i].x;
        v[i].y=i;
    }
    sort(v+1,v+n+1);
    for(int i=k; i<=n; ++i) if(v[i-k+1].x+v[i-k+2].x>=v[i].x) {
        for(int j=i-k+1; j<=i; ++j) g<<v[j].y<<' ';
        return 0;
    }
    return 0;
}
