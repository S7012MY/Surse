#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define x first
#define y second
#define LL long long
#define DN 1000005
#define LHEIGHT 4.5
#define mp make_pair
using namespace std;

typedef pair<LL, LL> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;

double acc,ms,da;

double time(double acc,double maxSpeed,double deAcc,double dist) {
  double maxAccDist=((acc/2.0)*(maxSpeed/acc)*(maxSpeed/acc));
  double maxDeAccDist=((deAcc/2.0)*(maxSpeed/deAcc)*(maxSpeed/deAcc));
  //cerr<<maxAccDist<<' '<<maxDeAccDist<<' '<<maxAccDist+maxDeAccDist<<' '<<dist<<'\n';
  double ta=sqrt(dist/(acc/2.0+(deAcc/2.0)*(acc/deAcc)*(acc/deAcc)));//timp in care accelerez
  double tb=(acc*ta)/deAcc;//timp in care deaccelerez
  //cerr<<ta<<' '<<tb<<' '<<ta+tb+(dist-maxAccDist-maxDeAccDist)/maxSpeed<<'\n';
  if(dist>=maxAccDist+maxDeAccDist) {
    double dinit=dist;
    dist=maxAccDist+maxDeAccDist;
    ta=sqrt(dist/(acc/2.0+(deAcc/2.0)*(acc/deAcc)*(acc/deAcc)));//timp in care accelerez
    tb=(acc*ta)/deAcc;//timp in care deaccelerez
    return (ta+(dinit-maxAccDist-maxDeAccDist)/maxSpeed+tb)*1000;
  }else {
   // cerr<<"aici";
    return (ta+tb)*1000;
  }
}

vector<LL> proc(vector<pair<LL,pair<LL,LL> > > v) {
  double tot=0;
  LL lstart=0;
  vector<LL> rez;
  for(int i=0; i<v.size(); ++i) {
    LL start=v[i].y.x,target=v[i].y.y,timestamp=v[i].x;
   // cerr<<start<<' '<<target<<' '<<timestamp<<'\n';
    if(tot<timestamp) tot=timestamp;
    tot+=time(acc,ms,da,abs(start-lstart)*LHEIGHT);
    tot=ceil(tot);
    tot+=time(acc,ms,da,abs(target-start)*LHEIGHT);
    tot=ceil(tot);
    rez.push_back(tot);
    lstart=target;
  }
  return rez;
}

void l3(char in[],char out[]) {
  LL nreq,ne,elev[105],time[105][105],mi[105],ma[105],first[105],rez[105];
  ifstream f(in);
  ofstream g(out);
  f>>ne;
  for(int i=1; i<=ne; ++i) {
    f>>mi[i]>>ma[i]; elev[i]=mi[i];
    for(int j=1; j<=100; ++j) f>>time[i][j];
    first[i]=0;
  }
  multiset <pair<per,per> > v;
  f>>nreq;
  for(int i=1;i<=nreq;++i) {
    rez[i]=0;
    LL start,goal,timestamp;
    f>>start>>goal>>timestamp;
    v.insert(mp(mp(timestamp,i),mp(start,goal)));
  }
  //sort(v.begin(),v.end());
  for(;v.size();) {
      LL start=v.begin()->y.x,end=v.begin()->y.y,timestamp=v.begin()->x.x,ind=v.begin()->x.y;
      LL cl=start,ct=timestamp;
      for(int i=1; i<5; ++i)
        if((cl<ma[i] && cl>mi[i]) || (cl==ma[i] && end<ma[i]) || (cl==mi[i] && end>mi[i])) {
          ct=max(ct,first[i])+time[i][abs(elev[i]-cl)];
          int nxt=min(ma[i],max(end,mi[i]));
          ct+=time[i][abs(nxt-cl)];
          elev[i]=nxt; cl=nxt;
          first[i]=ct;
          break;
        }
      v.erase(v.begin());
      if(end!=cl) v.insert(mp(mp(ct,ind),mp(cl,end)));
      else {
        rez[ind]=ct;
      }
  }
  for(int i=1; i<=nreq; ++i) g<<rez[i]<<' ';
}

