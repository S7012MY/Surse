#include <iostream>
#include <fstream>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cassert>
#define DN 15005
#define DM 200005
#define x first
#define y second
using namespace std;
using namespace tr1;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int t,n,m,st[DM],sz;

vector<per> gr[DN];
vector<int> gi[DN];
unordered_map<int,int> culoare;
unordered_map<int,int> fr;
int cind[DM];
int s1,d1;
per muc[DM];

    ifstream f("ulei.in");
	ofstream g("ulei.out");


int mp(int a, int b) {
    return a*DN+b;
}

void fap(int s) {
    //asta ii buna
    fr.clear();
    for(it i=gi[s].begin(); i!=gi[s].end(); ++i) {
        if(fr.find(cind[*i])!=fr.end()) ++fr[cind[*i]];
        else fr[cind[*i]]=1;
    }
    vector<pair<int,per> >c;
    c.clear();
    for(it i=gi[s].begin(); i!=gi[s].end(); ++i) {
        int cul=cind[*i];
        c.push_back(make_pair(fr[cul],make_pair(cul,*i)));
    }
    sort(c.begin(),c.end());
    int sz=c.size()/2;
    for(int i=0; i<sz; ++i) {
        int i1=c[i].y.y,i2=c[i+sz].y.y;
        gr[s].push_back(make_pair(i1,i2));
    }
}

bool stergeM(int n,int x) {
    for(it i=gr[n].begin(); i!=gr[n].end(); ++i) if(i->x==x) {
        gr[n].erase(i);
        return 1;
    }
    return 0;
}

int li[DN];

void euler(int s,){
    //cout<<a<<' '<<s<<' '<<b<<'\n';
    //cout.flush();
    if(stergeM(s,b) && stergeM(b,s)) euler(s,b,perNod[mp(s,b)]);

    for(li[s]=max(0,li[s]);li[s]<gr[s].size(); ++li[s]) {
        int i=li[s];
        int x=gr[s][i].x,cl=gr[s][i].y;
        int c1=culoare[mp(a,s)],c2=culoare[mp(s,b)],
        c3=culoare[mp(s,x)],c4=culoare[mp(x,perNod[mp(x,s)])];

        if(c1==c3 || c2==c4) x=perNod[mp(x,s)];
        stergeM(s,x);
        stergeM(x,s);
        --li[s];
        euler(s,x,perNod[mp(s,x)]);
    }
    st[++sz]=s;
}

int main()
{
	for(f>>t;t;--t) {
	    f>>n>>m;
        //cout<<'\n';
	    for(int i=0; i<m; ++i) {
	        int a,b,c;
	        f>>a>>b>>c;
	        muc[i]=make_pair(a,b);
	        muc[i+m]=make_pair(b,a);
	        cind[i]=cind[i+m]=c;
	        gi[a].push_back(i);
	        gi[b].push_back(i+m);
	        culoare[mp(a,b)]=culoare[mp(b,a)]=c;
	    }
	    for(int i=1; i<=n; ++i) fap(i);

	    euler(1,gr[1].front(),gr[1].front());
	    for(int i=sz; i; --i) g<<st[i]<<' ';
	    g<<'\n';

	    for(int i=1; i<=n; ++i) {
	        li[i]=0;
	        gi[i].clear();
	    }
	    culoare.clear();
	    perNod.clear();
	    s1=0;
	    sz=0;
	}
    return 0;
}
