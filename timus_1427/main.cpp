#include <iostream>
#include <string>
#include <cctype>
#define DN 200005
using namespace std;

int n,m,lg,dp[DN];
string s;

int main()
{
    cin>>n>>m;
    cin.get();
    getline(cin,s);
    lg=s.size();
    int i,lp=-1;
    for(i=0; i<n && i<lg; ++i) {
        dp[i]=1;
        if(!isalpha(s[i]) && ' '!=s[i]) lp=i;
    }
    for(;lp==-1 && i<m && i<lg; ++i) {
        dp[i]=1;
        if(!isalpha(s[i]) && ' '!=s[i]) lp=i;
    }
    for(;i<lg; ++i) {
        dp[i]=dp[i-n]+1;
        if(!isalpha(s[i]) && ' '!=s[i]) lp=i;
        if(n<i-lp) {
            if(i-m<0) dp[i]=min(dp[i],dp[lp]+1);
            else dp[i]=min(dp[i],dp[max(lp,i-m)]+1);
        }
    }
    if(lg==0) {
        cout<<0;
        return 0;
    }
    //for(int i=0; i<lg; ++i) cout<<dp[i];
    cout<<dp[lg-1];
    return 0;
}
