//TODO: aint
#include <cstdio>
#include <fstream>
#include <vector>
#define DN 50001
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[DN];
int n,m,c,fs[DN],lst[DN],ai[4*DN],freq[80],sz,op,x,cc,rq,cnt;
int ai[4*DN],gls,gld,istot;

void dfs(int s,int f) {
    fs[s]=++sz;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f) dfs(*i,s);
    lst[s]=sz;
}

//<parsing>
FILE* fin=fopen("color4.in","r");
const unsigned maxb=8000192;
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
    ofstream g("color4.out");
    n=getInt(); m=getInt(); c=getInt();
    for(int i=1;i<n;++i) {
        int a,b;
        a=getInt(); b=getInt();
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,0);
    ai[1]=1;

    for(int i=0; i<m; ++i) {
        op=getInt();
        if(0==op) {
            x=getInt(); cc=getInt();
            for(int i=fs[x]; i<=lst[x]; ++i) lin[i]=cc;
        }else {
            x=getInt();
            cnt=0;
            for(int i=0; i<=c; ++i) freq[i]=0;
            for(int i=fs[x];i<=lst[x]; ++i) ++freq[lin[i]];
            for(int i=0; i<=c; ++i) if(freq[i]>cnt) {
                rq=i;
                cnt=freq[i];
            }
            g<<rq<<' '<<cnt<<'\n';
            //cout<<rq<<' '<<cnt<<'\n';
        }
    }
    return 0;
}
