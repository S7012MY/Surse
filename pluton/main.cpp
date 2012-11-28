#include <cstdio>
#include <cstring>
#include <algorithm>
#define DN 4005
using namespace std;

char so[DN][11],st[DN][11];
int n;

int main()
{
    freopen("pluton.in","r",stdin);
    freopen("pluton.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%s",so[i]);
        int sz=strlen(so[i]);
        for(int j=0; j<sz; ++j) st[i][j]=so[i][j];
        sort(st,st+sz);
    }
    return 0;
}
