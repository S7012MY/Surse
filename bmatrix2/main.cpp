#include <iostream>
#include <fstream>
#include <stack>
#define x first
#define y second
#define DN 205
#define mp make_pair
#include <cstring>
using namespace std;

typedef pair<int,int> per;

int n,m,rez,v[DN];
char mt[DN][DN];
stack<per> s;

int pmax(int x1, int y1, int x2, int y2) {
    int r=0;
    memset(v,0,sizeof(v));
    for(int i=y1; i<=y2; ++i) v[i]=mt[x1][i];
    v[y2+1]=0;
    for(int i=x1+1; i<=x2; ++i) {
        for(int j=y1; j<=y2; ++j)
            if(mt[i][j]=='0') v[j]=0;
            else ++v[j];
        s.push(mp(0,1));
        for(int j=y1; j<=y2; ++j) {
            rez=max(rez,v[j]);
            int lst=j;
            for(;s.size() && s.top().x>=v[j]; s.pop()) {
                r=max(r,s.top().x*(j-s.top().y));
                lst=s.top().y;
            }
            s.push(mp(v[j],lst));
        }
    }
    for(;s.size();s.pop());
    return r;
}

int main()
{
    ifstream f("bmatrix.in");
    ofstream g("bmatrix.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>(mt[i]+1);
    }
    for(int i=1; i<=n; ++i) {
        rez=max(rez,pmax(1,1,i,m)+pmax(i+1,1,i+1,m));
    }
    for(int i=1; i<=m; ++i) {
        rez=max(rez,pmax(1,1,n,i)+pmax(1,i+1,n,m));
    }
    g<<rez;
    return 0;
}
