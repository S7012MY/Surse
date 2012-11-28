#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>
#include <vector>
#include <queue>
#define DN 5005
using namespace std;

int n,dist[DN]={0,1};
char c[DN];

typedef vector<int>::iterator it;

vector<int> gr[DN];
queue<int> q;

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

int main() {
	ifstream f("pali.in");
	ofstream g("pali.out");
	f.getline(c+1,DN);
	//f>>c+1;
	n=strlen(c+1);
	for(int i=1; i<=n; ++i) {
		//dist[i]=n;
		gr[i].push_back(i+1);
		for(int lg=1; i-lg>0 && i+lg<=n; ++lg) {
            if(c[i-lg]!=c[i+lg]) break;
            gr[i-lg].push_back(i+lg+1);
		}
		for(int lg=0; i-lg>0 && i+lg+1<=n; ++lg) {
		    if(c[i-lg]!=c[i+lg+1]) break;
		    gr[i-lg].push_back(i+lg+2);
		}
	}
	for(q.push(1);q.size();q.pop()) {
		int fr=q.front();
		for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(!dist[*i]) {
			dist[*i]=dist[fr]+1;
			q.push(*i);
			if(*i==n+1) {
				g<<dist[n+1]-1;
				return 0;
			}
		}
	}
	g<<dist[n+1]-1;
}
