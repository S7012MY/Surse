#include <iostream>
#include <bitset>
using namespace std;

int m[2][2],r1,r2,c1,c2,d1,d2;
bitset<10>fol;

int main()
{
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    for(int i=1; i<10; ++i) {
        fol&=0;
        m[0][0]=i;
        fol[i]=1;
        if(d1-i>9 || d1-i<1 || fol[d1-i]) continue;
        m[1][1]=d1-i;
        fol[d1-i]=1;
        if(r2-m[1][1]>9 || r2-m[1][1]<1 || fol[r2-m[1][1]]) continue;
        m[1][0]=r2-m[1][1];
        fol[r2-m[1][1]]=1;
        if(c2-m[1][1]>9 || c2-m[1][1]<1 || fol[c2-m[1][1]]) continue;
        m[0][1]=c2-m[1][1];
        if(m[0][0]+m[1][1]==d1 && m[0][1]+m[1][0]==d2 &&
           m[0][0]+m[1][0]==c1 && m[0][1]+m[1][1]==c2 &&
           m[0][0]+m[0][1]==r1 && m[1][0]+m[1][1]==r2) {
               cout<<m[0][0]<<' '<<m[0][1]<<'\n'<<m[1][0]<<' '<<m[1][1];
               return 0;
           }

    }
    cout<<"-1";
    return 0;
}
