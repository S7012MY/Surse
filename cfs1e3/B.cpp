//#include <iostream>
//#include <queue>
//#include <vector>
//#define DN 50005
//#define x first
//#define y second
//using namespace std;
//
//int n,d[DN],ld,inq[DN];
//vector<pair<int,int> > gr[DN];
//queue<int> c;
//
//int main() {
//  cin>>n;
//  for(int i=0; i<n; ++i) {
//    int a,b,c;
//    cin>>a>>b>>c;
//    ld=max(ld,b+1); gr[a].push_back(make_pair(b+1,c));
//  }
//  for(int i=0; i<=ld; ++i) {
//    d[i]=-(1<<30);
//    gr[i].push_back(make_pair(i+1,0));
//    gr[i+1].push_back(make_pair(i,-1));
//  }
//  d[0]=0;
//  for(c.push(0);c.size();c.pop()) {
//    int fr=c.front(); inq[fr]=0;
//    for(vector<pair<int,int> >::iterator it=gr[fr].begin(); it!=gr[fr].end(); ++it)
//      if(d[it->x]<d[fr]+it->y) {
//        d[it->x]=d[fr]+it->y;
//        if(!inq[it->x]) {
//          c.push(it->x);
//          inq[it->x]=1;
//        }
//      }
//  }
//  cout<<d[ld];
//}
