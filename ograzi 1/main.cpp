#include <fstream>
#include <vector>
#include <cstdio>
#define DN 50005
#define MOD 193939
using namespace std;

typedef vector<int>::iterator it;

int n,m,h,w,x[DN],y[DN],px,py,rez;
vector<int> hs[MOD];

int hash(int a, int b) {
    return (a*97 +b)%MOD;
}

int check(int a, int b) {
    int unde=hash(a,b);
    for(it i=hs[unde].begin(); i!=hs[unde].end(); ++i)
        if(x[*i]<=px && x[*i]+w>=px && y[*i]<=py && y[*i]+h>=py) return 1;
    return 0;
}

//<parsing>
FILE* fin=fopen("ograzi.in","r");
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
    ofstream g("ograzi.out");
    n=getInt();
    m=getInt();
    w=getInt();
    h=getInt();
    for(int i=1; i<=n; ++i) {
        x[i]=getInt();
        y[i]=getInt();
        int a=(x[i]+w-1)/w,b=(y[i]+h-1)/h;
        hs[hash(a,b)].push_back(i);
    }
    for(int i=1; i<=m; ++i) {
        px=getInt();
        py=getInt();
        int a=(px+w-1)/w, b=(py+h-1)/h;
        rez+=(check(a,b)|check(a,b-1)|check(a-1,b)|check(a-1,b-1));
    }
    g<<rez;
    return 0;
}
