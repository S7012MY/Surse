#include <iostream>
#include <cstring>
#define DN 105
using namespace std;

char s[DN];
int dp[DN][DN],n;

int memo(int a, int b) {
    if(dp[a][b]!=9999) return dp[a][b];
    if(a==b) {
        dp[a][b]=1;
        return 1;
    }
    if(a==b-1) {
        if((s[a]=='(' && s[b]==')') || (s[a]=='[' && s[b]==']')) dp[a][b]=0;
        else dp[a][b]=2;
        return dp[a][b];
    }
    if((s[a]=='(' && s[b]==')') || (s[a]=='[' && s[b]==']')) dp[a][b]=min(dp[a][b],memo(a+1,b-1));
    for(int i=a; i<b; ++i) dp[a][b]=min(dp[a][b],memo(a,i)+memo(i+1,b));
    return dp[a][b];
}

int main()
{
    cin>>s;
    n=strlen(s);
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dp[i][j]=9999;
    cout<<memo(0,n-1);
    return 0;
}
