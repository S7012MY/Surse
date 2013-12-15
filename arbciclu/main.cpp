#include <fstream>
#include <tr1/unordered_set>
#include <bitset>
#include <string>
#define DN 100005
using namespace std;
using namespace tr1;

typedef unordered_set<int>::iterator it;
unordered_set<int> gr[DN];
bitset<DN> inc;
string out;
int n,m,d[DN],c[DN];

int main()
{
    ifstream f("arbciclu.in");
    ofstream g("arbciclu.out");
    int t,i,a,b,cont,iinc,sfc,v[3];
    for(f>>t; t; --t) {
        for(i=1; i<=n; ++i) gr[i].clear(),d[i]=0;
        f>>n>>m;
        inc&=0;
        for(i=1; i<=m; ++i) {
            f>>a>>b;
            gr[a].insert(b);
            gr[b].insert(a);
            ++d[a]; ++d[b];
        }
        iinc=sfc=cont=0;
        for(i=1; i<=n; ++i)
            if(2==d[i]) c[sfc++]=i,inc[i]=1;
            else if(d[i]<2) cont=-1;
        for(;iinc<sfc && 0<=cont; ++iinc) {
            int fr=c[iinc],k=0;
            if(2>d[fr]) break;
            for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) v[++k]=*i;
            for(i=1; 2>=i; ++i) {
                gr[v[i]].erase(fr);
                --d[v[i]];
            }
            it iR=gr[v[1]].find(v[2]);
            if(iR==gr[v[1]].end()) {//nu ex muchie
                gr[v[1]].insert(v[2]);
                gr[v[2]].insert(v[1]);
                ++d[v[1]];
                ++d[v[2]];
            }
            for(i=1; 2>=i; ++i) if(2==d[v[i]] && 0==inc[v[i]]) {
                c[sfc++]=v[i];
                inc[v[i]]=1;
            }
            d[fr]=-1;
            ++cont;
        }
        if(cont==n-2 && 3<=n && m>=n) out+="YES\n";
        else out+="NO\n";
    }
    g<<out;
    return 0;
}
