#include <cstdio>
#define DN 501

int n,k,tp,bst[DN][DN],nr[DN];

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

//<parsing>
FILE* fin=fopen("caibicol.in","r");
const unsigned maxb=8192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
	while(buf[ptr]<'0'||'9'<buf[ptr])
		if(++ptr>=maxb)
			fread(buf,maxb,1,fin),ptr=0;
	while('0'<=buf[ptr]&&buf[ptr]<='9'){
		nr=nr*10+buf[ptr]-'0';
		if(++ptr>=maxb)
			fread(buf,maxb,1,fin),ptr=0;
	}
	return nr;
}
//</parsing>

int main()
{
  //  freopen("caibicol.in","r",stdin);
    freopen("caibicol.out","w",stdout);
    n=getInt();
    k=getInt();
    //scanf("%d %d",&n,&k);
    int nrz=0,nru=0;
    for(int i=1; i<=n; ++i) {
        //scanf("%d",&tp);
        tp=getInt();
        if(tp) ++nru,++nr[i];
        else ++nrz;
        nr[i]+=nr[i-1];
        bst[i][1]=nru*nrz;
    }
    for(int i=1; i<=n; ++i)
        for(int j=2; j<=k; ++j) {
            bst[i][j]=999999;
            for(int l=j-1; l<i; ++l) {//bag caii din intervalul [l,i] intr-un grajd nou
                nru=nr[i]-nr[l];
                nrz=i-l-nru;
                bst[i][j]=min(bst[i][j],bst[l][j-1]+nru*nrz);
            }
        }
    printf("%d",bst[n][k]);
    return 0;
}
