#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#define DN 705
#define MOD 30103
#define x first
#define y second.first
#define z second.second
using namespace std;

//d[i][j]=1 + sigma(d[k][l]), k = i + 1 ... j - 2, l = k + 1 ... j - 1, V[i] + V[j] > V[k] + V[l]
//SOL = d[i][j], i = 1 .. n - 1, j = i + 1, n
//eu vreau sa tin aib pe poz i,j cu v[i]+v[j] S, s fixat
typedef pair<int, pair<int, int> > per;
int n,v[DN],d[DN][DN],aib[DN][DN],s;
per a[250005];

static inline int lsb(int a) {
    return (((a)^(a-1))&(a));
}

static void update(int a, int b,int v) {
    for(int i=a; i<=n; i+=lsb(i)) for(int j=b; j<=n; j+=lsb(j)) {
        aib[i][j]+=v;
        if(aib[i][j]>MOD) aib[i][j]-=MOD;
    }
}

static int query(int a, int b) {
    int r=0;
    for(int i=a; 0<i; i-=lsb(i)) for(int j=b; 0<j; j-=lsb(j)) {
        r+=aib[i][j];
        if(r>MOD) r-=MOD;
    }
    return r;
}

int main()
{
    ifstream f("evantai.in");
    ofstream g("evantai.out");
    cin>>n;
    for(int i=1; i<=n; ++i)cin>>v[i];
    int sz=0;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) a[++sz]=make_pair(v[i]+v[j],make_pair(i,j));
    sort(a+1,a+sz+1);
    for(int in=1; in<=sz; ++in) {
        int i=a[in].y,j=a[in].z;
        int rq=query(j-1,j-1)-query(j-1,i)-query(i,j-1)+query(i,i)+1;
        if(rq<0) rq+=MOD;
        update(i,j,rq);
        d[i][j]=rq;
    }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) {
        s+=d[i][j];
        if(s>=MOD) s-=MOD;
    }
    g<<s;
    return 0;
}
