#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int t,lst[]={0,1,4,7,6,5,6,3,6,9},sum[105];
string s;

int main()
{
    ifstream f("cifra.in");
    ofstream g("cifra.out");
    int sm=0;
    for(int i=1; i<=100; ++i) {
        int put=i%4;
        if(!put) put=4;
        sm+=int(pow(i%10,put))%10;
        sm%=10;
        sum[i]=sm;
    }
    for(f>>t;t;--t) {
        f>>s;
        int num=s[s.size()-1]-'0';
        if(s.size()>1) num+=10*(s[s.size()-2]-'0');
        g<<sum[num]<<'\n';
    }
    return 0;
}
