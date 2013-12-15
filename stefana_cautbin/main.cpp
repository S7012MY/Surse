#include <cstdio>
#define  BM  100005

int s[BM],n;
int zero(int a){
    int ls=1,ld=n,m,ma;
    for(;ls<ld;){

        ma=m;
        m=(ls+ld)/2;
        if(ma==m)break;
        if(s[m]<=a) ls=m;
        else ld=m-1;
    }
     for(;s[ld]>a;)--ld;
    if(s[ld]==a)return ld;
    return -1;
}

int unu(int a){
    int ls=1,ld=n,m,ma;
    for(;ls<ld;){

        ma=m;
        m=(ls+ld)/2;
        if(ma==m)break;
        if(s[m]<=a) ls=m;
        else ld=m-1;
    }
    for(;s[ld]>a;)--ld;
    return ld;

}

int doi(int a){
    int ls=1,ld=n,m;
    for(;ls<ld;){
        m=(ls+ld)/2;
        if(s[m]<a)ls=m+1;
        else ld=m;
    }
    if(s[ls]<a)++ls;
    return ls;
}

int main(){
    int i,m,o,a;
    freopen("cautbin.in","r",stdin);
    freopen("cautbin.out","w",stdout);

    scanf("%d",&n);
    for(i=1;i<=n;++i) scanf("%d",&s[i]);
    scanf("%d",&m);
    for(i=1;i<=m;++i){
        //fprintf(stderr,"%d ",i);
        scanf("%d %d",&o,&a);
        if(o==0) printf("%d\n",zero(a));
        else if(o==1) printf("%d\n",unu(a));
        else printf("%d\n",doi(a));

    }
    return 0;
}
