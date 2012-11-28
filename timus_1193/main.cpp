#include <iostream>
#include <algorithm>
#define t1 first
#define t2 second.first
#define t3 second.second
using namespace std;

typedef pair<int,pair<int, int> > per;

per p[45];
int n,tc,r;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].t1>>p[i].t2>>p[i].t3;
    sort(p+1,p+n+1);
    for(int i=1; i<=n; ++i) {
        if(tc<p[i].t1-r)tc=p[i].t1-r;
        tc+=p[i].t2;
        if(tc>p[i].t3) {
            r+=tc-p[i].t3;
            tc=p[i].t3;
        }
    }
    cout<<r;
    return 0;
}
