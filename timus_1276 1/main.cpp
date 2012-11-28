#include <iostream>
#include <map>
#include <string>
#define DN 51
using namespace std;

map<string,int> mp;
string s;
int n,K,v[4],b[4];
unsigned long long nr[DN][DN][DN][DN][5],rez;
int main()
{
    cin>>n>>K;
    mp["AA"]=0; mp["AB"]=1; mp["BA"]=2; mp["BB"]=3;
    cin>>s;
    int l1,l2;
    if('A'==s[0]) l1=0,l2=2;
    else l1=1,l2=3;
    if('A'==s[1]) ++b[0],++b[1];
    else ++b[2],++b[3];
    for(int i=1; i<=n; ++i) {
        cin>>s;
        ++v[mp[s]];
    }
    if(b[0]) {
        if(v[0]) ++nr[1][0][0][0][0];
        if(v[1]) ++nr[0][1][0][0][1];
    }else {
        if(v[2]) ++nr[0][0][1][0][2];
        if(v[3]) ++nr[0][0][0][1][3];
    }
    for(int i=0; i<=v[0]; ++i) for(int j=0; j<=v[1]; ++j) for(int k=0; k<=v[2]; ++k) for(int l=0; l<=v[3]; ++l) {
        if(i) nr[i][j][k][l][0]+=nr[i-1][j][k][l][0]+nr[i-1][j][k][l][2];
        if(j) nr[i][j][k][l][1]+=nr[i][j-1][k][l][0]+nr[i][j-1][k][l][2];
        if(k) nr[i][j][k][l][2]+=nr[i][j][k-1][l][1]+nr[i][j][k-1][l][3];
        if(l) nr[i][j][k][l][3]+=nr[i][j][k][l-1][1]+nr[i][j][k][l-1][3];
        if(i+j+k+l==K) for(int p=0; p<4; ++p) if(p==l1 || p==l2) rez+=nr[i][j][k][l][p];
       // for(int p=0; p<4; ++p) if(nr[i][j][k][l][p]) cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<p<<'\n';
    }
    if(rez) cout<<"YES\n"<<rez<<'\n';
    else cout<<"NO\n";
    return 0;
}
