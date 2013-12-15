#include <iostream>
using namespace std;

int n,m,v[5000]={99999},nrs;

void back(int poz,int nr) {
    //cout<<poz<<' '<<nr<<":\n";
    if(nr>m) return;
    if(poz==n+1 && nr==m) {
        ++nrs;
        //for(int i=1; i<=n; ++i) cout<<v[i]<<' ';
        //cout<<endl;
        return;
    }
    if(poz>n) return;
    for(int i=min(v[poz-1],m-nr); i>=0; --i) {
        v[poz]=i;
       // cout<<poz<<' '<<i<<'\n';
        back(poz+1,i+nr);
    }
}

int main()
{
    /*n=2,m=6;
    back(1,0);
    cout<<nrs;*/
    for(n=1; n<=20; ++n) {
        for(m=1; m<=20; ++m) {
            nrs=0;
            back(1,0);
            cout<<nrs<<' ';
        }
        cout<<" \n";
    }
    return 0;
}
