#include <cstdio>
#define LL long long
#define DN 1000005
#define MULT -(1LL<<62)

int n,v;
LL dp[2][3][2],rez;

inline LL max(LL a,LL b) {
    if(a>b)return a;
    return b;
}

//<parsing>
FILE* fin=fopen("max.in","r");
const unsigned maxb=8192;
char buf[maxb];
int l = 0;
unsigned ptr=l;

inline unsigned getInt(){
    unsigned nr=0;
	while(buf[ptr]<'0'||'9'<buf[ptr])
			if(++ptr>=l)
					l=fread(buf,1,maxb,fin),ptr=0;
	while(l && '0'<=buf[ptr]&&buf[ptr]<='9'){
			nr=nr*10+buf[ptr]-'0';
			if(++ptr>=l)
					l=fread(buf,1,maxb,fin),ptr=0;
	}
	return nr;
}
//</parsing>

int main()
{
   // freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    n=getInt();
    dp[0][0][0]=dp[0][1][0]=dp[0][2][0]=dp[1][0][0]=dp[1][1][0]=dp[1][2][0]=MULT;
    for(int i=1; i<=n; ++i) {
        v=getInt();
        int ic=i&1,ip=(i&1)^1;
        for(int s=0; s<2; ++s) for(int md=0; md<3; ++md) {
            dp[s][md][ic]=dp[s][md][ip];
            if(md==0) dp[1][0][ic]=max(dp[1][0][ic],v);
            int semn=1;
            if(!s) semn=-1;
            dp[s][md][ic]=max(dp[s][md][ic],dp[s^1][(md+2)%3][ip]+semn*(md+1LL)*v);

            rez=max(rez,dp[s][md][ic]);
        }
    }
    printf("%lld",rez);
    return 0;
}