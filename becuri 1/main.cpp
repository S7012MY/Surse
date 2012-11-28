#include <iostream>
#include <fstream>
#include <vector>
#define DN 505
#define pb push_back
#define x first
#define y second
using namespace std;

int n,m,b[DN][DN],act[DN],ok,cp[DN][DN],sum;
vector<int> l1,c1,l2,c2;
vector<pair<int,int> > r1,r2;

int main()
{
    ifstream f("becuri.in");
    ofstream g("becuri.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        f>>b[i][j];
        cp[i][j]=b[i][j];
        sum+=b[i][j];
    }
    if(sum==0) {
        cout<<0;
        return 0;
    }
    // Nu actionez prima linie.
    ok=1;
    for(int j=1; j<=m; ++j) if(b[1][j]) {
        act[j]=1;
        c1.pb(j);
    }
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=m; ++j) if(act[j]) b[i][j]=!b[i][j];
        for(int j=2; j<=m; ++j) if(b[i][j]!=b[i][1]) ok=0;
        if(b[i][1]) l1.pb(i);
    }


    int nl=l1.size(),nc=c1.size();
    int lm=max(nl,nc);

    for(int i=0; i<lm && nl && nc; ++i)
        r1.pb(make_pair(l1[min(i,nl-1)],c1[min(i,nc-1)]));
    if((nc+nl)&1) ok=0;
    if(nl==0 || nc==0) ok=0;

    // Actionez prima linie
    int ok2=1;
    for(int i=1; i<=m; ++i) act[i]=0;

    l2.pb(1);
    for(int i=1; i<=m; ++i) if(!cp[1][i]) {
        act[i]=1;
        c2.pb(i);
    }
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=m; ++j) if(act[j]) cp[i][j]=!cp[i][j];
        for(int j=2; j<=m; ++j) if(cp[i][j]!=cp[i][1]) ok2=0;
        if(cp[i][1]) l2.pb(i);
    }

    nl=l2.size(),nc=c2.size(); lm=max(nl,nc);

    for(int i=0; i<lm && nl && nc; ++i)
        r2.pb(make_pair(l2[min(i,nl-1)],c2[min(i,nc-1)]));
    if((nc+nl)&1) ok2=0;
    if(nl==0 || nc==0) ok2=0;

    //cout<<ok<<' '<<ok2<<'\n';
    if(ok|ok2) {
        if(ok&&ok2 && r1.size()<r2.size()) {
            g<<r1.size()<<'\n';
            for(int i=0; i<r1.size(); ++i) g<<r1[i].x<<' '<<r1[i].y<<'\n';
        }else if(ok&&ok2 && r1.size()>=r2.size()){
            g<<r2.size()<<'\n';
            if(ok&&ok2 && r1.size()>=r2.size()) for(int i=0; i<r2.size(); ++i) g<<r2[i].x<<' '<<r2[i].y<<'\n';
        }else if(ok2) {
            g<<r2.size()<<'\n';
            for(int i=0; i<l2.size(); ++i) for(int i=0; i<r2.size(); ++i) g<<r2[i].x<<' '<<r2[i].y<<'\n';
        }else {
            g<<r1.size()<<'\n';
            for(int i=0; i<r1.size(); ++i) g<<r1[i].x<<' '<<r1[i].y<<'\n';
        }
    }
    else g<<-1;
    return 0;
}
