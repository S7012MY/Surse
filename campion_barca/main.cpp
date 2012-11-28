#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("barca.in");
    ofstream g("barca.out");
    int n;
    f>>n;
    g<<4*n<<'\n';
    for(int i=1; i<=n; ++i) g<<"IG\nI\n"<<i<<"\nG\n";
    return 0;
}
