//Normalizare + 2 caractere
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define DN 10005
#define BASE 10000
#define x first
#define y second
using namespace std;

typedef int huge[DN];

int n,m,k;
string cc,cnou,s[DN];
pair<int,pair<char,char> > fin[DN];
huge rez,nrf;

void inmul(huge a, int x){
    int rest = 0;
    int i;
    for(i=1; i<=a[0]||rest; i++,rest=rest/BASE){
        a[i] = (rest+=a[i]*x) % BASE;
    }
    a[0] = i-1;
}

void Add(huge A, huge B) {
        int i,T=0;

        if (B[0]>A[0]) {
                for (i=A[0]+1;i<=B[0];) A[i++]=0;
                A[0]=B[0];
        }
    else for (i=B[0]+1;i<=A[0];) B[i++]=0;
        for (i=1;i<=A[0];i++) {
                A[i]+=B[i]+T;
                T=A[i]/BASE;
                A[i]%=BASE;
    }
        if (T) A[++A[0]]=T;
}

int main()
{
    ifstream f("lexic.in");
    freopen("lexic.out","w",stdout);
    f>>n>>m>>k;
    int N=0;
    for(int i=0; i<=k; ++i) s[0]+='-';
    for(int i=1; i<=n; ++i) {
        f>>cc;
        cnou.clear();
        if(cc.size()<k) continue;
        for(int i=0; i<k; ++i) cnou+=cc[i];
        for(int i=cc.size()-1; i>=(int)cc.size()-k; --i) cnou+=cc[i];
        if(cc.size()>k) {
            cnou+=cc[k];
            cnou+=cc[cc.size()-k-1];
        }
        s[++N]=cnou;
    }
    n=N;
    sort(s+1,s+n+1);
    for(int i=1; i<=n; ++i) {
        fin[i].x=fin[i-1].x;
        string s1,s2;
        for(int j=0; j<2*k; ++j) s1+=s[i][j],s2+=s[i-1][j];
        if(s1.compare(s2)) ++fin[i].x;

        if(s[i].size()>2*k) {
            fin[i].y.x=s[i][s[i].size()-2];
            fin[i].y.y=s[i][s[i].size()-1];
        }else fin[i].y.x=fin[i].y.y=-1;
    }
    nrf[0]=nrf[1]=1;
    int dim=0,nrg=1;//cate am in fiecare familie si cate am gresite
    for(int i=2; i<=n; ++i) {
        if(fin[i].x!=fin[i-1].x) {
            inmul(nrf,nrg);
            if(dim) Add(rez,nrf);
            dim=0; nrf[0]=nrf[1]=nrg=1;
            continue;
        }
        if(fin[i].y.x==-1 || fin[i-1].y.x==-1 || fin[i].y.x!=fin[i-1].y.x || fin[i].y.y!=fin[i-1].y.y) {
               ++dim;
               inmul(nrf,nrg);
               nrg=1;
        } else ++nrg;
    }
    if(dim) {
        inmul(nrf,nrg);
        Add(rez,nrf);
    }
    printf("%d", rez[rez[0]]);
    for(int i=rez[0]-1; i>0; i--){
        printf("%04d", rez[i]);
    }
    return 0;
}