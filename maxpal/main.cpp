#include <fstream>
#define DN 2005
#define MOD 666013
using namespace std;

int n,v[DN],nr[DN][DN];
short lgm[DN][DN];

inline short ml(short a,short b) {
    if(lgm[a][b]) return lgm[a][b];
    if(a==b) return lgm[a][b]=1;
    if(a+1==b) {
        lgm[a][b]=1;
        if(v[a]==v[b]) ++lgm[a][b];
    }
    else if(v[a]==v[b]) {
        lgm[a][b]=2+ml(a+1,b-1);
        return lgm[a][b];
    }
    else lgm[a][b]=max(ml(a+1,b),ml(a,b-1));
    return lgm[a][b];
}

inline int memo(short a,short b) {
    if(nr[a][b]) return nr[a][b];
    if(a==b) return nr[a][b]=1;
    else if(a+1==b) {
        nr[a][b]=2;
        if(v[a]==v[b]) --nr[a][b];
        return nr[a][b];
    }
    nr[a][b]=0;
    if(v[a]==v[b]) nr[a][b]=memo(a+1,b-1);
    if(ml(a,b)==ml(a+1,b)) nr[a][b]+=memo(a+1,b);
    if(ml(a,b)==ml(a,b-1)) nr[a][b]+=memo(a,b-1);
    if(ml(a,b)==ml(a+1,b-1)) nr[a][b]-=memo(a+1,b-1);
    nr[a][b]=(nr[a][b]+MOD)%MOD;
    return nr[a][b];

}

int main()
{
    ifstream f("maxpal.in");
	ofstream g("maxpal.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
	    f>>v[i];
	    //for(int j=1; j<=n; ++j) lgm[i][j]=nr[i][j]=-1;
	}
	g<<ml(1,n)<<' '<<memo(1,n);
    return 0;
}
