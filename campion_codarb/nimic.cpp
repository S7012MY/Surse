#include <cstdio>
#include <cstring>
#include <algorithm>
#define DL 10005
using namespace std;

struct ab {
    char inf;
    ab *fs,*fd,*pre;
    ab() {
        fs=fd=pre=NULL;
    }
} *t,*rn,*rn2;

char sir[DL],arb[DL];
int lg,p;

void mrsd(ab *r) {
    int pi=p;
    r->inf=arb[p]+'A';
    if(arb[pi]&1) {
        r->fs=new ab;
        ++p;
        mrsd(r->fs);
    }
    if(arb[pi]%4>1) {
        r->fd=new ab;
        ++p;
        mrsd(r->fd);
    }
}

void msrd() {
   // for(int i=0; i<lg; ++i)
        //if()
}

void msdr(ab *r) {
    int pi=p;
    r->inf=arb[p]+'A';
    if(arb[pi]%4>1) {
        r->fd=new ab;
        ++p;
        msdr(r->fd);
    }
    if(arb[pi]&1) {
        r->fs=new ab;
        ++p;
        msdr(r->fs);
    }
}

void rsd(ab *r) {
    printf("%c",r->inf);
    if(r->fs!=NULL) rsd(r->fs);
    if(r->fd!=NULL) rsd(r->fd);
}

void srd(ab *r) {
    if(r->fs!=NULL) srd(r->fs);
    printf("%c",r->inf);
    if(r->fd!=NULL) srd(r->fd);
}

void sdr(ab *r) {
    if(r->fs!=NULL) sdr(r->fs);
    if(r->fd!=NULL) sdr(r->fd);
    printf("%c",r->inf);
}

int main()
{http://infoarena.ro/
    freopen("codarb.in","r",stdin);
    freopen("codarb.out","w",stdout);
    scanf("%s",sir);
    lg=strlen(sir);
    for(int i=3; i<lg; ++i) arb[i-3]=sir[i]-'A';
    lg=strlen(arb);
    t=new ab;
    if('R'==sir[0]) {
        mrsd(t);
    }else if('S'==sir[0]) {
        if('R'==sir[1]) {
            msrd();
        }
        else {
            reverse(arb,arb+lg);
            msdr(t);
        }
    }
    printf("RSD");
    rsd(t);
    printf("\nSRD");
    srd(t);
    printf("\nSDR");
    sdr(t);
    return 0;
}
