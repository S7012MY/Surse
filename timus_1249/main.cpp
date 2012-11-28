#include <cstdio>
#include <bitset>
#define DN 3005
using namespace std;

int n,m,x;
bitset<DN> v[DN];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        scanf("%d",&x);
        v[i][j]=x;
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(0==v[i][j]) {
            if((1==v[i][j-1] && 1==v[i-1][j-1] && 1==v[i-1][j]) ||
               (1==v[i-1][j] && 1==v[i-1][j+1] && 1==v[i][j+1]) ||
               (1==v[i][j+1] && 1==v[i+1][j+1] && 1==v[i+1][j]) ||
               (1==v[i+1][j] && 1==v[i+1][j-1] && 1==v[i][j-1])
            ) {
                printf("No");
                return 0;
            }
        }
    printf("Yes");
    return 0;
}
