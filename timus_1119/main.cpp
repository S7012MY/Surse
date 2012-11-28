#include <iostream>
#include <iomanip>
#include <bitset>
#define DN 1005
#define OS 141.421356
using namespace std;

double bw[2][DN];
int n,m,k;
bitset<DN> ism[DN];

int main()
{
    cin>>n>>m;
    for(cin>>k;k--;) {
        int a,b;
        cin>>a>>b;
        ism[a][b]=1;
    }
    bw[1][0]=-100;
    for(int i=1; i<=n+1; ++i) {
        for(int j=1; j<=m+1; ++j) {
            if(i==1) bw[i][j]=bw[i][j-1]+100;
            else if(j==1) bw[i&1][j]=bw[(i&1)^1][j]+100;
            else bw[i&1][j]=min(bw[(i&1)^1][j],bw[i&1][j-1])+100;
            if(ism[i-1][j-1]) bw[i&1][j]=min(bw[i&1][j],bw[(i&1)^1][j-1]+OS);
            //cout<<bw[i&1][j]<<' ';
        }
      // cout<<endl;
    }
    cout<<fixed<<setprecision(0)<<bw[(n+1)&1][m+1];
    return 0;
}
