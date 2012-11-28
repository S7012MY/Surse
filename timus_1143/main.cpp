#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#define DN 205
#define x first
#define y second
using namespace std;

typedef pair<double, double> per;

int n;
bitset<DN> calc[DN][DN];
double dp[2][DN][DN],bst;
per p[DN];

double dist(per a,per b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void memo(int nc, int i, int j) {
    //if(i>n || j>n || 1>i || 1>j) return;
    if(calc[nc==i][i][j]) return;
    if(i==j) {
        dp[nc==i][i][j]=0;
        calc[nc==i][i][j]=1;
        return;
    }
    int st=i+1,dr=j-1+n;
    if(nc==j) st=i;
    if(nc==i) dr=j;
    st%=n; dr%=n;
    memo(st,st,dr); memo(dr,st,dr);
    dp[nc==i][i][j]=min(dp[1][st][dr]+dist(p[nc],p[st]),dp[0][st][dr]+dist(p[nc],p[dr]));
    calc[nc==i][i][j]=1;
    //cout<<nc<<' '<<i<<' '<<j<<' '<<dp[nc][i][j]<<'\n';
    //cout.flush();
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) cin>>p[i].x>>p[i].y;
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)memo(i,i,j),memo(j,i,j);
    bst=min(dp[0][0][n-1],dp[1][0][n-1]);
    for(int i=1; i<n; ++i) bst=min(bst,min(dp[1][i][(i+n-1)%n],dp[0][i][(i+n-1)%n]));
    cout<<fixed<<setprecision(3)<<bst;
    return 0;
}
