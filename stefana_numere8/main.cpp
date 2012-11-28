#include <cstdio>

int a[11];

int bit(int n,int poz){
    if(n&(1<<poz))return 1;
    return 0;
}
int suma(int n){
    int s=0;
    for(int i=0;i<10;++i)if(bit(n,i))s+=a[i];
    return s;

}
void af(int n,int p){
   if(n==0)return;
   if(n&1)printf("%d ",a[p]);
   af(n>>1,p+1);
}

int main () {
    int s1,s2,smax=0,c=0,i,sum1,sum2,s1f,s2f;
    freopen("numere8.in","r",stdin);
    freopen("numere8.out","w",stdout);

    for(i=0;i<10;++i)scanf("%d",&a[i]);
    for(s1=1;s1<(1<<10);++s1){
        sum1=suma(s1);
        for(s2=s1+1;s2<(1<<10);++s2){
            if((s1&s2)==0 && sum1==suma(s2)){
                c++;
                if(smax<sum1){
                    smax=sum1;
                    s1f=s1;
                    s2f=s2;
                }
            }
        }
    }
    printf("%d %d\n",c,smax);
    af(s1f,0);
    printf ("\n");
    af(s2f,0);
    return 0;

}
