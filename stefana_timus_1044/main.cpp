#include <cstdio>
int f[1000000];
int main(){
    int n,i,s,p=1,ci,rez=0,smax=0;
    scanf("%d",&n);
    for(i=1;i<=n/2;++i){
        p*=10;
    }
    for(i=0;i<p;++i){
        s=0;
        ci=i;
        for(;ci!=0;){
            s+=ci%10;
            ci/=10;
        }
        ++f[s];
        if(smax<s)smax=s;
    }
    //printf("%d",p);
    //for(i=1;i<=9;++i)printf("%d ",f[i]);
    for(i=0;i<=smax;++i){
        rez+=f[i]*f[i];
    }
    printf("%d",rez);
    return 0;
}
