#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("honest.in");
ofstream g("honest.out");

vector <int> gr[1005];

int n,m,l,k,x,y,v[1005],s[1005],c[1005];
char b,a[1005][1005];
void dfst(int nd)
{  v[nd]=1;
  vector <int> :: iterator ir;
  for(ir=gr[nd].begin();ir!=gr[nd].end();ir++)
      if(v[*ir]==0)
         dfst(*ir);
  s[k]=nd;
  k++;
}
void dfsa(int nd)
{ v[nd]=1;
  vector <int> :: iterator ir;
  for(ir=gr[nd].begin();ir!=gr[nd].end();ir++)
      {if(c[nd]==1)
          {
          if(a[nd][*ir]=='c')
              c[*ir]=1;
          else
              c[*ir]=0;
          }
      else
          {
          if(a[nd][*ir]=='c')
              c[*ir]=0;
          else
              c[*ir]=1;
          }
    if(v[*ir]==0)
      dfsa(*ir);}}
int main()
{   int i,j;
    f>>n>>m;
      k=0;
    for (i=1;i<=m;i++)
        {
          f>>x>>b>>y;
          a[x][y]=b;
          gr[x].push_back(y);
        }
    for(i=1;i<=n;i++)
        {
          if(v[i]==0)
            dfst(i);
        }
    for(i=1;i<=n;i++)
        v[i]=0;
    for(i=1;i<=n;i++)
          c[i]=0;
    c[i]=1;
    for(i=k;i>0;i--)
        if(v[i]==0)
          dfsa(i);
    l=0;
    for(i=1;i<=n;i++)
        if(c[i]==0)
          l++;
    if(l>n/2)
      for(i=1;i<=n;i++)
          if(c[i]==1)
            c[i]=0;
          else c[i]=1;
    for(i=1;i<=n;i++)
        g<<c[i]<<"\n";
    return 0;
}
