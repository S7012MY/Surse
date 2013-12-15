#include <fstream>
#define MLT 1000000000
using namespace std;

int n,m,sm,bst[2][(1<<18)],st,fin;

int main()
{
    ifstream f("mmo.in");
    ofstream g("mmo.out");
    f>>n>>m;
    sm=(1<<n);
    for(int i=0; i<sm; ++i) bst[0][i]=bst[1][i]=MLT;
    bst[0][sm-1]=0;
    for(int i=0; i<m; ++i) {
      int x,y,z;
      f>>x>>y>>z;
      --x; --y; st+=z;
      for(int j=0; j<sm; ++j) {
        int nxt=j^(1<<x)^(1<<y);
        bst[1][nxt]=min(bst[1][nxt],bst[0][j]);
        bst[1][j]=min(bst[1][j],bst[0][j]+z);
      }
      for(int j=0; j<sm; ++j) bst[0][j]=bst[1][j],bst[1][j]=MLT;
    }
    g<<st-bst[0][sm-1];
    return 0;
}
