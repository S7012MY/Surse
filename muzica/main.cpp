#include <iostream>
#include <fstream>
#include <vector>
#define PRIM 1007
using namespace std;

int n,m,a,b,c,d,e,rez;

vector<int> l[2][PRIM];
vector<int>::iterator it;

int cauta(int ind,int x) {
    for(it=l[ind][x%PRIM].begin();it!=l[ind][x%PRIM].end();it++)
        if(*it==x) return 1;
    return 0;
}

void insert(int ind,int el) {
    l[ind][el%PRIM].push_back(el);
}

int main()
{
    ifstream f("muzica.in");
    ofstream g("muzica.out");
    f>>n>>m>>a>>b>>c>>d>>e;
    for(int i=1; i<=n; ++i) {
        int x;
        f>>x;
        insert(0,x);
    }
    if(cauta(0,a)) {
        insert(1,a);
        ++rez;
    }
    if(a!=b && cauta(0,b)) {
        ++rez;
        insert(1,b);
    }
    for(int i=3; i<=m; ++i) {
        int x=(c*1LL*b+d*1LL*a)%e;
        if(cauta(0,x) && !cauta(1,x)) {
            insert(1,x);
            ++rez;
        }
        a=b;
        b=x;
    }
    g<<rez;
    return 0;
}
