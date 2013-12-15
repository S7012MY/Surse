#include <fstream>
#include <bitset>
using namespace std;

int a[23],m[23][11];
bitset <11>bs;

int valid(int x,int n){
    if(a[x]>n) return 0;
    if(a[x]<=a[x-1]) return 0;
    return 1;
}

int verif(int k,int d){
    bs&=0;
    for(int i=1;i<=k;++i){
        int cc=a[i];
        for(int j=1;j<=m[cc][0];++j){
            bs[m[cc][j]]=1;
        }
    }
    if(bs.count()==d)return 1;
    return 0;
}
int main () {
    int n,k,d,i,pc=1,j,prec;
    ifstream f("pluricex.in");
    ofstream g("pluricex.out");
    f>>n>>k>>d;
    for(i=1;i<=n;++i){
        f>>m[i][0];
        for(j=1;j<=m[i][0];++j) f>>m[i][j];
    }
    for(;pc>0;){
        if(a[pc]) ++a[pc];
        else a[pc]=a[pc-1]+1;
        if(valid(pc,n)){
            if(pc==k&&verif(k,d)){
                for(i=1; i<=k; ++i) g<<a[i]<<' ';
                g<<'\n';
            }
            else if(pc<k) ++pc;
        }
        else
        if(a[pc]>n){
            a[pc]=0;
            --pc;
        }
    }
    return 0;
}
