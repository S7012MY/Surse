#include <cstdio>
#include <cstring>
#define DL 600005

char biti[DL],rez[DL];
int gres[DL],sz,ok=1,sr;

int check(int p) {
    char r=0,nrb=0;
    for(int i=p+1; i<p+8; ++i) {
        r<<=1;
        r+=biti[i]-'0';
        nrb+=biti[i]-'0';
    }
    if(nrb%2==biti[p]-'0') {
        rez[sr++]=r;
        return 1;
    }
    return 0;
}

int main()
{
    freopen("paritate.in","r",stdin);
    freopen("paritate.out","w",stdout);
    scanf("%s",biti);
    int lg=strlen(biti);
    for(int i=0;i*8<lg;++i) {
        if(!check(8*i)) {
            ok=0;
            gres[++sz]=i;
        }
    }
    if(ok) printf("DA\n%s",rez);
    else {
        printf("NU\n");
        for(int i=1; i<=sz; ++i) printf("%d ",gres[i]);
    }
    return 0;
}
