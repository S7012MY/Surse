#include <iostream>
#define zeros(x) (((x)^(x-1))&(x))
using namespace std;

int n,aib[200][200][200];

void update(int x,int y, int z,int v) {
    for(int i=x; i<=n; i+=zeros(i)) for(int j=y; j<=n; j+=zeros(j)) for(int k=z; k<=n; k+=zeros(k))
        aib[i][j][k]+=v;
}

int sum(int x,int y, int z) {
    int r=0;
    for(int i=x;0<i;i-=zeros(i)) for(int j=y;0<j;j-=zeros(j)) for(int k=z;0<k;k-=zeros(k)) r+=aib[i][j][k];
    return r;
}

int main()
{
    cin>>n;
    int op;
    int x1,y1,z1,x2,y2,z2,vl;
    for(cin>>op;op!=3;cin>>op) {
        if(1==op) {
            cin>>x1>>y1>>z1>>vl;
            ++x1,++y1,++z1;
            update(x1,y1,z1,vl);
        }else {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            ++x1,++y1,++z1;++x2,++y2,++z2;
            cout<<sum(x2,y2,z2)-
            sum(x1-1,y2,z2)-
            sum(x2,y1-1,z2)-
            sum(x2,y2,z1-1)+
            sum(x1-1,y1-1,z2)+
            sum(x1-1,y2,z1-1)+
            sum(x2,y1-1,z1-1)-
            sum(x1-1,y1-1,z1-1)
                <<'\n';
        }
    }
    return 0;
}
