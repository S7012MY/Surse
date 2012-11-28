#include <fstream>
#include <bitset>
#include <queue>
#define DN 505
#define DP 205
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<short,short> per;

short n,p,k,dist[DN][DP],d[DP],c[DP];
bitset<DP> ma[DP];

class cmp {
public:
    bool operator() (const per &a, const per &b) {
        return dist[a.x][a.y]>dist[b.x][b.y];
    }
};

priority_queue<per,vector<per>,cmp > q;

int main()
{
    ifstream f("zmeu2.in");
    ofstream g("zmeu2.out");
    f>>n>>p>>k;
    for(int i=1; i<=p; ++i) {
        f>>d[i]>>c[i];
        ma[i][i]=1;
    }
    ma[1][p]=1;
    for(int i=1; i<=k; ++i) {
        int a,b;
        f>>a>>b;
        ma[a][b]=1;
    }
    dist[1][n-c[1]]=d[1];
    short cmin=9999;
    for(q.push(mp(1,n-c[1]));q.size();) {
        int nc=q.top().x,cap=q.top().y;
        q.pop();
       // inq[nc][cap]=0;
        //cout<<nc<<' '<<cap<<' '<<dist[nc][cap]<<'\n';
        for(int i=1; i<=p; ++i) if(0==ma[nc][i]) {
            int cnou=cap-c[i];
            if(cnou<=0) continue;
            if(0==dist[i][cnou] || dist[i][cnou]>dist[nc][cap]+d[i]) {
                dist[i][cnou]=dist[nc][cap]+d[i];
                if(i==p) cmin=min(cmin,dist[i][cnou]);
              //  if(!inq[i][cnou]) {
                    q.push(mp(i,cnou));
                   // inq[i][cnou]=1;
               // }
            }
        }
    }

    if(cmin!=9999) g<<cmin;
    else g<<"-1";
    return 0;
}
