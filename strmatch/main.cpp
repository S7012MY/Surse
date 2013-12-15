#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MOD 666013
#define MOD2 100007
#define BASE 31
using namespace std;

string a,b;
int A,B,put=1,putp=1;
int Ap,Bp;
vector<int> sol;

int hs(string a,int md) {
    int A=0;
    for(int i=0; i<a.size(); ++i) A=(A*BASE+a[i]-'A')%md;
    return A;
}

int main()
{
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    f>>a>>b;
    int sz=a.size();
    A=hs(a,MOD);
    Ap=hs(a,MOD2);
    for(int i=0; i<sz; ++i) {
        B=(B*BASE+b[i]-'A')%MOD;
        Bp=(Bp*BASE+b[i]-'A')%MOD2;
        if(i) {
            put=(put*BASE)%MOD;
            putp=(putp*BASE)%MOD2;
        }
    }
    for(int i=sz; i<b.size(); ++i) {
        B=(B-(b[i-sz]-'A')*put+MOD)%MOD;
        B=(B*BASE+b[i]-'A')%MOD;
        Bp=(Bp-(b[i-sz]-'A')*putp+MOD2)%MOD2;
        Bp=(Bp*BASE+b[i]-'A')%MOD2;
        //cout<<B<<' ';
        if(B==A && Bp==Ap) sol.push_back(i);
    }
    g<<sol.size()<<'\n';
    for(int i=0; i<sol.size();++i) g<<sol[i]-sz+1<<' ';
    return 0;
}
