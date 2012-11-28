#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second.first
#define z second.second
using namespace std;

typedef pair<int, pair<int,int> > per;
int n,mom[1000005],nrs;
per v[1005];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i].y>>v[i].x;
        v[i].z=i;
    }
    sort(v+1,v+n+1);
    for(int i=n; i>0; --i)
        for(int j=v[i].y; j>=1; --j) if(0==mom[j]) {
            mom[j]=v[i].z;
            ++nrs;
            break;
        }
    cout<<nrs<<'\n';
    for(int i=1; i<=100000; ++i) if(mom[i]) cout<<mom[i]<<' ';
    return 0;
}
