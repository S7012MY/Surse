#include <cstdio>
#include <cstring>
#define MOD 4207849484LL
#define DN 1005

int n,m;
long long nrp[DN];
char msg[DN];
int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    scanf("%d",&n);
    for(int k=1; k<=n; ++k) {
        for(int i=0; i<DN; ++i) nrp[i]=0;
        scanf("%d %s",&m,msg+1);
        int lg=strlen(msg+1),ok=0;
        nrp[0]=1;
        for(int i=1; i<=lg; ++i) {
            msg[i]-='0';
          /*  if(i==1){
                if(msg[i]<=m && msg[i]) nrp[i]=1;
                continue;
            }else if(i==2) {
                if(msg[i]+msg[i-1]*10<=m && msg[i-1]) nrp[i]=2;
                else if(msg[i]<=m && msg[i]) nrp[i]=nrp[i-1];
                continue;
            }else if(i==3) {
                if(msg[i]+msg[i-1]*10+msg[i-2]*100<=m && msg[i-2]) nrp[i]=4;
                else if(msg[i]+msg[i-1]*10<=m && msg[i-1]) nrp[i]=nrp[i-1]+nrp[i-2];
                else if(msg[i]<=m && msg[i]) nrp[i]=nrp[i-1];
                continue;
            }*/

            if(msg[i]<=m && msg[i]) nrp[i]=nrp[i-1];
            if(i>1 && msg[i]+msg[i-1]*10<=m && msg[i-1]) nrp[i]+=nrp[i-2];
            if(i>2 &&msg[i]+msg[i-1]*10+msg[i-2]*100<=m && msg[i-2]) nrp[i]+=nrp[i-3];
            nrp[i]%=MOD;
        }
        //for(int i=1; i<=lg; ++i) fprintf(stderr,"%d ",nrp[i]);
        //fprintf(stderr,"\n");
        printf("Case #%d: %lld\n",k,nrp[lg]);
    }
    return 0;
}
