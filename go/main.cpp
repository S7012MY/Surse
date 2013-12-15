#include <fstream>
#include <set>
#define DN 1005
using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,s[DN][DN],fin[DN][DN],nrc,r=-1,rx,ry;
set<pair<int, int> > ss;

bool check(int a, int b) {
    if(0>a || 0>b || a>=n || b>=m) return 0;
    return 1;
}

void df(int a, int b) {
    s[a][b]=-1;
    ++nrc;
    for(int d=0; d<4; ++d) {
        int ii=a+dx[d],jj=b+dy[d];
        if(check(ii,jj)) {
            if(0==s[ii][jj]) ss.insert(make_pair(ii,jj));
            if(2==s[ii][jj]) df(ii,jj);
        }
    }
}

int main()
{
    ifstream f("go.in");
    ofstream g("go.out");
    f>>n>>m;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) f>>s[i][j];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(2==s[i][j]){
        nrc=0;
        df(i,j);
        if(1==ss.size()) fin[ss.begin()->first][ss.begin()->second]+=nrc;
        ss.clear();
    }
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(0==s[i][j]) {
        if(fin[i][j]>r) {
            r=fin[i][j];
            rx=i;
            ry=j;
        }
    }
    g<<rx<<' '<<ry;
    return 0;
}
