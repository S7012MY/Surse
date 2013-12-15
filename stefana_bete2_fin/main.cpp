#include <cstdio>
#define BM 3005
#include <algorithm>
using namespace std;
int a[BM];

int cb(int el,int i){
    int m,ma,ls=1,ld=i;
    for(;ls<ld;){
        //ma=m;
        m=(ls+ld)/2;

        //if(ma==m)break;
        if(a[m]>=el) ld=m;
        else ls=m+1;
    }
    //fprintf(stderr,"%d ",ls);
    if(a[ls]==el)return 1;
    return 0;


}
int main () {
    int i,j,n,d,c=0;
    freopen("bete2.in","r",stdin);
    freopen("bete2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=3;i<=n;++i){
        for(j=i-1;j;--j){

            d=a[i]-a[j];
            if(cb(d,i-1)&&a[j]!=d){
                //printf("%d %d %d\n",a[i],a[j],d);
                ++c;
            }

        }
    }
    printf("%d",c/2);
}



