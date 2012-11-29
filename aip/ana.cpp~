#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> per;
priority_queue<per,vector<per>,less<per> >h;
int n,k;

//<parsing>
FILE* fin=fopen("ana.in","r");
const unsigned maxb=800192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
	while(buf[ptr]<'0'||'9'<buf[ptr])
		if(++ptr>=maxb)
			fread(buf,maxb,1,fin),ptr=0;
	while('0'<=buf[ptr]&&buf[ptr]<='9'){
		nr=nr*10+buf[ptr]-'0';
		if(++ptr>=maxb)
			fread(buf,maxb,1,fin),ptr=0;
	}
	return nr;
}
//</parsing>

int main () {
	int i,el;
	freopen("ana.out","w",stdout);
	n=getInt(); k=getInt();
	for(i=1;i<=n-1;++i){
		el=getInt();
		if(i<=k)h.push(make_pair(el,i));
		else if(h.top().first>el){
			h.pop();
			h.push(make_pair(el,i));
		}
	}
	printf("%d",h.top().second);
	return 0;
} 
