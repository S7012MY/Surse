//#include <iostream>
//#include <cmath>
//#include <cstdlib>
//#define x first
//#define y second
//#define PI 3.14159265359
//using namespace std;
//
//typedef pair<double,double> per;
//typedef pair<per,per> seg;
//
//double t,x,y,r;
//per a,b,c;
//
//void edr(per p,per q,double &a,double &b,double &c) {
//  a=q.y-p.y; b=p.x-q.x; c=q.x*p.y-p.x*q.y;
//}
//
//double dist(per a,per b) {
//  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
//}
//
//bool unghi(double a,double b, double c) {
//  return acos((a-b-c)/(-2*sqrt(b)*sqrt(c)))>PI*0.5;
//}
//double pseg(seg l,per p) {
//  double a,b,c;
//  edr(l.x,l.y,a,b,c);
//  double d=fabs(a*p.x+b*p.y+c)/sqrt(a*a+b*b);
//  if(unghi(dist(p,l.x),dist(l.x,l.y),dist(l.y,p))|| unghi(dist(l.y,p),dist(p,l.x),dist(l.x,l.y)))
//     return sqrt(min(dist(l.x,p),dist(l.y,p)));
//  return d;
//}
//
//int main() {
//  for(cin>>t;t;--t) {
//    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>x>>y>>r;
//    //cout<<pseg(make_pair(a,b),make_pair(x,y));
//    if(pseg(make_pair(a,b),make_pair(x,y))<=r || pseg(make_pair(b,c),make_pair(x,y))<=r || pseg(make_pair(c,a),make_pair(x,y))<=r)
//      cout<<"YES\n";
//    else cout<<"NO\n";
//  }
//}
