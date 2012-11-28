#include <cstdio>
#include <cstdlib>
#define DN 1005

int n,m[2][DN];
char drm[2*DN],viz[DN][DN];

inline bool back(int x, int y, int sum, int ix,int iy) {
    if(abs(sum+m[x][y])>1||y>n || viz[ix][iy]) return 0;
    viz[ix][iy]=1;
    drm[ix+iy]=x+1+'0';
    sum+=m[x][y];
    if(ix+iy==n+n) {
        printf("%s",drm+1);
        return 1;
    }
    if(x==0)
        return back(x,y+1,sum,y+1,iy) || back(x^1,iy+1,sum,ix,iy+1);
    else
        return back(x,y+1,sum,ix,y+1) || back(x^1,ix+1,sum,ix+1,iy);
}

int main()
{
    scanf("%d\n",&n);
    char cc;
    for(int i=1; i<=n; ++i) {
        scanf("%c",&cc);
        if(cc=='0') m[0][i]=-1;
        else m[0][i]=1;
    }
    scanf("\n");
    for(int i=1; i<=n; ++i) {
        scanf("%c",&cc);
        if(cc=='0') m[1][i]=-1;
        else m[1][i]=1;
    }
    if(!back(0,1,0,1,0) && !back(1,1,0,0,1)) printf("Impossible");
}
