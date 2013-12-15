#include <iostream>
#include <vector>
#include <queue>
#define DN 205
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<int>::iterator it;

vector<int> gr[DN],gt[DN];

int cst[DN][DN],rez=(1<<30);
int n,unde[DN],acc[DN],ft[DN];

void back(int nc,int co,int fs=0) {
   // cout<<nc<<' '<<co<<'\n';
    queue<int> c;
    vector<int> l;

    int lv=0;
    for(int i=1; i<=n; ++i) if(acc[i]) {
        ++lv;
        c.push(i);
    }

    for(;c.size();c.pop()) {
        int fr=c.front();
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(nc==unde[*i] && !acc[*i]) {
            int ok=1;
            for(it j=gt[*i].begin(); j!=gt[*i].end(); ++j) if(!acc[*j]) ok=0;
            if(!ok) continue;
            c.push(*i);
            acc[*i]=1;
            l.push_back(*i);
        }
    }
    int luate=0;
    for(int i=1; i<=n; ++i) if(acc[i]) ++luate;
   // for(int i=1; i<=n; ++i) cout<<acc[i]<<' ';
    //cout<<'\n';
    if(lv==luate && !fs) return;

    if(luate==n) rez=min(rez,co);
    else for(int i=1; i<=3; ++i) if(i!=nc) back(i,co+cst[nc][i]);
    for(int i=0; i<l.size(); ++i) acc[l[i]]=0;
}

int main()
{
    cst[1][2]=1; cst[1][3]=2;
    cst[2][1]=2; cst[2][3]=1;
    cst[3][1]=1; cst[3][2]=2;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>unde[i];
    for(int i=1; i<=n; ++i) {
        int k;
        cin>>k;
        if(k==0) ft[i]=1;
        for(;k;--k) {
            int a;
            cin>>a;
            gr[a].push_back(i);
            gt[i].push_back(a);
        }
    }
    for(int i=1; i<4; ++i) {
        for(int j=1; j<=n; ++j) if(unde[j]==i && ft[j]) acc[j]=1;
        back(i,0,1);
        for(int j=1; j<=n; ++j) acc[j]=0;
    }
    cout<<rez+n;
    return 0;
}
