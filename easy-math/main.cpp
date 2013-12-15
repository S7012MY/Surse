#include <iostream>
#include <queue>
#include <bitset>
#include <cassert>
#define DX 100005
using namespace std;

//2*a+b;
bitset<DX> viz[5];
int lg[5][DX],nr4[5][DX];
int solve(int x) {
  queue<pair<int,int> > c;
  viz[0]&=0;
  viz[4]&=0;
  lg[4][4%x]=1;nr4[4][4%x]=1;
  for(c.push(make_pair(4%x,4));!c.empty(); c.pop()) {
    int md=c.front().first,lst=c.front().second;
    //cout<<md<<' ';
    int fr=md;
    viz[lst][md]=1;
    if(md==0) return nr4[lst][0]+lg[lst][0];
    int nxt=(md*10)%x;
    if(!viz[0][nxt]) {
      nr4[0][nxt]=nr4[lst][fr];
      lg[0][nxt]=lg[lst][fr]+1;
      c.push(make_pair(nxt,0));
    }
    if(lst==4) {
      nxt=(md*10+4)%x;
      if(!viz[4][nxt]) {
        nr4[4][nxt]=nr4[4][fr]+1;
        lg[4][nxt]=lg[4][fr]+1;
        c.push(make_pair(nxt,4));
      }
    }
  }
  return 0;
  assert(0);
}

int main()
{
    int t,x;
    for(cin>>t;t--;) {
      cin>>x;
      cout<<solve(x)<<'\n';
    }
    return 0;
}
