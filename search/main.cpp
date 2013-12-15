#include <iostream>
#include <fstream>
#include <cstring>
#define DN 105
#define DL 5005
#define DM 200005
using namespace std;

int n,m,sz,next[DN][DL][26];//cuvant pozitie litera
char ops[DM],cuv[DL],op;
int lst[DL][DN];

int main()
{
    ifstream f("search.in");
    ofstream g("search.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>(cuv+1);
        for(int k=strlen(cuv+1); k; --k) {
            for(int j=0; j<26; ++j) next[i][k][j]=next[i][k+1][j];
            next[i][k][cuv[k]-'a']=k;
        }
    }
    for(int i=1; i<=m; ++i) {
        f>>op;
        if(op=='-') --sz;
        else ops[++sz]=op;
        int rq=0;
        for(int i=1; i<=n; ++i) {
            int unde=lst[sz-1][i]+1;
            if(next[i][unde][ops[sz]-'a'] && lst[sz-1][i]!=-1) {
                lst[sz][i]=next[i][unde][ops[sz]-'a'];
                ++rq;
            }else lst[sz][i]=-1;
        }
        g<<rq<<'\n';
    }
    return 0;
}
