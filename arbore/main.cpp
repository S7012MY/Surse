#include <cstdio>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
#define SQ 450
#define DV 200005
using namespace std;

typedef vector<int>::iterator it;

int n,m,eu[DN*2],f[DN],l[DN],v[DN*2],buc[SQ],sz;
char am[SQ][DV];
vector<int> gr[DN];

void dfs(int &s, int &fa) {
    eu[++sz]=s;
    f[s]=sz;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(*i!=fa) dfs(*i,s);
    eu[++sz]=s;
    l[s]=sz;
}

inline void update(int nod,int suma) {
    for(int a=1,b=SQ,ib=0; a<=sz;a=b+1,b+=SQ,++ib) {
        if(f[nod]>b || l[nod]<a) continue;
        if(f[nod]<=a && l[nod]>=b) {
            buc[ib]+=suma;
            continue;
        }
        int lim=min(b,sz);
        for(int i=a; i<=lim; ++i) am[ib][v[i]]=0;
        lim=min(l[nod],b);
        for(int i=max(a,f[nod]);i<=lim; ++i) v[i]+=suma;
        lim=min(b,sz);
        for(int i=a; i<=lim; ++i) am[ib][v[i]]=1;
    }
}

inline int cauta(int a,int b, int vl) {
    for(int i=a; i<=b; ++i) if(v[i]==vl) return eu[i];
    return -1;
}

inline int query(int suma) {
    for(int a=1,b=SQ,ib=0; a<=sz;a=b+1,b+=SQ,++ib) {
        int vl=suma-buc[ib];
        if(vl>=0 && am[ib][vl]) return cauta(a,min(b,sz),vl);
    }
    return -1;
}

//<parsing>
FILE* fin=fopen("arbore.in","r");
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
    ofstream g("arbore.out");
    n=getInt(); m=getInt();
    for(int i=1; i<n; ++i) {
        int a,b;
        a=getInt(); b=getInt();
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int c=1,b=0;
    dfs(c,b);

    for(int i=0; i<m; ++i) {
        int op,a,b;
        op=getInt();
        if(op==1) {
            a=getInt(); b=getInt();
            update(a,b);
        }else {
            a=getInt();
            g<<query(a)<<'\n';
        }
    }
    return 0;
}
