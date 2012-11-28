#include <iostream>
#define x "Crosses win"
#define o "Ouths win"
#define d "Draw"
using namespace std;

char t[3][3];
int n[3][3],f[3],sx,sy;

int main()
{
    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) {
        cin>>t[i][j];
        if('X'==t[i][j]) n[i][j]=1;
        else if('O'==t[i][j]) n[i][j]=2;
    }
    for(int i=0; i<3; ++i) {
        f[0]=f[1]=f[2]=0;
        for(int j=0; j<3; ++j) ++ f[n[i][j]];
        if(1<f[1] && 1>f[2]) ++sx;
        if(1>f[1] && 1<f[2]) ++sy;
    }
    for(int j=0; j<3; ++j) {
        f[0]=f[1]=f[2]=0;
        for(int i=0; i<3; ++i) ++ f[n[i][j]];
        if(1<f[1] && 1>f[2]) ++sx;
        if(1>f[1] && 1<f[2]) ++sy;
    }
    f[0]=f[1]=f[2]=0;
    for(int i=0; i<3; ++i) ++f[n[i][i]];
    if(1<f[1] && 1>f[2]) ++sx;
    if(1>f[1] && 1<f[2]) ++sy;

    f[0]=f[1]=f[2]=0;
    for(int i=0; i<3; ++i) ++f[n[i][2-i]];
    if(1<f[1] && 1>f[2]) ++sx;
    if(1>f[1] && 1<f[2]) ++sy;
    cerr<<sx<<" "<<sy<<'\n';
    //if(0==sx && sx==sy) cout<<d;
    if(sx>sy) cout<<x;
    else if(sy>sx+1) cout<<o;
    else cout<<d;
    return 0;
}
