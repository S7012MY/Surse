#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>
#define DN 1005
using namespace std;

int n,M,m[DN][DN],nviz,v[DN*DN],sv;
int dx[]={-1, 0, 1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1, 1, 0};
vector<pair<int,int> > s;
map<int,int> nxt;

bool check(int a, int b) {
    return (a>0 && b>0 && a<=n && b<=M);
}

void dfs(int x, int y) {
    //cout<<x<<' '<<y<<'\n';
    ++nviz;
    s.push_back(make_pair(x,y));
    for(int i=0; i<8; ++i) {
        int ii=x+dx[i],jj=y+dy[i];
        if(check(ii,jj) && nxt[m[x][y]]==m[ii][jj]) {
            dfs(ii,jj);
            break;
        }
    }
}

string inp;

int main()
{
    ifstream f("traseu2.in");
    ofstream g("traseu2.out");
    f>>n>>M;
    f.get();
    int px,py,mi=(1<<30);
    int tot=n*M;
    for(int i=1; i<=n; ++i) {
        getline(f,inp);
        int sz=0;
        for(int j=0; j<inp.size(); ++j) {
            if(inp[j]=='#') {
                m[i][++sz]=-1;
                --tot;
                continue;
            }else if(isdigit(inp[j])) {
                int nr=0;
                for(;isdigit(inp[j]);nr=nr*10+inp[j]-'0',++j);
                --j;
                m[i][++sz]=nr;
            }
        }
        for(int j=1; j<=M; ++j) {


            v[++sv]=m[i][j];
            //cout<<m[i][j]<<' ';
            if(mi>m[i][j] && m[i][j]!=-1) {
                mi=m[i][j];
                px=i; py=j;
            }
        }
    }
    if(!sv) {
        g<<"Exista solutie!\n0";
        return 0;
    }
    sort(v+1,v+sv+1);
    for(int i=2; i<=sv; ++i) nxt[v[i-1]]=v[i];
    nxt[v[sv]]=(1<<30);
    dfs(px,py);
    if(nviz!=tot) {
        g<<"Nu exista solutie!";
        return 0;
    }
    g<<"Exista solutie!\n"<<tot<<'\n';
    for(int i=0; i<s.size(); ++i) {
        g<<s[i].first<<' '<<s[i].second<<' '<<m[s[i].first][s[i].second]<<'\n';
    }
    return 0;
}
