#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream f("rj.in");
ofstream g("rj.out");

queue <int> coada;

char h[105][105];
int n,m,dis[100000];

void(int x,int y )
{ coada.push(x*1000+y);
  while (coada.size()>0)
  {
    if(h[x+1][y]==' ')
      {
        coada.
      }
    if(h[x-1][y]==' ')
    if(h[x][y+1]==' ')
    if(h[x][y-1]==' ')

  }

}
int main ()
{ f>>n>>m;
  for(i=1;i<=n;i++)
    f.getline(h[i]);
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(h[i][j]=='R')
            bfs(i,j);
