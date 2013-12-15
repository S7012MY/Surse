#include <iostream>
#include <queue>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <vector>
#define x first
#define y second
#define mp make_pair
#define DN 1005
using namespace std;

typedef pair<int,int> per;

int n,m,k,dst[35][36],cpath,dist[DN][DN],indd[DN][DN],cind;
string s[DN],traseu;
per pLit[36],start,end;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
queue<per> c;

bool check(int i,int j) {
    return (i>=0 && j>=0 && i<n && j<m && s[i][j]!='#');
}

int cst(char c) {
    if(isalpha(c)) return 1;
    return c-'0';
}

int dmin(per inc,per sf,int ind) {
    dist[inc.x][inc.y]=1;
    for(c.push(inc);c.size();c.pop()) {
        per fr=c.front();
        indd[fr.x][fr.y]=ind;
        for(int d=0; d<4; ++d) {
            int ii=fr.x+dx[d],jj=fr.y+dy[d];
            if(check(ii,jj) && indd[ii][jj]!=ind || (indd[ii][jj]==ind && dist[ii][jj]>dist[fr.x][fr.y]+cst(s[fr.x][fr.y]))) {
                dist[ii][jj]=dist[fr.x][fr.y]+cst(s[fr.x][fr.y]);
                c.push(mp(ii,jj));
            }
        }
    }
    return dist[sf.x][sf.y]-1;
}

per pre[DN][DN];
vector<per> sol;

void rtras(per inc,per sf,int ind) {
    dist[inc.x][inc.y]=1;
    pre[inc.x][inc.y]=mp(-1,-1);
    //cout<<inc.x<<' '<<inc.y<<'\n';
    for(c.push(inc);c.size();c.pop()) {
        per fr=c.front();
        indd[fr.x][fr.y]=ind;
        for(int d=0; d<4; ++d) {
            int ii=fr.x+dx[d],jj=fr.y+dy[d];
            if(check(ii,jj) && indd[ii][jj]!=ind || (indd[ii][jj]==ind && dist[ii][jj]>dist[fr.x][fr.y]+cst(s[fr.x][fr.y]))) {
                dist[ii][jj]=dist[fr.x][fr.y]+cst(s[fr.x][fr.y]);
                pre[ii][jj]=fr;
                c.push(mp(ii,jj));
            }
        }
    }
    for(;pre[sf.x][sf.y]!=mp(-1,-1);) {
        sf=pre[sf.x][sf.y];
        sol.push_back(sf);
    }
    int cd=0;
    for(int i=sol.size()-1; i>=0; --i) {
        //cout<<sol[i].x<<' '<<sol[i].y<<'\n';
        if(cd+cst(s[sol[i].x][sol[i].y])>k) {
            cout<<sol[i].x+1<<' '<<sol[i].y+1<<'\n';
            exit(0);
        }
        if(cd==k) {
            cout<<sol[i].x+1<<' '<<sol[i].y+1<<'\n';
            exit(0);
        }
        cd+=cst(s[sol[i].x][sol[i].y]);
    }
}

int main()
{
    cin>>n>>m>>k;
    cin.get();
    for(int i=0; i<n; ++i) getline(cin,s[i]);
    cin>>start.x>>start.y>>traseu>>end.x>>end.y;

    --start.x; --start.y; --end.x; --end.y;

    for(int i=0; i<26; ++i) pLit[i].x=-1;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(isalpha(s[i][j])) {
        pLit[s[i][j]-'a']=mp(i,j);
        //cerr<<i<<' '<<j<<'\n';
    }

    for(int i=0; i<26; ++i) if(pLit[i].x!=-1) for(int j=i+1; j<26; ++j) if(pLit[j].x!=-1) {
        dst[i][j]=dst[j][i]=dmin(pLit[i],pLit[j],++cind);
        //cout<<i<<' '<<j<<' '<<dst[i][j]<<'\n';
    }

    if(dmin(start,pLit[traseu[0]-'a'],++cind)>k) {
        rtras(start,pLit[traseu[0]-'a'],++cind);
    }
    k-=dmin(start,pLit[traseu[0]-'a'],++cind);
    //cerr<<'\n'<<k<<' '<<dmin(start,pLit[traseu[0]-'a'],100)<<'\n';
    //cerr<<dst[0][1]<<'\n';
    for(int i=1; i<traseu.size(); ++i) {
        int a=traseu[i-1]-'a',b=traseu[i]-'a';
        if(dst[a][b]>k) {
            //cerr<<i<<'\n';
            rtras(pLit[a],pLit[b],++cind);
        }
        k-=dst[a][b];
    }
    int sz=traseu.size()-1;
    if(dmin(pLit[traseu[sz]-'a'],end,++cind)>k) rtras(pLit[traseu[sz]-'a'],end,++cind);
    cout<<end.x+1<<' '<<end.y+1;
    return 0;
}
