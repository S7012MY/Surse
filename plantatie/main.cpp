#include <iostream>
#include <fstream>
#define DN 505
using namespace std;

int n,m,rmq[10][DN][DN],log[DN];

int main()
{
    ifstream f("plantatie.in");
	ofstream g("plantatie.out");
	f>>n>>m;
	for(int i=0; i<n; ++i) {
	    if(i>1) log[i]=1+log[i/2];
	    for(int j=0; j<n; ++j) f>>rmq[0][i][j];
	}
	log[n]=log[n/2]+1;
    for(int k=1; k<=log[n]; ++k)
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
            rmq[k][i][j]=rmq[k-1][i][j];
            int ok1=0,ok2=0;
            if((i+(1<<(k-1)))<n) rmq[k][i][j]=max(rmq[k][i][j],rmq[k-1][i+(1<<(k-1))][j]),ok1=1;
            if((j+(1<<(k-1)))<n) rmq[k][i][j]=max(rmq[k][i][j],rmq[k-1][i][j+(1<<(k-1))]),ok2=1;
            if(ok1 && ok2) rmq[k][i][j]=max(rmq[k][i][j],rmq[k-1][i+(1<<(k-1))][j+(1<<(k-1))]);
        }
    for(int q=0; q<m; ++q) {
        int i,j,k,rq,lg,ok1=0,ok2=0;
        f>>i>>j>>k;
        --i; --j;;
        lg=(1<<log[k]);
        rq=rmq[log[k]][i][j];
        if(i+k-lg>=0 && i+k-lg<n) rq=max(rq,rmq[log[k]][i+k-lg][j]),ok1=1;
        if(j+k-lg>=0 && j+k-lg<n) rq=max(rq,rmq[log[k]][i][j+k-lg]),ok2=1;
        if(ok1 && ok2) rq=max(rq,rmq[log[k]][i+k-lg][j+k-lg]);
        g<<rq<<'\n';
    }
    return 0;
}
