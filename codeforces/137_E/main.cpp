/* cacat*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cctype>
#define LL long long
#define DIM 100
#define REST 1000000007
#define MOD REST
#define DN 100
using namespace std;

long long n,m,k;
LL aux[DN][DN],c[DN][DN],mi[DN][DN],rez[DN][DN];

void inm(LL a[DN][DN],LL b[DN][DN],LL r[DN][DN]) {
    for(int i=0; i<m; ++i) for(int j=0; j<m; ++j) {
        LL c=0;
        for(int k=0; k<m; ++k) c=(c+1LL*a[i][k]*b[k][j])%MOD;
        r[i][j]=c;
    }
}
/*cacat*/

void lgput(LL e) {
    memset(rez,0,sizeof(rez));
    memcpy(c,mi,sizeof(c));
    for(int i=0; i<m; ++i) rez[i][i]=1;
    for(long long i=0; (1LL<<i)<=e; ++i) {
        if((1LL<<i)&e) {
            inm(rez,c,aux);
            memcpy(rez,aux,sizeof(rez));
        }
        inm(c,c,aux);
        memcpy(c,aux,sizeof(aux));
    }
}


int main()
{
	long long n,i,pd;
	cin>>n>>m>>k;
	for(int i=0;i<m; ++i) for(int j=0; j<m; ++j) mi[i][j]=1;
	for(int i=0; i<k; ++i) {
	    char a,b;
	    cin>>a>>b;
	    int x=a-'a',y=b-'a';
	    if(isupper(a)) x=a-'A'+26;
	    if(isupper(b)) y=b-'A'+26;
	    mi[y][x]=0;
	}


    LL ra=0;
	lgput(n-1);
	for(int i=0;i<m; ++i) {
	    for(int j=0; j<m; ++j) {
	        ra+=rez[i][j];
	        if(ra>=MOD) ra-=MOD;
	    }
	}
	cout<<ra;
	return 0;
}
