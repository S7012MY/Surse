#include <cstdio>
#include <bitset>
using namespace std;
bitset <121> a[100005];
int st[100005],vf;
int mpb(bitset <121>&a,bitset<121>b){
    bitset <121> c=a&b;
    if (c.any()){
        a|=b;
        return 1;
    }
    return 0;
}
int main () {
    int n,i,j,m,el,c=0,k;
    freopen("liste.in","r",stdin);
    freopen("liste.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&m);
        for(j=1;j<=m;++j){
            scanf("%d",&el);
            a[i][el]=1;
        }

    }
    for(i=1;i<=n;++i){

       for(;vf>0&&mpb(a[i],a[st[vf]]);--vf);
        st[++vf]=i;
     }

    printf("%d",vf);
    return 0;
}
