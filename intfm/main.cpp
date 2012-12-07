#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#define DN 2005
#define x first
#define y second
using namespace std;

multiset<int> s;
typedef pair<int,int> per;
pair<per,per> v[DN],nrm[DN];
int n;

int main() {
    ifstream f("intfm.in");
    ofstream g("intfm.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        int a,b,lg;
        f>>a>>b;
        lg=(b-a)/5;
        v[i].x.x=a;
        v[i].x.y=a+2*lg;
        v[i].y.x=a+3*lg;
        v[i].y.y=b;
    }
    return 0;
}
