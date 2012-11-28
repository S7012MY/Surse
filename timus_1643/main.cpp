#include <stack>
#include <vector>
#include <cctype>
#include <cstdio>
#include <bitset>
#define DN 105
#define VAL_MARE 99999
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

const int dx[]={-1,-1,-1,0,1,1, 1, 0},
          dy[]={-1, 0, 1,1,1,0,-1,-1};

int n,m,c1[DN][DN],c2[DN][DN],c3[DN][DN],bd=VAL_MARE;
char mp[DN][DN];
bitset<26> v;
vector<per> lst[26];
per pf,pa1,pa2;

bool check(int a, int b) {
    if(a>=0 && b>=0 && a<n && b<m) return 1;
    return 0;
}

stack<per> pr,cr;

void bfs(per pi,int c[DN][DN]) {
    c[pi.x][pi.y]=1;
    pr.push(pi);
    do {
        for(;cr.size();cr.pop());
        for(;pr.size();) {
            per fr=pr.top();
            pr.pop();
            int p=mp[fr.x][fr.y]-'A';
            if(isalpha(mp[fr.x][fr.y]) && 0==v[p]) {
                v[p]=1;
                for(int i=0; i<lst[p].size(); ++i) {
                    int ii=lst[p][i].x,jj=lst[p][i].y;
                    if(0==c[ii][jj]) {
                        c[ii][jj]=c[fr.x][fr.y];
                        pr.push(make_pair(ii,jj));
                    }
                }
            }
            for(int d=0; d<8; ++d) {
                int ii=fr.x+dx[d],jj=fr.y+dy[d];
                if(check(ii,jj) && '#'!=mp[ii][jj] && '*'!=mp[ii][jj] && 0==c[ii][jj]) {
                    c[ii][jj]=c[fr.x][fr.y]+1;
                    cr.push(make_pair(ii,jj));
                }
            }
        }
        pr=cr;
    }while(cr.size());
}

void printm(int c[DN][DN]) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) printf("%d ",c[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%s",mp[i]);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        if(isalpha(mp[i][j])) lst[mp[i][j]-'A'].push_back(make_pair(i,j));
        else if('*'==mp[i][j]) pf=make_pair(i,j);
        else if('$'==mp[i][j]) pa1=make_pair(i,j);
        else if('!'==mp[i][j]) pa2=make_pair(i,j);
    bfs(pf,c1);
    v&=0;
    bfs(pa1,c2);
    v&=0;
    bfs(pa2,c3);
    //printm(c1); printm(c2); printm(c3);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        if(make_pair(i,j)!=pf && c2[i][j] && c1[i][j] && c3[i][j]) bd=min(bd,max(c2[i][j],c3[i][j])+c1[i][j]);
    if(bd!=VAL_MARE) printf("%d",bd-2);
    else printf("Impossible");
    return 0;
}
