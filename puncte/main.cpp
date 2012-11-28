#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 100005
#define x first
#define y second
#define MULT (1<<30)
#define LL long long
using namespace std;

typedef pair<int,int> per;

int n,m,ind[DN],ox[DN],sz;
per p[DN];

//unde incepe intervalul lui b
int undeIntervB(per A,per B) {
    pair<long long,long long> a=A,b=B;
    if(a.x==b.x) {
        if(a.y<b.y) return MULT;
        return 0;
    }
    LL x=(2*(a.x-b.x)-1+a.x*a.x+a.y*a.y-b.x*b.x-b.y*b.y)/(2LL*(a.x-b.x));
    if(x<0) return 0;
    if(x>MULT) return MULT;
    return x;
}

//<parsing>
FILE* fin=fopen("puncte.in","r");
const unsigned maxb=7000000;
char buf[maxb];
unsigned ptr=0;

inline unsigned getInt(){
    unsigned nr=0;
	while(buf[ptr]<'0'||'9'<buf[ptr]) ++ptr;
	while('0'<=buf[ptr]&&buf[ptr]<='9'){
		nr=nr*10+buf[ptr]-'0';
		++ptr;
	}
	return nr;
}
//</parsing>

int main()
{
    freopen("puncte.out","w",stdout);
    fread(buf,maxb,1,fin),ptr=0;
	n=getInt(); m=getInt();
	for(int i=1; i<=n; ++i)
	    p[i].x=getInt(),p[i].y=getInt();
    ind[++sz]=1;
    ox[++sz]=MULT;
    for(int i=2; i<=n; ++i) {
        int px;
        for(;sz>1 && (px=undeIntervB(p[ind[sz-1]],p[i]))<=ox[sz-1];--sz);
        ind[sz]=i;
        ox[sz]=px; ox[++sz]=MULT;
    }
   // for(int i=1; i<=sz; ++i) cout<<ind[i]<<' ';
    for(int i=1; i<=m; ++i) {
        int a;
        a=getInt();
        int px=upper_bound(ox+1,ox+sz+1,a)-ox-1;
        printf("%lld\n",(p[ind[px]].x-a)*1LL*(p[ind[px]].x-a)+p[ind[px]].y*1LL*p[ind[px]].y);
    }
    return 0;
}
