#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char mp[1005],fol[1005];
int idx,t;
string inp;

int main() {
    ifstream f("inp.txt");
	ofstream g("out.txt");
    f>>t;
    f.get();
    mp['a']='y';
    mp['b']='n';
    mp['c']='f';
    mp['d']='i';
    mp['e']='c';
    mp['f']='w';
    mp['g']='l';
    mp['h']='b';
    mp['i']='k';
    mp['j']='u';
    mp['k']='o';
    mp['l']='m';
    mp['m']='x';
    mp['n']='s';
    mp['o']='e';
    mp['p']='v';
    mp['q']='z';
    mp['r']='p';
    mp['s']='d';
    mp['t']='r';
    mp['u']='j';
    mp['v']='g';
    mp['w']='t';
    mp['x']='h';
    mp['y']='a';
    mp['z']='q';
	mp[' ']=' ';
	//for(char i='a'; i<='z'; ++i) fol[mp[i]]=1;
	//for(char i='a'; i<='z'; ++i) if(!fol[i]) cout<<i;
	
    for(int i=1;i<=t; ++i) {
        getline(f,inp);
		//cout<<inp;
        string out;
        for(int i=0; i<inp.size(); ++i) {
			char cc=inp[i];
			if(cc==' ') {
				out+=' ';
				continue;
			}
			for(char j='a'; j<='z'; ++j) if(mp[j]==cc) {
				out+=j;
				break;
			}
		}
        g<<"Case #"<<i<<": "<<out<<'\n';
    }
}
