#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#define EPS 1e-5
using namespace std;


int main() {
  ifstream f1("balance.out");
  ifstream f2("output.txt");
  double r1,c1,r2,c2;
  while(f1>>r1>>c1 && f2>>r2>>c2) {
    cerr<<fixed<<setprecision(9)<<r1<<' '<<c1<<'\n'<<r2<<' '<<c2<<'\n';
    if(/*fabs(r1-r2)>EPS ||*/ fabs(c1-c2)>EPS) {
      cerr<<r1<<' '<<c1<<' '<<r2<<' '<<c2<<"greseala!!!";
      while(1);
    }
  }
}
