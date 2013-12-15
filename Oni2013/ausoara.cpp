//#include <fstream>
//#include <vector>
//using namespace std;
//
//int n,m,poz[105];
//vector<int> s[105],r;
//
//int main() {
//  ifstream f("ausoara.in");
//  ofstream g("ausoara.out");
//  f>>n;
//  for(int i=0; i<n; ++i) {
//    f>>m;
//    for(int j=0; j<m; ++j) {
//      int x; f>>x;
//      s[i].push_back(x);
//    }
//  }
//  for(int i=0; i<s[0].size(); ++i) {
//    int ok=1;
//    for(int j=1; j<n; ++j) {
//      for(;poz[j]<s[j].size()-1 && s[j][poz[j]]<s[0][i]; ++poz[j]);
//      if(s[j][poz[j]]!=s[0][i]) ok=0;
//    }
//    if(ok) {
//      for(int j=1; j<n; ++j) ++poz[j];
//      r.push_back(s[0][i]);
//    }
//  }
//  g<<r.size()<<' ';
//  for(int i=0; i<r.size(); ++i) g<<r[i]<<' ';
//}
