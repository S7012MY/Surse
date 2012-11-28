#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define DN 20005
#define x first
#define y second
using namespace std;

pair<int, pair<int, pair<int, int> > > v[DN];
int n;

int main()
{
    ifstream f("intfm.in");
    ofstream g("intfm.out");
    f>>n;
    for(int i=0; i<n; ++i) {
        int a,b,lg,t1,t2;
        f>>a>>b;
        lg=(b-a)/5;
        t1=a+2*lg;
        t2=t1+lg;
        v[i]=make_pair(b,make_pair(a,make_pair(t1,t2)));
    }
    sort(v,v+n);
    int ult=0,r=1;
    for(int i=1; i<n; ++i)
        if(v[ult].x<=v[i].y.x) ult=i,++r;
        else if(v[ult].x<=v[i].x) {
            int t1=v[i].y.y.x,t2=v[i].y.y.y;
            if(v[ult].y.x>=t1 && t2>=v[ult].x) {
                ult=i;
                ++r;
            }
        }
    g<<r;
    cout<<r;
    return 0;
}
