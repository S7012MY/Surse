#include <fstream>
#include <algorithm>
#include <deque>
#define x first
#define y second
#define DN 105
using namespace std;

typedef pair<int,int> per;

int n,a,bst[DN][DN][DN];
per p[DN];

int memo(deque<int> &pc) {
    if(pc.empty()) return 0;
    int ls=pc.front(),ld=pc.back(),sz=pc.size();
    int ih=ls;
    for(int i=1; i<sz; ++i) if(p[pc[i]].y<p[ih].y) ih=pc[i];
    if(bst[ls][ld][ih]) return bst[ls][ld][ih];

    int r=DN;
    deque<int> st,dr=pc;
    for(int i=0; i<sz-1; ++i) {
      st.push_back(pc[i]); dr.pop_front();
      r=min(r,memo(st)+memo(dr));
    }
    int ymin=a/max(1,p[ld].x-p[ls].x);
    if(ymin>0) {
      deque<int> sus;
      for(int i=0; i<sz; ++i) if(p[pc[i]].y>ymin)
        sus.push_back(pc[i]);
      r=min(r,1+memo(sus));
    }

    bst[ls][ld][ih]=r;
    return r;
}

int main()
{
    ifstream f("photo.in");
    ofstream g("photo.out");
    f>>n>>a;
    deque<int> in;
    for(int i=1; i<=n; ++i) {
      f>>p[i].x>>p[i].y;
      in.push_back(i);
    }
    sort(p+1,p+n+1);
    g<<memo(in);
    return 0;
}
