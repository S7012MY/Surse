#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char mp[1005];
int idx,t;
string inp;

int main() {
    ifstream f("inp.in");
    f>>t;
    f.get();
    mp['a']='y';
    mp['b']='n';
    mp['c']='y';
    mp['d']='y';
    mp['e']='y';
    mp['f']='y';
    mp['g']='y';
    mp['h']='y';
    mp['i']='y';
    mp['j']='y';
    mp['k']='y';
    mp['l']='y';
    mp['m']='y';
    mp['n']='y';
    mp['o']='e';
    mp['p']='y';
    mp['q']='y';
    mp['r']='p';
    mp['s']='y';
    mp['t']='y';
    mp['u']='j';
    mp['v']='y';
    mp['w']='y';
    mp['x']='y';
    mp['y']='y';
    mp['z']='q';
    for(int i=1;i<=t; ++i) {
        getline(f,inp);
        string out;
        for(int i=0; i<inp.size(); ++i) out+=mp[inp[i]];
        cout<<"Case #1: "<<out<<'\n';
    }
}
