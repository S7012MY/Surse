#include <cstdio>
#include <cstring>
#include <iostream>
#define DN 2025
using namespace std;

char sir1[DN],sir2[DN],cmlsc[DN];
int n,m,d[DN][DN],d2[DN][DN],nre,nr[DN][DN]={1},nr2[DN][DN],cnt;

int main()
{
    int i,j;
	scanf("%s %s",sir1+1,sir2+1);
	n=strlen(sir1+1); m=strlen(sir2+1);
	for(i=1; i<=n; i++)
        for(j=1; j<=m; j++) {
            if(sir1[i]==sir2[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]= max(d[i][j-1],d[i-1][j]);
            d2[i][j]=i+j-d[i][j];
        }
  //  nr[0][0]=1;
    for(i=1; i<=n; ++i) nr[i][0]=1;
    for(j=1; j<=m; ++j) nr[0][j]=1;
    for(i=1; i<=n; ++i) for(j=1; j<=m; ++j) if(0==d[i][j]) nr[i][j]=1;
    for(i=1; i<=n; ++i) for(j=1; j<=m;++j) if(0==nr[i][j]) {
        if(sir1[i]==sir2[j]) nr[i][j]=nr[i-1][j-1];
        else {
       	    cnt=0;
            if(d[i-1][j]==d[i][j]) nr[i][j]+=nr[i-1][j],++cnt;
	    if(d[i][j-1]==d[i][j]) nr[i][j]+=nr[i][j-1],++cnt;
	    if(cnt==2 && d[i-1][j-1]==d[i][j]) nr[i][j]-=nr[i-1][j-1];
	}
    }
    for(i=1; i<=n; ++i) nr2[i][0]=1;
    for(j=1; j<=m; ++j) nr2[0][j]=1;
    for(i=1; i<=n; ++i) for(j=1; j<=m;++j) if(0==nr2[i][j]) {
        if(sir1[i]==sir2[j]) nr2[i][j]=nr2[i-1][j-1];
        else {
       	    cnt=0;
            if(d2[i-1][j]==d2[i][j]) nr2[i][j]+=nr2[i-1][j],++cnt;
	    if(d2[i][j-1]==d2[i][j]) nr2[i][j]+=nr2[i][j-1],++cnt;
	    if(cnt==2 && d2[i-1][j-1]==d2[i][j]) nr2[i][j]-=nr2[i-1][j-1];
	}
    }
    printf("%d\n",nr2[n][m]);
    for(int i=1; i<=n; ++i) {
    	for(int j=1; j<=m; ++j) printf("%d ",d2[i][j]);
    	printf("\n");
    }
    printf("\n");
    for(int i=1; i<=n; ++i) {
    	for(int j=1; j<=m; ++j) printf("%d ",nr2[i][j]);
    	printf("\n");
    }
	return 0;
}

