#include <cstdio>
#include <vector>
#include <bitset>
#define DN 2005
using namespace std;

typedef vector<short>::iterator it;

bitset<DN> viz;
vector<short> gr[DN],gt[DN];
short n,v[DN],poz[DN],unde[DN],sz,nrc,lst,grad[DN];

void dfs(short s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(0==viz[*i]) dfs(*i);
    v[++sz]=s;
    poz[s]=sz;
}

void dfst(short s) {
    viz[poz[s]]=1;
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i)
        if(0==viz[poz[*i]]) dfst(*i);
    unde[s]=nrc;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        short nr;
        for(;;) {
            scanf("%d",&nr);
            if(0==nr) break;
            gr[i].push_back(nr);
            gt[nr].push_back(i);
        }
    }
    for(int i=1; i<=n; ++i) if(0==viz[i]) dfs(i);
    viz&=0;
    for(int i=n; 0<i; --i) if(0==viz[i]) {
        ++nrc;
        dfst(v[i]);
    }
   // for(int i=1; i<=n; ++i) cout<<unde[i]<<' ';
  //  cout<<'\n';
    for(int i=1; i<=n; ++i)
        for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(unde[i]!=unde[*j]) {
            ++grad[unde[*j]];
            //cout<<unde[i]<<' '<<unde[*j]<<'\n';
        }
    for(int i=1; i<=nrc; ++i) if(0==grad[i]) {
        if(lst) lst=-1;
        else lst=i;
    }
    for(int i=1; i<=n; ++i) if(unde[i]==lst) printf("%d ",i);
    printf("0");
    return 0;
}
