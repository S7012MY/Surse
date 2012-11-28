#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char di[15][15],lc[105],viz[15][15];
int n,m,p,gasit;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<char> r;

bool check(int a, int b) {
    if(0>a||0>b || a>=n || b>=m) return 0;
    return 1;
}

void dfs(int i,int j,int lg) {
   // cout<<endl<<i<<' '<<j<<' '<<lc[lg]<<' '<<lc;
    viz[i][j]=1;
    if(lg==strlen(lc)) {
        gasit=1;
        return;
    }
    for(int d=0; d<4; ++d) if(!gasit && check(i+dx[d],j+dy[d]) && di[i+dx[d]][j+dy[d]]==lc[lg] && !viz[i+dx[d]][j+dy[d]])
        dfs(i+dx[d],j+dy[d],lg+1);
    if(!gasit) viz[i][j]=0;
}

int main()
{
    cin>>n>>m>>p;
    for(int i=0; i<n; ++i) cin>>di[i];
    for(int i=0; i<p; ++i)  {
        cin>>lc;
        //cout<<":"<<lc<<endl;
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(di[i][j]==lc[0] && !viz[i][j]) {
            gasit=0;
            dfs(i,j,1);
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            if(!viz[i][j]) {
                r.push_back(di[i][j]);
                //cout<<di[i][j];
            }else;// cout<<"-";
       // cout<<endl;
    }
    sort(r.begin(),r.end());
    for(int i=0; i<r.size(); ++i) cout<<r[i];
    return 0;
}
