#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int t,fr[2][26];
string tx[2];

int main()
{
    ifstream f("joben.in");
    ofstream g("joben.out");
    for(f>>t;t;--t) {
        for(int i=0; i<2; ++i) {
            f>>tx[i];
            for(int j=0;j<tx[i].size(); ++j) ++fr[i][tx[i][j]-'a'];
            sort(fr[i],fr[i]+26);
        }
        int ok=1;
        for(int i=0; i<26; ++i) {
            if(fr[0][i]!=fr[1][i]) ok=0;
            fr[0][i]=fr[1][i]=0;
        }
        if(ok) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
