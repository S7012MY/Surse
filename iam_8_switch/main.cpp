#include <iostream>
#include <fstream>
#define LL long long
using namespace std;

int t,a[2][2],b[2][2];

int main()
{
    ifstream f("switch.in");
    ofstream g("switch.out");
    for(f>>t;t;--t) {
        f>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
        f>>b[0][0]>>b[0][1]>>b[1][0]>>b[1][1];
        int ok=0;
        for(int i=0; i<(1<<6); ++i) {
            if(i&1) {//prima linie
                a[0][0]=1-a[0][0];
                a[0][1]=1-a[0][1];
            }
            if(i&2) {//a 2-a
                a[1][0]=1-a[1][0];
                a[1][1]=1-a[1][1];
            }
            if(i&4) {//prima coloana
                a[0][0]=1-a[0][0];
                a[1][0]=1-a[1][0];
            }
            if(i&8) {//a doua
                a[0][1]=1-a[0][1];
                a[1][1]=1-a[1][1];
            }
            if(i&16) {
                a[0][0]=1-a[0][0];
                a[1][1]=1-a[1][1];
            }
            if(i&32) {
                a[1][0]=1-a[1][0];
                a[0][1]=1-a[0][1];
            }
            if(a[0][0] == b[0][0] && a[1][0] == b[1][0] && a[0][1] == b[0][1] && b[1][1] == a[1][1]) {
                ok=1;
                break;
            }
            if(i&1) {//prima linie
                a[0][0]=1-a[0][0];
                a[0][1]=1-a[0][1];
            }
            if(i&2) {//a 2-a
                a[1][0]=1-a[1][0];
                a[1][1]=1-a[1][1];
            }
            if(i&4) {//prima coloana
                a[0][0]=1-a[0][0];
                a[1][0]=1-a[1][0];
            }
            if(i&8) {//a doua
                a[0][1]=1-a[0][1];
                a[1][1]=1-a[1][1];
            }
            if(i&16) {
                a[0][0]=1-a[0][0];
                a[1][1]=1-a[1][1];
            }
            if(i&32) {
                a[1][0]=1-a[1][0];
                a[0][1]=1-a[0][1];
            }
        }
        if(ok) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