void l4(char in[],char out[]) {
  ifstream f(in); ofstream g(out);
  LL stoptime,time[405],n;
  time[0]=0;
  LL start[555],end[555],ts[555],d[555],tmin=(1LL<<60),imin,rezolvate=0,cl=0,ct=0,r[555],dir=0;//1 pentru sus -1 pentru jos
  f>>stoptime;
  for(int i=1; i<=400; ++i) f>>time[i];
  f>>n;

  for(int i=1; i<=n; ++i) {
    f>>start[i]>>end[i]>>ts[i];
    if(start[i]<end[i]) d[i]=1;
    else d[i]=0;
    r[i]=0;
    if(tmin>ts[i]) {
      tmin=ts[i];
      imin=i;
    }
  }
  int ok=1;
  for(;rezolvate<n;) {
    if(ok) {
      for(int i=1; i<=n; ++i) if(!r[i] && dir==d[i] && start) {
      }
      ct=max(ts[imin],ct);
      ct+=time[abs(cl-start[imin])];
      ct+=time[abs(start[imin]-end[imin])];
      ++rezolvate; r[imin]=ct; cl=end[imin];
      if(start[imin]<end[imin]) dir=1;
      else dir=0;
      ok=0;
    }
    //case 1
    LL dmin=(1LL<<60); imin=-1;
    for(int i=1; i<=n; ++i)
      if(!r[i] && ts[i]<=ct && d[i]==dir && ((dir==1 && start[i]>=cl) || (dir==0 && start[i]<=cl)) && dmin>abs(start[i]-cl)) {
        dmin=abs(start[i]-cl);
        imin=i;
      }
    if(imin!=-1) {
      ok=1;
      continue;
    }
    //case 2
    LL high=-1,low=500;
    for(int i=1; i<=n; ++i)
      if(!r[i] && ts[i]<=ct && d[i]!=dir) {
        if(dir==1 && start[i]>high) {
          high=start[i];
          imin=i;
        }else if(dir==0 && start[i]<low) {
          low=start[i];
          imin=i;
        }
      }
    if(imin!=-1) {
      ok=1;
      continue;
    }
    //case 3
   // cerr<<imin<<' '<<r[3]<<' '<<d[3]<<' '<<dir<<' '<<cl<<' '<<start[3]<<' '<<ts[3]<<' '<<ct<<'\n';
    for(int i=1; i<=n; ++i) if(!r[i] && ts[i]<=ct && d[i]==dir) {
      if( high<abs(cl-start[i])) {
        high=abs(cl-start[i]);
        imin=i;
      }
    }
    if(imin!=-1)  {
      ok=1;
      continue;
    }
    if(imin==-1 && rezolvate<n) {
      //cerr<<in<<rezolvate<<"aici\n";
      LL tmin=(1LL<<60);
      //cerr<<tmin<<'\n';
      for(int i=1; i<=n; ++i) if(!r[i] && tmin>ts[i]) {
        tmin=ts[i];
        imin=i;
      }
      //cerr<<rezolvate<<' '<<tmin<<'\n'; while(1);
      ct=tmin; imin=-1;
    //  cerr<<imin<<' ';
    }
  }
  for(int i=1; i<=n; ++i) g<<r[i]<<' ';
}

void solve(char in[],char out[]) {
  ifstream f(in);
  ofstream g(out);
 // cerr<<in<<' '<<out<<'\n';
  f>>acc>>ms>>da;
  int n; f>>n;
  vector<pair<LL,pair<LL,LL> > > v;
  for(int i=1; i<=n; ++i) {
    int start,target,timestamp;
    f>>start>>target>>timestamp;
    v.push_back(make_pair(timestamp,make_pair(start,target)));
  }
  sort(v.begin(),v.end());
  vector<LL> r=proc(v);
  for(int i=0; i<r.size(); ++i) g<<r[i]<<' ';

}

int main()
{
    for(int i=1; i<=6; ++i) {
      char in[55],out[55];
      sprintf(in,"%d.txt",i);
      sprintf(out,"%d.out",i);
      l4(in,out);
    }
    return 0;
}
