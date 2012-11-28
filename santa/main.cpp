#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#define DN 45005
using namespace std;

typedef vector<int>::iterator it;
typedef pair<int,int> per;

int n,m,sus[DN],niv[DN],nrc,unde[DN];
vector<int> gr[DN],arb[20*DN];
stack<per> st;
vector<vector<int> > bi;

bool isc[DN];
bool bun[20*DN];//pot ajunge in arbore in d din nodul i
bitset<20*DN> viz;

int s,e,q;

void makeCon(int a, int b) {
    int x=-1,y=-1;
    vector<int> cc;
    for(;x!=a && y!=b;) {
        x=st.top().first;
        y=st.top().second;
        unde[x]=unde[y]=nrc;
        st.pop();
        cc.push_back(x);
        cc.push_back(y);
    }
    sort(cc.begin(),cc.end());
    cc.erase(unique(cc.begin(),cc.end()),cc.end());
    bi.push_back(cc);
}

void dfs(int s,int f,int lev) {
    sus[s]=niv[s]=lev;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) {
        if(*i==f) continue;
        if(!niv[*i]) {
            st.push(make_pair(s,*i));
            dfs(*i,s,lev+1);
            sus[s]=min(sus[s],sus[*i]);
            if(niv[s]<=sus[*i]) {
                ++nrc;
                makeCon(s,*i);
                isc[s]=1;
            }
        }else sus[s]=min(sus[s],niv[*i]);
    }
}

void farb() {
    for(int i=1; i<=n; ++i) if(isc[i]) {
        viz&=0;
        for(int j=0; j<gr[i].size(); ++j) {
            if(!viz[unde[gr[i][j]]] && !isc[gr[i][j]]) {
                int k=unde[gr[i][j]];
                viz[k]=1;
                arb[i+m].push_back(k);
                arb[k].push_back(i+m);
                //cout<<i+m<<' '<<k<<'\n';
            }
            if(!viz[gr[i][j]+m] && isc[gr[i][j]]) {
                viz[gr[i][j]+m]=1;
                arb[i+m].push_back(gr[i][j]+m);
                arb[gr[i][j]+m].push_back(i+m);
            }
        }
    }
    viz&=0;
}

int parc(int s,int f) {
    cout<<s<<' '<<f<<'\n';
    if((isc[s-m] && s-m==e) || s==unde[e]) {
        bun[s]=1;
        return 1;
    }
    for(it i=arb[s].begin();i!=arb[s].end(); ++i) if(f!=*i) {
        if(parc(*i,s)) bun[s]=1;
    }
    return bun[s];
}

bitset<DN> fol;//am folosit nodul i in back
vector<int> ham,soltot;

void back(int lst,int comp,int fin) {
    if(ham.size()==bi[comp-1].size() && fin==ham[ham.size()-1]) {
        for(int i=0; i<ham.size(); ++i) soltot.push_back(ham[i]);
        return;
    }
    for(it i=gr[lst].begin(); i!=gr[lst].end(); ++i)
        if(!fol[*i] && (unde[*i]==comp || isc[*i])){
            ham.push_back(*i);
            fol[*i]=1;
            back(*i,comp,fin);
            fol[*i]=0;
            ham.pop_back();
        }
}

void makeHam(int first, int last,int comp) {
    ham.push_back(first);
    fol&=0;
    fol[first]=1;
    back(first,comp,last);
}

//tot timpul ma aflu intr-o componenta
void dute(int s,int nod) {//parcurg arborele din q spre d sau s, nod e nodul pe unde intrii in comp
    //cout<<s<<' ';
    viz[s]=1;
    for(it i=arb[s].begin(); i!=arb[s].end(); ++i) if(bun[*i]) {
        makeHam(nod,*i-m,s);
        for(it j=arb[*i].begin();j!=arb[*i].end(); ++j) if(bun[*j] && !viz[*j]) {
            dute(*j,*i-m);
            return;
        }
    }
}

int main()
{
    ifstream f("santa.in");
    ofstream g("santa.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,0,1);

    farb();
    for(int i=0; i<bi.size(); ++i) {
        for(int j=0; j<bi[i].size(); ++j) cout<<bi[i][j]<<' ';
        cout<<'\n';
    }
    f>>s>>e>>q;
    if(unde[s]==unde[q] || unde[e]==unde[q]) {
        if(isc[s]) parc(s+m,0);
        else parc(unde[s],0);
    }
    if(isc[q]) {
        for(it i=arb[q+m].begin(); i!=arb[q+m].end(); ++i) if(bun[*i]) {
            dute(*i,q);
            break;
        }
    }else {
        dute(q+m,q);
    }
    for(int i=0; i<=100; ++i) if(bun[i]) cout<<i<<' ';
    g<<soltot.size()<<'\n';
    for(int i=0; i<soltot.size(); ++i) g<<soltot[i]<<' ';
    return 0;

}
