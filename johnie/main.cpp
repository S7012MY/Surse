#include <fstream>
#include <vector>
#include <cmath>
#define DN 200005
#define ins push_back
using namespace std;

typedef vector<int>::iterator it;

int n,m,st[DN],sz,con,viz[DN],d[DN],ss;
vector<int> gr[DN];

void dfs(int s) {
    viz[s]=1;
    d[++ss]=s;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
}

//<parsing>
FILE* fin=fopen("johnie.in","r");
const unsigned maxb=7000000;
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
	ofstream g("johnie.out");
    n=getInt(); m=getInt();
	for(int i=0; i<m; ++i) {
	    int a,b;
	    a=getInt(); b=getInt();
	    gr[a].ins(b); gr[b].ins(a);
	}
	int nf=n,cpar=0,ci=0;
	for(int i=1; i<=n; ++i) if(!viz[i] && gr[i].size()) {
        dfs(i);
        int ok=1;
        ++nf;
        viz[nf]=1;
        for(int j=1; j<=ss; ++j) if(gr[d[j]].size()&1) {
            ++ci;
            ok=0;
            gr[d[j]].ins(nf);
            gr[nf].ins(d[j]);
        }
        if(ok) {
            ++cpar;
            gr[nf].ins(d[1]);
            gr[nf].ins(d[1]);
            gr[d[1]].ins(nf);
            gr[d[1]].ins(nf);
        }
        ss=0;
    }
	g<<ceil(ci/2.0)+cpar<<'\n';
	for(int i=n+1; i<=nf; ++i)
	for(st[++sz]=i;sz;) {
	    int fr=st[sz];
	    if(gr[fr].size()==0) {
	        if(fr>n) {
	            if(ss){
	                g<<ss<<' ';
                    for(int i=1; i<=ss; ++i) g<<d[i]<<' ';
                    ss=0;
                    g<<'\n';
	            }
	        }else d[++ss]=fr;
	        --sz;
	        continue;
	    }
	    int x=gr[fr].back();
	    gr[fr].pop_back();
	    for(it i=gr[x].begin(); i!=gr[x].end(); ++i) if(*i==fr) {
	        gr[x].erase(i);
	        break;
	    }
	    st[++sz]=x;
	}
    return 0;
}
