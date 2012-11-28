/*
    se da o matrice de N pe M care reprezinta codificarea unor cabluri.
    sa se determine cate cabluri se vor intersecta dupa intinderea tuturor cablurilor
*/
#include <iostream>
#include <fstream>
#include <cstring>
#define DN 105
using namespace std;

int n,m,mt[DN][DN],start[DN],end[DN],rez[DN];

int main()
{
	for(int i=1; i<=20; ++i) {
		memset(start,0,sizeof(start));
		memset(end,0,sizeof(end));
		memset(rez,0,sizeof(rez));
		char in[55],out[55];
		sprintf(in,"teste/grader_test%d.in",i);
		sprintf(out,"teste/grader_test%d.ok",i);
		ifstream f(in); 
		ofstream g(out);
		f>>n>>m;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>mt[i][j];
		for(int i=1; i<=n; ++i) {
		    start[mt[i][1]]=i;
		    end[mt[i][m]]=i;
		}
		for(int i=1; i<=n; ++i) if(start[i])
		    for(int j=1; j<=n; ++j) if(start[j]<start[i] && end[j]>end[i]) {
		        ++rez[i]; ++rez[j];
		    }
		for(int i=1;i<=n && start[i]; ++i) g<<rez[i]<<' ';
	}
    return 0;
}
