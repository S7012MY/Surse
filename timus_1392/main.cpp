#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;

struct pl {
    int x,y,z,r;
} p[DN];

int n,nrc;
bitset<DN> viz;
vector<int> gr[DN],con[DN];

double dist(pl a,pl b) {
    double da=(a.x-b.x)*(a.x-b.x);
    double db=(a.y-b.y)*(a.y-b.y);
    double dc=(a.z-b.z)*(a.z-b.z);
    return sqrt(da+db+dc);
}

bool is(pl a, pl b) {
    double dst=dist(a,b);
    if(dst<(double)a.r+b.r) return 1;
    return 0;
}

void dfs(int s) {
    viz[s]=1;
    con[nrc].push_back(s);
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]) dfs(*i);
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) cin>>p[i].x>>p[i].y>>p[i].z>>p[i].r;
    for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) if(is(p[i],p[j])) {
        gr[i].push_back(j);
        gr[j].push_back(i);
    }
    for(int i=0; i<n; ++i) if(0==viz[i]) {
        ++nrc;
        dfs(i);
    }
    for(int i=1; i<=nrc; ++i) {
        sort(con[i].begin(),con[i].end());
        for(int j=0; j<(int)con[i].size()-1; ++j) cout<<con[i][j]<<", ";
        cout<<con[i][con[i].size()-1]<<'\n';
    }
    return 0;
}
