#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");

vector <int> gr[50005];
int n,n1,m,x,i,j,y,v[50005],b[50005];
void cit(int q)
{
  b[n1]=q;
  n1--;
}
void dfs(int z)
{ v[z]=1;
  vector <int> :: iterator ir;
    for(ir=gr[z].begin();ir!=gr[z].end() ;ir++)
        if(v[*ir]==0)
            dfs(*ir);
  cit(z);
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {
          f>>x>>y;
          gr[x].push_back(y);
        }
    for(i=1;i<=n;i++)
        b[i]=0;
    n1=n;
    for(i=1;i<=n;i++)
          if(v[i]==0)
            dfs(i);
    for(i=1;i<=n;i++)
        g<<b[i]<<" ";
    return 0;
}
