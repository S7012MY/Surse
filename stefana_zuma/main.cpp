#include <cstdio>
#include <cstring>
struct grup{
	int ls,ld;
	char lit;
};
char a[205];
grup b[205];

int main () {
	int n,i,x,dim=1,s,d,c=0;
	freopen ("zuma.in","r",stdin);
	freopen ("zuma.out","w",stdout);
	scanf("%d",&x);
	--x;
	scanf("%s",a);
	n=strlen(a);
	b[1].ls=0;

	b[1].ld=0;
	b[1].lit=a[0];
	for(i=0;i<n-1;++i){

		if(a[i]==a[i+1]){
			b[dim].ld++;
		}
		else{
			b[++dim].ls=i+1;
			b[dim].ld=i+1;
			b[dim].lit=a[i+1];
		}
	}

	for(i=1;i<=dim;++i){
		if(x<b[i].ld&&b[i].ls<x){
			b[i].lit=-6;
			s=i-1;
			d=i+1;
			for(;s>=0&&d<=dim;){
				if(b[s].lit==b[d].lit&&b[d].ld-b[d].ls+1+b[s].ld-b[s].ls+1>2){
					b[s].lit=b[d].lit=-6;
					--s;
					++d;
				}
				else break;
			}
			break;
		}
	}

	for(i=1;i<=dim;++i){
		if(b[i].lit!=-6){
			++c;
			for(;b[i].ld-b[i].ls>=0;){
				printf("%c",b[i].lit);
				++b[i].ls;
			}
		}
	}
	if(c==0)printf (" ");
	return 0;

}
