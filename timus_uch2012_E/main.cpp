#include <iostream>
#include <vector>
#include <cstdlib>
#define DN 15
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n,a[DN];
vector<per> sol;

int trans(int nr) {
    for(int i=0; i<n; ++i) nr=abs(nr-a[i]);
    return nr;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=-2000000; i<=2000000; ++i) {
        if(trans(i)>1) continue;
        per z;
        z.x=i;
        for(;trans(i)<=1; ++i);
        --i;
        z.y=i;
        sol.push_back(z);
    }
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) {
        cout<<sol[i].x<<' '<<sol[i].y<<'\n';
    }
    return 0;
}
