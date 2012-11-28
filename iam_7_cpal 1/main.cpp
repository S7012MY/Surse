#include <iostream>
#include <fstream>
using namespace std;

int fr[55];

int main()
{
    ifstream f("cpal.in");
    ofstream g("cpal.out");
    for(int i=1; i<=10; ++i) {
        int ok=0,lg=0;
        for(int i=1; i<=9; ++i) {
            f>>fr[i];
            lg+=fr[i];
            ok+=(fr[i]&1);
        }
        if(ok<2 && (lg&1) && lg) g<<"1\n";
        else if(ok<1 && lg) g<<"1\n";
        else g<<"0\n";
    }
    return 0;
}
