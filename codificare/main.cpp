#include <iostream>
#include <fstream>
#include <string>
#define MOD 666013
using namespace std;

int fr[26],fct[100005]={1};
int n;//,nr[1005][1005];
string s;

int lgput(int b,int exp) {
    if(exp==1) return b;
    if(exp&1) return (lgput(b,exp-1)*1LL*b)%MOD;
    int r=lgput(b,exp/2);
    return (r*1LL*r)%MOD;
}

int inv(int k) {
    return lgput(k,MOD-2);
}

int cmb(int n,int k) {
    int in=inv((fct[k]*1LL*fct[n-k])%MOD);
    return (fct[n]*1LL*in)%MOD;
}

int main()
{
    /*nr[0][0]=1;
    for(int i=0; i<=100; ++i) for(int j=0; j<=100; ++j) {
        if(i) nr[i][j]+=nr[i-1][j];
        if(j) nr[i][j]+=nr[i][j-1];
    }
    cout<<nr[0][6]<<' '<<nr[1][5]<<' '<<nr[2][4]<<' '<<nr[3][3]<<' '<<nr[4][2]<<' '<<nr[5][1];*/
    ifstream f("codificare.in");
    ofstream g("codificare.out");
    f>>n>>s;
    for(int i=1; i<=n; ++i) fct[i]=(fct[i-1]*1LL*i)%MOD;
    for(int i=0; i<n; ++i) {
        int st=i,dr=n-i-1;
        fr[s[i]-'a']+=cmb(st+dr,st);
        if(fr[s[i]-'a']>=MOD) fr[s[i]-'a']-=MOD;
    }
    int cnt=0;
    for(int i=0; i<26; ++i) cnt+=(fr[i]>0);
    g<<cnt<<'\n';
    for(char i='a'; i<='z'; ++i) if(fr[i-'a']) g<<i<<' '<<fr[i-'a']<<'\n';
    return 0;
}
