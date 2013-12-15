#include <cstdio>
#define DN 200005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,r,tu,ord[DN],sf[2*DN],poz[2*DN],nxt[2*DN],tintac;
int arcasi[2][100005];

int find(int n) {
    if(nxt[n]==n) return n;
    nxt[n]=find(nxt[n]);
    return nxt[n];
}

int bruteFind(int poz) {
    int i=poz;
    for(;sf[i];) {
        i=i-1;
        if(0==i) i=n;
    }
    return i;
}

bool check(int p) {
    bool ok=0;
    for(int i=1;i<=2*n;++i) {
        if((i+1)/2==p && !ok){
            poz[tu]=(i+1)/2;
            ok=1;
        }else {
            if(ok==0) poz[ord[i]]=(i+1)/2;
            else poz[ord[i-1]]=(i+1)/2;
        }
        sf[i]=0;nxt[i]=i;
    }
    sf[1]=1; nxt[1]=n;
     //deb(p) debnl
    for(int i=2*n; i>tu; --i) {
        int indi=find(nxt[poz[i]]);
       //int indi=bruteFind(poz[i]);
        sf[indi]=1;
        nxt[indi]=find(nxt[indi-1]);
       // deb(i) deb(nxt[i]) debnl
        //for(int j=1; j<=n; ++j) deb(nxt[j]);
       // debnl
    }
   // deb(nxt[poz[tu]]) debnl debnl
    if(find(nxt[poz[tu]])==tintac) return 1;
    //if(bruteFind(poz[tu])==tintac) return 1;
    return 0;
}

int tinta(int n,int el){
        int i;
        for(i=1;i<=n;++i)if(arcasi[0][i]==el||arcasi[1][i]==el)return i;
}

int main (){

    int poz,ok=0,j,t,aux,tintaf,pozf;
    freopen("arcas.in","r",stdin);
    freopen("arcas.out","w",stdout);
    scanf("%d %d",&n,&r);
    tintaf=n;
    scanf("%d",&tu);
    for(int i=1;i<=2*n-1;++i)scanf("%d",&ord[i]);
    if(tu==1){
        printf("%d",n);
        return 0;
    }
    if(tu==2*n) {
        printf("2");
        return 0;
    }
    if(tu>n+1){
        int i;
        for(i=3;ord[i]>tu;)i+=2;
        tintac=(i+1)/2;
        for(;tintac<=n; ++tintac) if(check(tintac)) {
            int ls=tintac,ld=n,m,sol=tintac;
            //deb(tintac);
            for(;ls<ld;) {
                m=(ls+ld)>>1;
                if(check(m)) {
                    sol=m;
                    ls=m+1;
                }else ld=m-1;
            }
            for(;check(sol) && sol<=n;++sol);
            //deb(sol-1)
            printf("%d",sol-1);
            return 0;
        }
    }else {
        int i;
        r%=n;
        for(poz=1;poz<=n;++poz){
                //printf("pt inceput din %d\n",poz);
                ok=0;
                for(i=1;i<=2*n;++i){
                        if((i+1)/2==poz && !ok){
                                arcasi[(i+1)%2][(i+1)/2]=tu;
                                ok=1;
                        }
                        else {
                                if(ok==0)arcasi[(i+1)%2][(i+1)/2]=ord[i];
                                else arcasi[(i+1)%2][(i+1)/2]=ord[i-1];
                        }
                }

                for(i=1;i<=2*n+r;++i){
                        if(arcasi[0][1]<arcasi[1][1])t=arcasi[1][1];
                        else t=arcasi[0][1];
                        for(j=n;j>1;--j){
                                if(arcasi[0][j]<arcasi[1][j]){
                                        aux=arcasi[0][j];
                                        arcasi[0][j]=t;
                                        t=aux;
                                }
                                else{
                                        aux=arcasi[1][j];
                                        arcasi[1][j]=t;
                                        t=aux;
                                }
                        }
                        if(arcasi[0][1]<arcasi[1][1])arcasi[1][1]=t;
                        else arcasi[0][1]=t;
                        //printf("dupa runda %d\n",i);
                        //for(int k=1;k<=n;++k)printf("%d %d\n",arcasi[0][k],arcasi[1][k]);

                }
                tintac=tinta(n,tu);
                if(tintac<=tintaf){
                        pozf=poz;
                        tintaf=tintac;
                }
        }
        printf("%d",pozf);
    }
    return 0;
}
