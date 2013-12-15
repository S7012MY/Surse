#include <iostream>
#include <fstream>
#define DN 65
using namespace std;

int n,m,q,mt[DN][DN];
char pot[DN][DN][DN][DN],am[3505][DN][DN],are[3505];

int main()
{
    ifstream f("luna.in");
    ofstream g("luna.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>mt[i][j];
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        are[mt[i][j]]=1;
        pot[i][j][i][j]=1;
        for(int k=i+1; k<=n && mt[i][j]==mt[k][j]; ++k) pot[i][j][k][j]=1;
        for(int k=j+1; k<=m && mt[i][j]==mt[i][k]; ++k) pot[i][j][i][k]=1;
        for(int a=i+1; a<=n; ++a) for(int b=j+1; b<=m; ++b)
            if(pot[i][j][a-1][b] && pot[i][j][a][b-1] && mt[i][j]==mt[a][b]) pot[i][j][a][b]=1;
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int a=i; a<=n; ++a) for(int b=j; b<=m; ++b)
        if(pot[i][j][a][b]) {
            //cout<<i<<' '<<j<<' '<<a<<' '<<b<<'\n';
            am[mt[i][j]][a-i+1][b-j+1]=1;
        }
    f>>q;
    for(int i=1; i<=q; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        if(a>2500) {
            g<<"Tara de provenienta nu are parcele pe Luna!\n";
            continue;
        }
        if(!are[a]) {
            g<<"Tara de provenienta nu are parcele pe Luna!\n";
            continue;
        }
        if(max(b,c)>max(n,m)) {
            g<<"Cererea nu poate fi satisfacuta!\n";
            continue;
        }
        if(am[a][b][c] || am[a][c][b]) g<<"Cererea poate fi satisfacuta!\n";
        else if(are[a]) g<<"Cererea nu poate fi satisfacuta!\n";
        else g<<"Tara de provenienta nu are parcele pe Luna!\n";
    }
    return 0;
}
