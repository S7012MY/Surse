#include <cstdio>
#include <cstring>
#include <set>
#define DM 200005
#define DN 105
#define DL 5005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

int n,m,lg[DN],lst[DN][DL],lgs;
char c[DN][DL],ops[DM];
set<int> apar[DN][30];

int main(){
    freopen("search.in","r",stdin);
    freopen("search.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=0; i<n; ++i) {
        scanf("%s\n",c[i]);
        lg[i]=strlen(c[i]);
        for(int j=0; j<lg[i]; ++j) apar[i][c[i][j]-'a'].insert(j);
    }
    for(;m;--m) {
        char op;
        scanf("%c\n",&op);
        if(op=='-') --lgs;
        else {
            ++lgs;
            ops[lgs]=op;
        }
        int rq=0;
        for(int i=0; i<n; ++i)
            if(apar[i][ops[lgs]-'a'].lower_bound(lst[i][lgs-1])!=apar[i][ops[lgs]-'a'].end()) {
                ++rq;
                lst[i][lgs]=*apar[i][ops[lgs]-'a'].lower_bound(lst[i][lgs-1])+1;
                //deb(i) deb(lst[i][lgs]) debnl
            }else lst[i][lgs]=DN;
        printf("%d\n",rq);
    }
    return 0;
}
