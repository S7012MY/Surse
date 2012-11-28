#include <iostream>
#include <fstream>
#define DN 1005
using namespace std;

int n,m,k,v[DN];

int main()
{
    for(cin>>k; k;--k) {
        cin>>n>>m;
        int rez=0;
        for(int i=1; i<=m; ++i) v[i]=0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                char x='9';
                while(x!='R' && x!='F') cin>>x;
                if(x=='F') ++v[j];
                else v[j]=0;
                //cout<<x<<' ';
                //cout<<v[j]<<' ';
            }
            //cout<<'\n';
            for(int j=1; j<=m; ++j) {
                int mi=999999;
                for(int k=j;k>0; --k) {
                    mi=min(mi,v[k]);
                    rez=max(rez,mi*(j-k+1));
                }
                //cout<<rez<<' ';
            }
        }
        cout<<rez*3<<'\n';
    }
    return 0;
}
