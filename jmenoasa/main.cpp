#include <iostream>
#include <fstream>
#include <stack>
#define DN 1005
#define x first
#define y second
using namespace std;

int n,m,mt[DN][DN],v[DN],rez,vnou[DN][DN];
stack<pair<int,int> > s;

int main()
{
    ifstream f("jmenoasa.in");
    ifstream ok("jmenoasa.out");
    f>>n>>m;
    for(int i=0; i<=m+1; ++i) mt[0][i]=-1;
    for(int i=0; i<=n+1; ++i) mt[i][0]=-1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            f>>mt[i][j];
            if(mt[i][j]>mt[i-1][j]) vnou[i][j]=vnou[i-1][j]+1;
            else vnou[i][j]=0;
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j)
            if(mt[i][j]>mt[i-1][j]) ++v[j];
            else v[j]=1;
        v[m+1]=0;
        s.push(make_pair(0,1));
        for(int j=1; j<=m+1; ++j) {
            int ec=v[j],lst=j;
            if(mt[i][j]<=mt[i][j-1]) {
                for(;s.size();s.pop()) rez=max(rez,s.top().x*(j-s.top().y));
                s.push(make_pair(vnou[i][j],j));
                v[j]=0;
                cout<<s.top().x<<' '<<s.top().y<<' '<<rez<<" --\n";
                continue;
            }
            for(;s.size() && s.top().x>=ec;s.pop()) {
                rez=max(rez,s.top().x*(j-s.top().y));
                lst=s.top().y;
            }
            s.push(make_pair(ec,lst));
            cout<<s.top().x<<' '<<s.top().y<<' '<<rez<<'\n';
        }
        for(;s.size(); s.pop()) rez=max(rez,s.top().x*(n-s.top().y+1));
        cout<<'\n';
    }
    int rbun;
    ok>>rbun;
    if(rez!=rbun) {
        cout<<rez<<' '<<"Gresit";
        cout.flush();
        while(1);
    }
    return 0;
}
