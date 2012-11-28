#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("capete.in");
    ofstream g("capete.out");
    int n;
    f>>n;
    //for(int i=1; i<=n; ++i) sol+=5;
    g<<5*n;
    //cout<<sol;
    return 0;
}
