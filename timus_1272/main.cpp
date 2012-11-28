#include <iostream>
#include <vector>
#define DN 1000005
#define x first.first
#define y first.second
#define c second
using namespace std;

typedef pair<pair<int, int>, int>per;
int n,k,m,pre[DN],a,b;
vector<per> e;

int find(int i) {
    if(i==pre[i]) return i;
    pre[i]=find(pre[i]);
    return pre[i];
}

void unite(int a, int b) {
    pre[b]=a;
}

int main()
{
    cin>>n>>k>>m;
    for(int i=1; i<=k+m+10; ++i) pre[i]=i;
    for(int i=1; i<=k; ++i) {
        cin>>a>>b;
        e.push_back(make_pair(make_pair(a,b),0));
    }
    for(int i=1; i<=m; ++i) {
        cin>>a>>b;
        e.push_back(make_pair(make_pair(a,b),1));
    }
    int cst=0,i=0;
    for(int i=0;i<e.size(); ++i) {
        if(find(e[i].x)!=find(e[i].y)) {
            cst+=e[i].c;
            unite(find(e[i].x),find(e[i].y));
        }
    }
    cout<<cst;
    return 0;
}
