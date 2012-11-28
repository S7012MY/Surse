#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef pair<int, pair<int, int> > ec;
int n,sz;
double sol;
per p[305];
set<ec> s;
vector<per> v[45005];

int det(per a, per b, per c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-c.x*b.y-a.x*c.y-b.x*a.y;
}

double dist(per a, per b) {
    return ((double)a.x-b.x)*((double)a.x-b.x)+((double)a.y-b.y)*((double)a.y-b.y);
}

int cmmdc(int a, int b) {
    int c;
    for(;b;c=a%b,a=b,b=c);
    return a;
}

ec dr(per a, per b) {
    int p1=a.y-b.y;
    int p2=b.x-a.x;
    int p3=a.x*b.y-b.x*a.y;
    if(p1!=0 && p2!=0 && p3!=0) {
        int cm=cmmdc(p1,p2);
        cm=cmmdc(cm,p3);
        p1/=cm; p2/=cm; p3/=cm;
    }else if(p1==0 && p2!=0 && p3!=0) {
        int cm=cmmdc(p2,p3);
        p2/=cm;p3/=cm;
    }else if(p1!=0 && p2==0 && p3!=0) {
        int cm=cmmdc(p1,p3);
        p1/=cm;p3/=cm;
    }else if(p1!=0 && p2!=0 && p3==0) {
        int cm=cmmdc(p2,p1);
        p2/=cm;p1/=cm;
    }else if(p1!=0 && p2==0 && p3==0) p1=1;
    else if(p1==0 && p2!=0 && p3==0) p2=1;
    else if(p1==0 && p2==0 && p3!=0) p3=1;
    if(p1<0) p1*=-1,p2*=-1,p3*=-1;
   // cout<<p1<<' '<<p2<<' '<<p3<<'\n';
    return make_pair(p1,make_pair(p2,p3));
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y;
    for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j) if(s.find(dr(p[i],p[j]))==s.end()) {
        ++sz;
        s.insert(dr(p[i],p[j]));
        v[sz].push_back(p[i]); v[sz].push_back(p[j]);
        for(int k=j+1; k<=n; ++k) if(0==det(p[i],p[j],p[k])) v[sz].push_back(p[k]);
    }
    for(int k=1; k<=sz; ++k) {
        double bd=0;
        for(int i=0; i<v[k].size(); ++i) for(int j=i+1; j<v[k].size(); ++j) bd=max(bd,dist(v[k][i],v[k][j]));
        //cout<<bd<<' ';
        sol+=sqrt(bd);
    }
    cout<<fixed<<setprecision(0)<<sol;
    return 0;
}
