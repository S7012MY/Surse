#include <iostream>
#define DN 205
using namespace std;

int n,m,bs,nr=(1<<20);
char mt[DN][DN];


int main() {
    cin>>n>>m;
    if(n<3 || m<3) {
        cout<<"No solution";
        return 0;
    }
    for(int start=1; start<4; ++start) {
        int cnt=0;
        for(int i=1+start; i<=n+start; ++i) for(int j=1; j<=m; ++j) mt[i][j]='0';
        for(int i=1+start; i<=n+start; ++i) for(int j=1; j<=m; ++j) if(i%3==j%3)
            ++cnt,mt[i][j]='#';
        if(cnt<nr) {
            nr=cnt;
            bs=start;
        }
    }
    int start=bs;
    for(int i=1+start; i<=n+start; ++i) for(int j=1; j<=m; ++j) mt[i][j]='0';
    for(int i=1+start; i<=n+start; ++i) {
        for(int j=1; j<=m; ++j) {
            if(i%3==j%3) mt[i][j]='#';
            cout<<mt[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
