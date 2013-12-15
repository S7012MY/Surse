//#include <iostream>
//#include <fstream>
//#include <bitset>
//#include <cstring>
//#define DN 105
//using namespace std;
//
//int n,m,it[DN][DN],r[DN];
//bitset<DN> viz;
//
//bool cupl(int s) {
//    if(s==-1) return 1;
//    if(viz[s]) return 0;
//    viz[s]=1;
//    for(int i=1; i<=n; ++i) if(it[s][i] && cupl(r[i])) {
//        r[i]=s;
//        return 1;
//    }
//    return 0;
//}
//
//int main()
//{
//    ifstream f("drumuri2.in");
//    ofstream g("drumuri2.out");
//    f>>n>>m;
//    for(int i=1; i<=m; ++i) {
//        int a,b;
//        f>>a>>b;
//        it[a][b]=1;
//    }
//    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
//        it[i][j]|=(it[i][k]&it[k][j]);
//    int rez=0;
//    memset(r,-1,sizeof(r));
//    for(int i=1; i<=n; ++i) {
//        viz&=0;
//        if(!cupl(i)) ++rez;
//    }
//    g<<rez;
//    return 0;
//}
