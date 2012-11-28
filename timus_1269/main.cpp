#include <cstdio>
#include <cstring>
#include <vector>
#define DL 10005
#define DA 26
using namespace std;

char c[DL],z;
int n;

struct ac {
    int n0;
    ac *fail,*f[DA];
    ac() {
        n0=0;
        fail=NULL;
        memset(f,0,sizeof(f));
    }
};

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    return 0;
}
