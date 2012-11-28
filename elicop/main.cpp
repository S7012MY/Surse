#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define DN 105
using namespace std;

int n,m,k,tt[DN][DN],rc1;
vector<int> sol;

bool p1(int sx,int sy,int fx,int fy) {
    int t=0,nrz=0;
    if(sy>fy) {
        int cnt=0;
        for(int i=sx; i<=fx; ++i) {
            for(int j=fy; j<=sy-cnt; ++j) {
                ++t;
                if(!tt[i][j])++nrz;
                //cout<<i<<' '<<j<<'\n';
            }
            ++cnt;
        }
    }else {
        int cnt=0;
        for(int i=sx; i<=fx; ++i) {
            for(int j=sy+cnt; j<=fy; ++j) {
                ++t;
                if(!tt[i][j]) ++nrz;
            }
            ++cnt;
        }
    }
    if(!nrz)++rc1;
    return nrz<=t/2;
}

bool p2(int sx, int sy, int fx,int fy) {
    int t=0,nrz=0;
    if(sy>fy) {
        int cnt=0;
        for(int i=sx; i<=fx; ++i) {
            for(int j=sy-cnt;j<=sy; ++j) {
                ++t;
                if(!tt[i][j]) ++nrz;
            }
            ++cnt;
        }
    }else {
        int cnt=0;
        for(int i=sx; i<=fx; ++i) {
            for(int j=sy; j<=sy+cnt; ++j) {
                ++t;
                if(!tt[i][j]) ++nrz;
            }
            ++cnt;
        }
    }
    if(!nrz) ++rc1;
    return nrz<=t/2;
}

int main()
{
    ifstream f("elicop.in");
    ofstream g("elicop.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) f>>tt[i][j];
    f>>k;
    for(int i=1; i<=k; ++i) {
        int sx,sy,fx,fy,tp;
        f>>sx>>sy>>fx>>fy>>tp;
        if(sx>fx) {
            swap(sx,fx);
            swap(sy,fy);
        }
        if(1==tp) {
            if(!p1(sx,sy,fx,fy)) sol.push_back(i);
        }else {
            if(!p2(sx,sy,fx,fy)) sol.push_back(i);
        }
    }
    g<<rc1<<'\n';
    g<<sol.size()<<' ';
    for(int i=0; i<sol.size(); ++i) g<<sol[i]<<' ';
    return 0;
}
