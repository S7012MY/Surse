#include <cstdio>
#include <algorithm>
#include <cstring>
#define BM 100005
#define MARE 9900000
using namespace std;
char s[BM];
int ev[BM],dime,vf,sa[BM],dima,st[BM];
int main () {
	int i,j,n,semn=1,nrc,c=0,sc,smax=-100,sf=0;
	freopen("expresie2.in","r",stdin);
	freopen("expresie2.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;++i){
		nrc=0;
		if(s[i]>='0'&&s[i]<='9'){
			for(;s[i]>='0'&&s[i]<='9';){
				nrc=nrc*10+s[i]-'0';
				++i;
			}
			if(semn==-1){
				ev[++dime]=-1*nrc;
				semn=1;
			}
			else ev[++dime]=nrc;
		}
		if(s[i]=='(')ev[++dime]=MARE+1;
		if(s[i]==')')ev[++dime]=MARE+2;
		if(s[i]=='[')ev[++dime]=MARE+3;
		if(s[i]==']')ev[++dime]=MARE+4;
		if(s[i]=='-')semn=-1;
	}
	for(i=1;i<=dime;++i)if(ev[i]<100){
		++c;
		//fprintf(stderr,"%d ",ev[i]);
	}
	printf("%d\n",c);
	for(i=1;i<=dime;++i){
		if(ev[i]<100||ev[i]==MARE+1||ev[i]==MARE+3)st[++vf]=ev[i];
		else if(ev[i]==MARE+2){
			dima=0;
			smax=sc=-100;
			for(;st[vf]!=MARE+1;){
				sa[++dima]=st[vf];
				--vf;
			}
			for(j=1;j<=dima;++j){
				if(sc+sa[j]<=sa[j])sc=sa[j];
				else sc+=sa[j];
				if(smax<sc)smax=sc;
			}
			st[vf]=smax;
		}
		else if(ev[i]==MARE+4){
			dima=0;
			for(;st[vf]!=MARE+3;){
				sa[++dima]=st[vf];
				--vf;
			}
			sort(sa+1,sa+dima+1);
			st[vf]=sa[(dima+1)/2];
		}
		//fprintf(stderr,"%d %d\n",vf,ev[i]);
	    //for(int i=1; i<=vf; ++i) fprintf(stderr,"%d ",st[i]);
	    //fprintf(stderr,"\n");
	}
	//for(i=1;i<=vf;++i)fprintf(stderr,"%d ",st[i]);
	for(;vf;--vf)sf+=st[vf];
	printf("%d\n",sf);
	return 0;
}
