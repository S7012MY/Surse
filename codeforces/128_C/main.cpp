#include <iostream>
#include <algorithm>
#define DN 100005
using namespace std;

int n,d,sol[DN],sz;
long long a,b;
pair<long long,int> cst[DN];

int main()
{
    cin>>n>>d;
    cin>>a>>b;
    for(int i=1; i<=n; ++i) {
        int x,y;
        cin>>x>>y;
        cst[i].first=x*a+y*b;
        cst[i].second=i;
    }
    sort(cst+1,cst+n+1);
    for(int i=1; i<=n; ++i) {
        if(d>=cst[i].first) {
            d-=cst[i].first;
            sol[++sz]=cst[i].second;
        }
        else break;
    }
    cout<<sz<<'\n';
    for(int i=1; i<=sz; ++i) cout<<sol[i]<<' ';
    return 0;
}
