#include <iostream>
#include <cstring>
#define B '*'
#define W '.'
#define DN 650
#define DK 9
#define DR (1<<4)
using namespace std;

const int dx[]={0,1,0,1};
const int dy[]={0,0,1,1};
int n,m,rez,l2;
char mt;
short isFractal[DK][DR][DN][DN];
bool isBlack[DN][DN][DK];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        cin>>mt;
        if(B==mt) isBlack[i][j][0]=1;
        else for(int k=0; k<16; ++k) isFractal[0][k][i][j]=1;
    }
    for(int l=0; l<8; ++l)
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
            int ji=i+(1<<l),jj=j+(1<<l);
            isBlack[i][j][l+1]=isBlack[i][j][l]&isBlack[i][jj][l]&isBlack[ji][j][l]&isBlack[ji][jj][l];
            for(int md=0; md<16; ++md) {
                int ok[4]={0,0,0,0};
                for(int b=0; b<4; ++b)
                    if(md&(1<<b)) ok[b]=isFractal[l][md][i+dx[b]*(1<<l)][j+dy[b]*(1<<l)];
                    else ok[b]=isBlack[i+dx[b]*(1<<l)][j+dy[b]*(1<<l)][l];
                isFractal[l+1][md][i][j]=ok[0]&ok[1]&ok[2]&ok[3];
                rez+=(isFractal[l+1][md][i][j]==1 && l);
            }
    }
    cout<<rez;
    return 0;
}
