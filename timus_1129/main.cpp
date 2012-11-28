#include <iostream>
#include <cstdlib>
#define DN 105
using namespace std;

int n,k,nr;
int ma[DN][DN],tp[DN][DN],viz[DN],grad[DN];

int dfs(int s) {
    viz[s]=1;
    int ok=0;
    for(int i=1; i<=n; ++i)
        if(ma[s][i] && !tp[s][i]) {
            tp[s][i]=1;
            tp[i][s]=2;
            ok=1;
            if(0==dfs(i)) return 0;
        }
    if(!ok)
        return 0;
    return 1;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>k;
        grad[i]=k;
        for(int j=1; j<=k; ++j) {
            cin>>nr;
            ma[i][nr]=ma[nr][i]=1;
        }
    }
    for(int i=1; i<=n; ++i) if(grad[i]&1) dfs(i);

    for(int i=1; i<=n; ++i) dfs(i);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) if(tp[i][j]) {
            if(1==tp[i][j]) cout<<"G ";
            else cout<<"Y ";
        }
        cout<<"\n";
    }
    return 0;
}
