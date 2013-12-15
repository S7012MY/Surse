#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n;
string s,rez;

int main() {
	ifstream f("crypt.in");
	ofstream g("crypt.out");
	f>>n;
	f.get();
	for(int k=0; k<n; ++k) {
		getline(f,s);
		rez=s;
		int lg=s.size();
		int dif=(lg*(lg+1))/2-1;
		for(int i=0; i<s.size(); ++i) {
			int nr=((s[i]+256)%256)&i;
			nr=(~nr)&i;
			nr<<=1;
			rez[i]=(256+rez[i]-dif+nr)%256;
		}
		g<<rez<<'\n';
	}
	return 0;
}