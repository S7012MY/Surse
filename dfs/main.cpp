#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream f("dfs.in");
ofstream g("dfs.out");
vector <int> gr[100005];
int i,j,n,m,x,y,v[100000],k;
void dfs(int p)
{ v[p]=1;
  vector <int> :: iterator ir;
  for(ir=gr[p].begin();ir!=gr[p].end();ir++)

        if(v[*ir]==0)
          dfs(*ir);


}

int main()
{   f>>n>>m>>b;
    for(i=1;i<=m;i++)
        {
          f>>x>>y;
          gr[x].push_back(y);
          gr[y].push_back(x);
          }
    for(i=1;i<=n;i++)
        v[i]=0;
     k=0;
    for(i=1;i<=n;i++)
        if(v[i]==0) {
            dfs(i);
            k++;
        }
    g<<k;

}

