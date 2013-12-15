//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//using namespace std;
//#define DM 400001
//#define DN 10005
//
//int x[DM],y[DM],ind[DM],cost[DM],pre[DM],tcost;
//vector<int> gr[DN];
//int n,m,c,sz;
//int tx,ntx;
//
//int find(int i) {
//    if(pre[i]==i) return i;
//    pre[i]=find(pre[i]);
//    return pre[i];
//}
//
//void reuniune(int i,int j) {
//    pre[find(i)]=find(j);
//}
//
//bool cmp(int i,int j) {//pentru sortarea indicilor in functie de cost
//    return(cost[i] < cost[j]);
//}
//
//vector<int> nefol; int viz[DN],cc;
//
//void dfs(int s) {
//  viz[s]=1;
//  for(vector<int>::iterator i=gr[s].begin();i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
//}
//
//int main()
//{
//  freopen("asd.in","r",stdin);
//    int i,t;
//    for(cin>>t;t;--t) {
//      cin>>n>>m>>c;
//      for(int i=1; i<=n; ++i) gr[i].clear(),viz[i]=0,pre[i]=i;
//      nefol.clear();
//      tcost=ntx=tx=cc=0;
//      for(i=1; i<=m; i++) {
//          cin>>x[i]>>y[i]>>cost[i];
//          cost[i]=-cost[i];
//          ind[i]=i;
//      }
//      for(i=1; i<=n; i++) pre[i]=i;
//      sort(ind+1,ind+m+1,cmp);
//      for(i=1;i<=m; i++)
//          if(find(x[ind[i]])!=find(y[ind[i]])) {
//              gr[x[ind[i]]].push_back(y[ind[i]]);
//              gr[y[ind[i]]].push_back(x[ind[i]]);
//              reuniune(x[ind[i]],y[ind[i]]);
//          } else {
//            nefol.push_back(-cost[ind[i]]);
//           // cout<<x[ind[i]]<<' '<<y[ind[i]]<<'\n';
//          }
//      sort(nefol.begin(),nefol.end());
//      //cout<<"nefol:\n";
//      //for(int i=0; i<nefol.size(); ++i) cout<<nefol[i]<<' ';
//      //cout<<'\n';
//      int pnefol=0;
//      for(int i=1; i<=n; ++i) if(!viz[i]) {
//        ++cc;
//        dfs(i);
//      }
//      for(int i=1; i<cc; ++i) {
//        if(pnefol>=nefol.size() || nefol[pnefol]>c) {
//          ++ntx;tcost+=c;
//        }else {
//          ++tx;
//          tcost+=nefol[pnefol];++pnefol;
//        }
//      }
//      cout<<ntx<<' '<<tx<<' '<<tcost<<'\n';
//    }
//    return 0;
//}
