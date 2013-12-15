#include <fstream>
using namespace std;

int nrd[1000005],x,y,cnt;

void c() {
    for(int i=2; i<=y; ++i) for(int j=i; j<=y; j+=i) ++nrd[j];
}

int main()
{
    ifstream f("magicnum.in");
    ofstream g("magicnum.out");
    f>>x>>y;
    c();
    for(int i=x; i<=y; ++i) if(0==i%(nrd[i]+1)) ++cnt;
    g<<cnt;
    return 0;
}
