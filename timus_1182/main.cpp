#include <iostream>
#include <bitset>
#include <cstdlib>
#include <vector>
#define DN 105
using namespace std;

bitset<DN> viz;
int n,ma[DN][DN],unde[DN],cnt[3];
vector<int> e[3];

void impos() {
    cout<<"No solution";
    exit(0);
}

int check(int n,int c) {
    for(int i=0; i<e[c].size(); ++i) if(!ma[n][e[c][i]]) return 0;
    return 1;
}

void dfs(int s, int c) {
    unde[s]=c;
    if(!check(s,c)) impos();
    e[c].push_back(s);
    ++cnt[c];
    viz[s]=1;
    for(int i=1; i<=n; ++i) if(i!=s && 0==ma[s][i] && 0==viz[i]) {
        if(unde[i]&&unde[i]!=3-c) impos();
        dfs(i,3-c);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int nr;
        for(cin>>nr;nr!=0;cin>>nr) ma[i][nr]=1;
    }
    for(int i=1; i<=n; ++i) if(0==viz[i]) {
        if(cnt[1]>cnt[2]) {
            if(check(i,2)) dfs(i,2);
            else dfs(i,1);
        }
        else {
            if(check(i,1)) dfs(i,1);
            else dfs(i,2);
        }
    }
    cout<<cnt[1]<<' ';
    for(int i=1; i<=n; ++i) if(1==unde[i]) cout<<i<<' ';
    cout<<'\n';
    cout<<cnt[2]<<' ';
    for(int i=1; i<=n; ++i) if(2==unde[i]) cout<<i<<' ';
    return 0;
}
