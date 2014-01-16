#include <iostream>
#include <fstream>
#define D 1000005
#include <queue>
#include <vector>
using namespace std;
vector <int>:: iterator ive;
queue <int> c;
ifstream f("bfs.in");
ofstream g("bfs.out");
vector <int> ve[D];
int n,m,s,i,j,fr,d[D],k;
int main ()
{
    f>>n>>m>>s;
    for(k=1;k<=m;k++)
        {
          f>>i>>j;
          ve[i].push_back(j);
        }
    d[s]=1;
    for(c.push(s);!c.empty();c.pop())
        {
          fr=c.front();
          for(ive=ve[fr].begin();ive!=ve[fr].end();ive++)
              {
                if(d[(*ive)]==0)
                {d[*ive]=d[fr]+1;
                c.push(*ive);}
              }
        }

    for(i=1;i<=n;i++)
        g<<d[i]-1<<" ";
    return 0;
}
