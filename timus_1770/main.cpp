#include <iostream>
#define DN 305
using namespace std;

int n,rf[DN][DN],in[DN][DN];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin>>in[i][j];
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(in[i][j]+in[j][i]<=1 && i!=j) rf[i][j]=rf[j][i]=1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j)
            cout<<rf[i][j];
        cout<<'\n';
    }
    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(k!=i && i!=j && i!=k && rf[i][k] && rf[k][j]) {
            if(rf[i][j]) rf[i][j]=min(rf[i][j],rf[i][k]+rf[k][j]);
            else rf[i][j]=rf[i][k]+rf[k][j];
        }

    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(rf[i][j]!=in[i][j]) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j)
            if(!in[i][j] && in[j][i]) cout<<'1';
            else if(!in[i][j]) cout<<'0';
            else cout<<'2';
        cout<<'\n';
    }
    return 0;
}
