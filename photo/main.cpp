#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define DN 101
#define MLT (1<<30)
using namespace std;

typedef pair<int,int> per;

int n,a;
char bst[DN][DN][DN];
per p[DN];

inline int min(int a, int b) {
    if(a<b)return a;
    return b;
}

char memo(int ls, int ld, int ih) {
    if(bst[ls][ld][ih]) return bst[ls][ld][ih]-1;
    vector<char> v;
    for(int i=ls; i<=ld; ++i) if(p[i].y>=p[ih].y) v.push_back(i);
    if(v.size()<2) {
        bst[ls][ld][ih]=v.size()+1;
        return v.size();
    }
    char r=DN;int sz=v.size();
    for(int i=0; i<sz-1; ++i) {
        char st=memo(ls,v[i],ih);
        if(st>r) continue;
        r=min(r,st+memo(v[i+1],ld,ih));
    }

    int hmax=MLT,hmin=MLT,ind=-1,cnt=0;
    if(p[v[sz-1]].x-p[v[0]].x) hmax=a/(p[v[sz-1]].x-p[v[0]].x);
    for(int i=0; i<sz; ++i) if(p[v[i]].y>hmax){
        ++cnt;
        if(p[v[i]].y<hmin) {
            hmin=p[v[i]].y;
            ind=v[i];
        }
    }
    if(cnt!=v.size()) {
        if(ind!=-1) r=min(r,1+memo(ls,ld,ind));
        else r=min(r,1);
    }
    bst[ls][ld][ih]=r+1;
    return r;
}

int main()
{
    ifstream f("photo.in");
    ofstream g("photo.out");
    f>>n>>a;
    for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
    sort(p+1,p+n+1);
    //for(int i=0; i<DN; ++i) for(int j=0; j<DN; ++j) for(int k=0; k<DN; ++k) bst[i][j][k]=-1;
    g<<memo(1,n,0);
    return 0;
}
