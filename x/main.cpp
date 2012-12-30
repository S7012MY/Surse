#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string a,b;

int n,m,q;
vector<int> z,zr;

void pp() {
  string s;
  s=a+'$'+b;
}

int main()
{
    ifstream f("x.in");
    ofstream g("x.out");
    f>>n>>m>>q;
    f>>a>>b;
    pp();
    return 0;
}
