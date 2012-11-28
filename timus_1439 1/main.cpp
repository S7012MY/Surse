#include <iostream>
using namespace std;

struct ai{
    ai *fs,*fd;
    int sum;
    ai(int lg) {
        sum=lg;
        fs=fd=NULL;
    }
} *t;

int n,m;

int query(int nr,ai *nod=t,int ls=1,int ld=n) {
    //cout<<ls<<' '<<ld<<' '<<nod->sum<<'\n';
    if(ls==ld) return ls;
    int m=(ls+ld)>>1;
    int vst=m-ls+1;
    if(nod!= NULL && nod->fs!=NULL) vst=nod->fs->sum;
    if(nr<=vst) {
        if(nod!=NULL && nod->fs!=NULL) return query(nr,nod->fs,ls,m);
        return query(nr,NULL,ls,m);
    }else {
        nr-=vst;
        if(nod!=NULL && nod->fd!=NULL) return query(nr,nod->fd,m+1,ld);
        return query(nr,NULL,m+1,ld);
    }
}

void update(int p,ai *nod=t,int ls=1,int ld=n) {
    if(ls==ld) {
        nod->sum=0;
        return;
    }
    int m=(ls+ld)>>1;
    int vst=m-ls+1,vdr=ld-m;
    if(p<=m) {
        if(nod->fs==NULL) {
            ai *p=new ai(m-ls+1);
            nod->fs=p;
        }
        update(p,nod->fs,ls,m);
    } else {
        if(nod->fd==NULL) {
            ai *p=new ai(ld-m);
            nod->fd=p;
        }
        update(p,nod->fd,m+1,ld);
    }
    if(nod->fs!=NULL) vst=nod->fs->sum;
    if(nod->fd!=NULL) vdr=nod->fd->sum;
    nod->sum=vst+vdr;
}

int main()
{
    cin>>n>>m;
    t=new ai(n);
    for(int i=1; i<=m; ++i) {
        char op;
        int nr;
        cin>>op>>nr;
        if('L'==op) {
            cout<<query(nr)<<'\n';
        }else {
            update(query(nr));
        }
    }
    return 0;
}
