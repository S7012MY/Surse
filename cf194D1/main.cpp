#include <iostream>
#include <cmath>
#include <vector>
#define LL long long
using namespace std;

vector<LL> p3;


int main()
{
  LL n,rez=0,p3;
    cin>>n;
  for(p3=3;n%p3==0; p3*=3LL);
  cout<<n/p3+1;
    return 0;
}
