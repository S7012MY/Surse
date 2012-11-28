#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

vector<double> s;

int main()
{
    int inp;
    for(;cin>>inp;s.push_back(sqrt((double)inp)));
    for(int i=s.size()-1; 0<=i;--i) cout<<fixed<<setprecision(5)<<s[i]<<'\n';
    return 0;
}
