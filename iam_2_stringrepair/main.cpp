#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string a,b;
vector<int> sol;

int main()
{
    ifstream f("sr.in");
    ofstream g("sr.out");
    f>>a>>b;
    int ib=0;
    for(int i=0; i<a.size(); ++i) {
        if(a[i]==b[ib]) {
            sol.push_back(i+1);
            ++ib;
        }
    }
    for(int i=0; i<sol.size(); ++i) g<<sol[i]<<' ';
    return 0;
}
