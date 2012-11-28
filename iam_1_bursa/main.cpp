#include <iostream>
#include <fstream>
#include <set>
#define DN 100005
#define LL long long
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;

LL n,s,pro,prec,cnt;
int p[DN];

int main()
{
    ifstream f("bursa.in");
    ofstream g("bursa.out");
    f>>n>>s;
    pro=s;
    for(int i=1; i<=n; ++i) {
        f>>p[i];
        pro=max(pro,p[i]*cnt+prec);
        cnt=pro/p[i];
        prec=pro%p[i];
    }
    g<<pro-s;
    return 0;
}
