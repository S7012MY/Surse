#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#define DN 40005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef vector<int>::iterator it;

vector
<int> gr[DN];
int n,m,grad[DN],r[DN],sz;
bitset<DN> viz;

inline bool ct(int &n1, int n2) {
    bool ret=0;
    viz[n1]=1;
    if(n1==n2) return 1;
    for(it i=gr[n1].begin(); i!=gr[n1].end(); ++i) if(!viz[*i]) ret|=ct(*i,n2);
    return ret;
}

inline void dst(int &nod, int d) {
    viz[nod]=1;
    if(d==0) {
        r[++sz]=nod;
        return;
    }
    for(it i=gr[nod].begin(); i!=gr[nod].end(); ++i) if(!viz[*i]) dst(*i,d-1);
}

inline void cap(int &nod) {
    viz[nod]=1;
    if(1==grad[nod]) r[++sz]=nod;
    for(it i=gr[nod].begin(); i!=gr[nod].end(); ++i) if(!viz[*i]) cap(*i);
}

int main()
{
    freopen("drumuri.in","r",stdin);
    freopen("drumuri.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(;m;--m) {
        int op,a,b;
        scanf("%d",&op);
        viz&=0; sz=0;

        if(1==op) {
            scanf("%d %d",&a,&b);
            if(grad[a]>1 || grad[b]>1 || ct(a,b)) {
                printf("0\n");
                continue;
            }
            ++grad[a]; ++grad[b];
            gr[a].push_back(b); gr[b].push_back(a);
            printf("1\n");
        }

        else if(2==op) {
            scanf("%d %d",&a,&b);
            int ok=0;
            for(it i=gr[a].begin(); i!=gr[a].end(); ++i) if(*i==b) {
                gr[a].erase(i),ok=1;
                break;
            }
            for(it i=gr[b].begin(); i!=gr[b].end(); ++i) if(*i==a) {
                gr[b].erase(i),ok=1;
                break;
            }
            printf("%d\n",ok);
            if(ok) --grad[a],--grad[b];
        }

        else if(3==op) {
            scanf("%d %d",&a,&b);
            dst(a,b);
            if(sz==2 && r[1]>r[2]) swap(r[1],r[2]);
            printf("%d ",sz);
            for(int i=1; i<=min(sz,2); ++i) printf("%d ",r[i]);
            printf("\n");
        }

        else {
            scanf("%d",&a);
            cap(a);
            if(0==sz) r[++sz]=a;
            if(sz==2 && r[1]>r[2]) swap(r[1],r[2]);
            printf("%d ",sz);
            for(int i=1; i<=min(sz,2); ++i) printf("%d ",r[i]);
            printf("\n");
            //debnl
        }
        fflush(stdout);
        /*deb(m) debnl
        for(int i=1; i<=n; ++i) {
            deb(i)
            for(it j=gr[i].begin(); j!=gr[i].end(); ++j) deb(*j)
            debnl
        }
        debnl debnl*/
    }
    return 0;
}
