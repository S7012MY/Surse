#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define DS 4000005
#define VMAX 2000000
#define VM VMAX
using namespace std;

int t,n,s[25],ok;
int dp[DS],fol[DS];

vector<int> v1,v2;

ifstream f("inp.in");
ofstream g("out.out");

int main()
{
    f>>t;
    for(int k=1; k<=t; ++k) {
        v1.clear(); v2.clear();
        memset(dp,0,sizeof(dp));
        f>>n;
        for(int i=1; i<=n; ++i) f>>s[i];
        for(int i=1; i<=n; ++i) {
            for(int j=DS-1; j>=0; --j) if(dp[j]) {
                if(!dp[j+s[i]]) {
                    dp[j+s[i]]=1;
                    fol[j+s[i]]=s[i];
                }
            }
            for(int j=0; j<DS; ++j) if(dp[j]) {
                if(!dp[j-s[i]]){
                    dp[j-s[i]]=-1;
                    fol[j-s[i]]=s[i];
                }
            }
            if(!dp[s[i]+VMAX]) {
                dp[s[i]+VMAX]=1;
                fol[s[i]+VMAX]=s[i];
            }
            if(!dp[s[i]+VMAX]) {
                dp[s[i]-VMAX]=-1;
                fol[-s[i]+VMAX]=s[i];
            }
        }
        g<<"Case #"<<k<<": \n";
        if(!dp[VM]) g<<"Impossible";
        else {
            int sc=VM;
            if(dp[VM]>0) {
                v2.push_back(fol[VM]);
                sc-=fol[VM];
            }else {
                v1.push_back(fol[VM]);
                sc+=fol[VM];
            }
            for(;sc!=VM;) {
                if(dp[sc]>0) {
                    v2.push_back(fol[sc]);
                    sc-=fol[sc];
                }else {
                    v1.push_back(fol[sc]);
                    sc+=fol[sc];
                }
            }
            for(int i=0; i<v1.size(); ++i) g<<v1[i]<<' ';
            g<<'\n';
            for(int i=0; i<v2.size(); ++i) g<<v2[i]<<' ';
            g<<'\n';
        }
    }
    return 0;
}
