#include <iostream>
#include <fstream>
#include <vector>
#define DN 105
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;

char ma[DN][DN],r[DN][DN];
int n,m,cz,cu;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
vector<per> semn;

bool check() {
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        cz=cu=0;
        for(int d=0; d<4; ++d)
            if('1'==ma[i+dx[d]][j+dy[d]]) ++cu;
            else if('0'==ma[i+dx[d]][j+dy[d]]) ++cz;
        if('1'==ma[i][j] && cu&1) return 0;
        if('0'==ma[i][j] && cz&1) return 0;
    }
    return 1;
}

int main()
{
    ifstream f("go2.in");
    ofstream g("go2.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        if('?'==ma[i][j]) semn.push_back(mp(i,j));
    }
    int sz=semn.size(),rez=0;
    for(int i=0; i<(1<<sz); ++i) {
        for(int j=0; j<sz; ++j)
            if(i&(1<<j)) ma[semn[j].x][semn[j].y]='1';
            else ma[semn[j].x][semn[j].y]='0';
        if(check()) ++rez;
    }
    cout<<rez;
    g<<rez;
    return 0;
}
