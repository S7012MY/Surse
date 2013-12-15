#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define DN 105
#define MULT 999999999
using namespace std;

int n,m,t,sir[DN],ind[DN],indi[DN],gr[DN][DN],cgraf[DN][DN],ns=8,nsf=16,cmin=1,cmax=19;

bool fixeaza(int nod) {
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(i>=nod && j>=nod && gr[i][j]) cgraf[i][j]=gr[i][j];
        else cgraf[i][j]=MULT;
    int ok=0;
    for(int k=nod; k<=n; ++k) {
        //rf
        for(int i=nod; i<=n; ++i) if(cgraf[i][k]<=MULT) for(int j=nod; j<=n; ++j) if(cgraf[i][j]>cgraf[i][k]+cgraf[k][j]) cgraf[i][j]=cgraf[i][k]+cgraf[k][j];
        for(int i=nod; i<=k; ++i) for(int j=nod; j<=k; ++j)  {
            //avem solutie ??
            if(cgraf[i][j]<t) ok=1;
            if(cgraf[i][j]==t) {
                ns=i;
                nsf=j;
                cmin=sir[nod];
                cmax=sir[k];
                return 1;
            }
        }
    }
    return ok!=1;
}

int main()
{
    ifstream f("coach.in");
    ofstream g("coach.out");
    f>>n>>m>>t;
    for(int i=1; i<=n; ++i) {
        f>>sir[i];
        ind[i]=i;
    }
    for (int i=1; i<n; ++i)for (int j=i+1;j<=n; ++j) if(sir[i]>sir[j]) {
         indi[ind[i]]=j, indi[ind[j]]=i;
         swap(sir[i],sir[j]);
         swap(ind[i],ind[j]);
    }
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[indi[a]][indi[b]]=gr[indi[b]][indi[a]]=c;
    }
    for(int i=1; i<n; ++i) //fixam un cmin
        if(fixeaza(i))
            break;
    g<<ind[ns]<<' '<<ind[nsf]<<' '<<cmin<<' '<<cmax<<'\n';
    return 0;
}
