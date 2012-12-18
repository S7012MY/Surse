#include <iostream>
#include <fstream>
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<double,double> per;
pair<per,per> seg[DN];
int n;

int main()
{
    ifstream f("taie.in");
    ofstream g("taie.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>seg[i].x.x>>seg[i].x.y>>seg[i].y.x>>seg[i].y.y;
    return 0;
}
