#include <cstdio>
#include <fstream>
#define DN 262145
using namespace std;

int n,x,lst,pre[DN],nrc,ok=1;

//<parsing>
FILE* fin=fopen("euler.in","r");
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
    ofstream g("euler.out");
    n=getInt();
    int prim;
    prim=getInt();
    pre[prim]=-1;
    lst=prim;
    for(int i=2;i<2*n;++i,lst=x) {
         x=getInt();
         if(!pre[x]) pre[x]=lst;
         else if(pre[lst]!=x) ok=0;
    }
    for(int i=1;i<=n; ++i) if(!pre[x])ok=0;
    pre[prim]=0;
    if(ok) {
        g<<"DA\n";
        for(int i=1; i<=n; ++i) g<<pre[i]<<' ';
    }else g<<"NU\n";
    return 0;
}
