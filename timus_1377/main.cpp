#include <iostream>
#include <bitset>
#define DN 105
using namespace std;

int n,m,t1x,t2x,t1y,t2y;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bitset<DN> viz[DN];

bool check(int a, int b) {
    return(0<a && 0<b && a<=n && b<=m);
}

int main()
{
    cin>>n>>m>>t1x>>t1y>>t2x>>t2y;
    int d=0,r=0,px=1,py=1,da=0,tfx=-1,tfy=-1;
    for(;px!=tfx || py!=tfy;px+=dx[d],py+=dy[d],r+=da) {
        viz[px][py]=1;
        if(0==da && px==t1x && py==t1y) da=1,tfx=t2x,tfy=t2y;
        if(0==da && px==t2x && py==t2y) da=1,tfx=t1x,tfy=t1y;
      //  cout<<tfx<<' '<<tfy<<":"<<px<<' '<<py<<'\n';
      //  cout.flush();
        if(!check(px+dx[d],py+dy[d]) || viz[px+dx[d]][py+dy[d]]) d=(d+1)%4;
    }
    cout<<r;
    return 0;
}
