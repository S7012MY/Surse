#include <cstdio>
#define DN 20005
int n,m,k,dp[3][DN];
char a[DN],b[DN];

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

inline int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("edist.in","r",stdin);
    freopen("edist.out","w",stdout);
    scanf("%d %d %d %s %s",&n,&m,&k,a+1,b+1);
    for(int i=1; i<=m; ++i) dp[0][i]=i;
    //for(int i=1; i<=n; ++i) dp[i][0]=i;
    for(int i=1;i<=n; ++i) {
        for(int j=max(i-k,0); j<=i+k && j<=m; ++j) {
            dp[i&1][0]=i;
            if(a[i]==b[j])
                dp[i&1][j]=dp[(i&1)^1][j-1];
            else
                dp[i&1][j]=min(dp[(i&1)^1][j]+1,
                           min(dp[i&1][j-1]+1,
                               dp[(i&1)^1][j-1]+1));
        }
    }
    printf("%d",dp[n&1][m]);
    return 0;
}
