#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#define mp make_pair
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef set<per>::iterator is;
int t,n,col[DN];
per p[DN];
map<int,int>mx,my;

int main()
{
    ifstream f("arbsat.in");
    ofstream g("arbsat.out");
    for(f>>t;t;--t) {
        f>>n;
        for(int i=1; i<=n; ++i) {
            f>>p[i].x>>p[i].y;
            if(mx.find(p[i].x)==mx.end()) mx[p[i].x]=1;
            else ++mx[p[i].x];
            if(my.find(p[i].y)==my.end()) my[p[i].y]=1;
            else ++my[p[i].y];
        }
        sort(p+1,p+n+1);
        int ok=1;
        if(mx[p[1].x]+my[p[1].x]<2) ok=0;
        if(mx[p[n].x]+my[p[n].x]<2) ok=0;
        for(int i=2; i<n; ++i)
            if(mx[p[i].x]+my[p[i].y]<4) ok=0;
        mx.clear();my.clear();
        g<<ok<<'\n';
    }
    return 0;
}
