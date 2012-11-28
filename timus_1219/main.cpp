#include <iostream>
#include <cstdlib>
#include <string>
#define L 1000000
using namespace std;

int d,fol[3][30],ca;
string a="abc",rez;

void bk(int k) {
    if(k==3) {
        if(d+3>L) {
            for(int i=0;d<L;++d,++i) rez+=a[i];
            cout<<rez;
            exit(0);
        }
        for(int i=0; i<3; ++i) if('a'==a[i]) ++ca;
       // cout<<a;//cout.flush();
       rez.append(a);
        d+=3;
        return;
    }
    for(char i='a';i<='z';++i) if(0==fol[k][i-'a']) {
        fol[k][i-'a']=1;
        a[k]=i;
        bk(k+1);
        fol[k][i-'a']=0;
    }
}

int main()
{
    for(;d+3<=L;bk(0));
    //for(int i=1; i<=rez.size(); ++i);
    //for(;d<=L;++d) cout<<"z";
    return 0;
}
