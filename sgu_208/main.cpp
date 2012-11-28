#include <iostream>
#include <vector>
#include <set>
#define DN 25
using namespace std;

int n,m,perm[DN*DN],mt[DN][DN],aux[DN][DN],mi[DN][DN],rez,rc,viz[DN*DN];
set<vector<int> > s;

void dfs(int s) {
    viz[s]=1;
    if(!viz[perm[s]]) dfs(perm[s]);
}

void countC(int mt[DN][DN]) {
    rc=0;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        perm[(i-1)*m+j]=mt[i][j];
        viz[(i-1)*m+j]=0;
    }
    for(int i=1; i<=n*m; ++i) if(!viz[i]) dfs(i),++rc;
}

void afis(int mt[DN][DN]) {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cout<<mt[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}

void rotate180(int mt[DN][DN]) {
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) aux[i][j]=mt[n-i+1][m-j+1];
    //afis(aux);
}

void rotate90(int mt[DN][DN]) {
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) aux[i][j]=mt[n-j+1][i];
    //afis(aux);
}

void fa(int mt[DN][DN]) {
    int nr=0;
    vector<int> v;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) v.push_back(mt[i][j]);
    if(s.find(v)!=s.end()) return;
    //afis(mt);
    s.insert(v);
    countC(mt);
    rez+=(1<<rc);
    int aux[DN][DN];
    //perc
    for(int i=1; i<=n; ++i) {
        for(int j=2; j<=m; ++j) aux[i][j-1]=mt[i][j];
        aux[i][m]=mt[i][1];
    }
    fa(aux);
    //perl
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=m; ++j) aux[i-1][j]=mt[i][j];
    }
    for(int j=1; j<=m; ++j) aux[n][j]=mt[1][j];
    fa(aux);
    //rotatie
    rotate180(mt);
    fa(aux);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) mi[i][j]=(i-1)*m+j;
    cout<<rc<<'\n';
    fa(mi);
    if(n==m) {
        rotate90(mi);
        fa(mi);
    }
    cout<<rc;
    return 0;
}
