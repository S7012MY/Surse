#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream g("date2.in");
    g<<"1000\n";
    for(int i=1; i<=1000; ++i) {
        cout<<i<<'\n';
        int n=rand()%500000;
        g<<n<<'\n';
        for(int i=1; i<=n; ++i) {
            int a=rand()%1000;
            int b=rand()%(1000-a)+a;
            g<<a<<' '<<b<<'\n';
        }
    }
    return 0;
}
