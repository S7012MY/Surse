#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n;
bitset<DN> viz;
vector<vector<int> > v;
string s[DN];
vector<int> gr[DN];

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]) dfs(*i);
}

int main()
{
    cin>>n;
    v.resize(n+1);
    for(int i=1; i<=n; ++i) {
        v[i].resize(3);
        cin>>s[i]>>v[i][0]>>v[i][1]>>v[i][2];
        //sort(v[i].rbegin(),v[i].rend());
    }

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) if(i!=j) {
            int cnt=0;
            for(int k=0; k<3; ++k) if(v[i][k]>v[j][k]) ++cnt;
            if(cnt>1) gr[i].push_back(j);
        }

    for(int i=1; i<=n; ++i) {
        viz&=0;
        int ok=1;
        dfs(i);
        for(int i=1; i<=n; ++i) if(0==viz[i]) ok=0;
        if(ok) cout<<s[i]<<'\n';
    }
    return 0;
}
