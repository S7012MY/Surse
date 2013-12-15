//#include <iostream>
//#include <fstream>
//#include <vector>
//#define DN 15005
//#define MLT (1LL<<60)
//using namespace std;
//
//typedef vector<int>::iterator it;
//
//long long t,n,m,v[DN],bst[DN],viz[DN];
//vector<int>gr[DN];
//
//void dfs(int s) {
//  viz[s]=1;
//  bst[s]=v[s];
//  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
//    if(!viz[*i]) dfs(*i);
//    bst[s]=max(bst[s],bst[*i]+v[s]);
//  }
//}
//
//int main()
//{
//    ifstream f("easygraph.in");
//    ofstream g("easygraph.out");
//    for(f>>t;t--;) {
//      f>>n>>m;
//      for(int i=1; i<=n; ++i) {
//        f>>v[i];
//        gr[i].clear();
//        viz[i]=0;
//      }
//      for(;m--;) {
//        int a,b;
//        f>>a>>b;
//        gr[a].push_back(b);
//      }
//      long long rez=-MLT;
//      for(int i=1; i<=n; ++i) {
//        if(!viz[i]) dfs(i);
//        rez=max(rez,bst[i]);
//      }
//      g<<rez<<'\n';
//      //cout<<rez;
//    }
//    return 0;
//}
