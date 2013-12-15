//#include <iostream>
//#include <string>
//#define DN 1000005
//#define LL long long
//using namespace std;
//
//LL k,n,ai[4*DN],v[DN];
//string s;
//
//void build(int vn=1,int ls=1,int ld=n) {
//  if(ls==ld) {
//    ai[vn]=v[ls];
//    return;
//  }
//  int fs=(vn<<1),m=(ls+ld)>>1;
//  build(fs,ls,m);
//  build(fs+1,m+1,ld);
//  ai[vn]=max(ai[fs],ai[fs+1]);
//}
//
//int findSum(LL sum,int vn=1,int ls=1,int ld=n){
//  if(ls==ld) {
//    if(ai[vn]>=sum) return ls;
//    if(sum>=0) return 0;
//    return -1;
//  }
//  int fs=(vn<<1),m=(ls+ld)>>1;
//  if(ai[fs+1]>=sum) return findSum(sum,fs+1,m+1,ld);
//  else if(ai[fs]>=sum) return findSum(sum,fs,ls,m);
//  else return -1;
//}
//
//LL bs(int i) {
//  LL si=v[n]-v[i-1],st=v[n],ls=0,ld=k-1,m,r=-1;
//  for(;ls<=ld;) {
//    m=(ls+ld)>>1;
//    //cerr<<ls<<' '<<m<<' '<<ld<<'\n';cerr.flush();
//    int p=findSum(-(si+st*m));
//    if(m==k-1) p=0;
//    if(si+st*m+v[p]>=0) {
//      r=n-i+1+n*m+p;
//      ls=m+1;
//    }else ld=m-1;
//  }
//  return r;
//}
//
//int main()
//{
//    cin>>k>>s;
//    n=s.size();
//    for(int i=1; i<=n; ++i) v[i]=v[i-1]+(s[i-1]=='0'?-2:3);
//    build();
//    LL rez=0;
//    for(int i=1;i<=n; ++i) {
//      int p=findSum(v[i-1]);
//      if(p>=i) rez=max(rez,(long long) p-i+1);
//      rez=max(rez,bs(i));
//      //cerr<<i<<' '<<rez<<'\n';
//    }
//    cout<<rez;
//    return 0;
//}
