//#include <iostream>
//#include <string>
//#include <vector>
//#include <bitset>
//#define DN 20005
//using namespace std;
//
//typedef vector<int> graf[DN];
//typedef vector<int>::iterator it;
//graf gr;
//int n,m,e,l[DN],r[DN],nrc,c[DN];
//string mt[105];
//bitset<DN> viz;
//vector<int> a,b;
//
//int cupleaza(int s) {
//    if(viz[s]) return 0;
//    viz[s]=1;
//    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(-1==r[*i]||cupleaza(r[*i])) {
//        l[s]=*i; r[*i]=s;
//        return 1;
//    }
//    return 0;
//}
//
//void check() {
//  int sum=0;
//  for(int i=0; i<n; ++i) sum+=(l[i]!=-1);
//  if(sum==n) for(int j=0; j<n; ++j) c[j]=1;
//
//  sum=0;
//  for(int j=0; j<n; ++j) sum+=(c[j]!=-1);
//  if(sum==n) for(int i=0; i<n; ++i) l[i]=1;
//}
//
//int main()
//{
//    cin>>n;
//    for(int i=0; i<n; ++i) l[i]=r[i]=c[i]=-1;
//    for(int i=0; i<n; ++i) cin>>mt[i];
//    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(mt[i][j]!='E') gr[i].push_back(j);
//
//    for(bool ok=1; ok;) {
//        ok=0; viz&=0;
//        for(int i=0; i<n; ++i) if(-1==l[i]) ok|=cupleaza(i);
//    }
//
//    for(int i=0; i<n; ++i) if(l[i]!=-1) a.push_back(i),b.push_back(l[i]),c[l[i]]=1;
//    check();
//    for(int j=0; j<n; ++j) if(c[j]==-1) {
//      for(int i=0; i<n; ++i) if(mt[i][j]!='E') {
//        a.push_back(i); b.push_back(j);
//        c[j]=1;
//        break;
//      }
//    }
//    check();
//    for(int i=0; i<n; ++i) if(-1==l[i]) for(int j=0; j<n; ++j) if(mt[i][j]!='E') {
//      l[i]=1;
//      c[j]=1;
//      a.push_back(i);
//      b.push_back(j);
//      break;
//    }
//    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(-1==l[i] && -1==c[j]) {
//      cout<<-1;
//      return 0;
//    }
//    for(int i=0; i<a.size(); ++i) cout<<a[i]+1<<' '<<b[i]+1<<'\n';
//}
