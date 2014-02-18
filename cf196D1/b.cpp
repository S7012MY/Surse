//#include <vector>
//#include <cstdio>
//#include <iostream>
//#define deb(n) fprintf(stderr,"%d",(n));
//#define foreach(V) for(typeof (V).begin() it = (V).begin(); it != (V).end(); ++it)
//#define DN 100005
//#define DL 20
//using namespace std;
//int n,m,d,k,p[DN];
//int l[DN<<1],euler[DN<<1],lg[DN<<1],prim[DN],rmq[DL][DN<<2];
//vector<int>g[DN];
//vector<int>::iterator it;
//
//void dfs(int sursa,int nivel,int f){
//    euler[++k]=sursa;
//    l[k]=nivel;
//    prim[sursa]=k;
//    foreach(g[sursa]) if(*it!=f){
//        dfs(*it,nivel+1,sursa);
//        euler[++k]=sursa;
//        l[k]=nivel;
//    }
//}
//
//void init_rmq() {
//    int i,o,j;
//    for(i=2;i<=k; ++i) lg[i]=lg[i/2]+1;
//    for(i=1;i<=k; ++i) rmq[0][i]=i;
//    for(i=1; (1<<i)<k;++i)
//        for(j=1; j<=k-(1<<i);++j) {
//            o=1<<(i-1);
//            rmq[i][j]=rmq[i-1][j];
//            if(l[rmq[i-1][j+o]]<l[rmq[i][j]]) rmq[i][j]=rmq[i-1][j+o];
//        }
//}
//
//int lca (int x,int y) {
//    int dif,o,rez,sh,a=prim[x],b=prim[y];
//    if(a>b) {
//        int aux=a;
//        a=b;
//        b=aux;
//    }
//    dif=b-a+1;
//    o=lg[dif];
//    rez=rmq[o][a];
//    sh=dif-(1<<o);
//    if(l[rez]>l[rmq[o][a+sh]]) rez=rmq[o][a+sh];
//    return euler[rez];
//}
//
//int da[DN],db[DN],dc[DN];
//#include <queue>
//void bfs(int s,int d[DN]) {
//  for(int i=1; i<=n; ++i) d[i]=(1<<30);
//  d[s]=0;
//  queue<int> c;
//  for(c.push(s);c.size(); c.pop()) {
//    int fr=c.front();
//    //cerr<<fr<<'\n';
//    foreach(g[fr]) {
//      //cerr<<*it<<' ';
//      if(d[*it]>d[fr]+1) {
//        d[*it]=d[fr]+1;
//        c.push(*it);
//
//      }
//    }
//  }
//  //cerr<<'\n';
//}
//
//int main()
//{
//    int i,x,y;
//    //freopen("lca.in","r",stdin);
//    //freopen("lca.out","w",stdout);
//    scanf("%d %d %d",&n,&m,&d);
//    for(int i=1; i<=m; ++i) scanf("%d ",&p[i]);
//    for(i=1; i<n; ++i) {
//        scanf("%d %d",&x,&y);
//        g[x].push_back(y);
//        g[y].push_back(x);
//    }
//    dfs(1,0,0);
//    init_rmq();
//    int la=p[1],lb=p[1],lc=p[1],mx=0;
//    for(i=2; i<=m; ++i) la=lca(la,p[i]);
//    bfs(la,da);
//    for(int i=1; i<=m; ++i) if(da[p[i]]>mx) {
//      mx=da[p[i]];
//      lb=p[i];
//    }
//    bfs(lb,db);
//    mx=0;
//    for(int i=1; i<=m; ++i) if(db[p[i]]>mx && p[i]!=lb && p[i]!=la) {
//      mx=db[p[i]];
//      lc=p[i];
//    }
//    bfs(lc,dc);
//    int rez=0;
//
//    for(int i=1; i<=n; ++i) {
//      //cerr<<i<<' '<<da[i]<<' '<<db[i]<<'\n';
//      if(max(dc[i],db[i])<=d) ++rez;
//    }
//    cout<<rez;
//    return 0;
//}