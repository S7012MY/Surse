#include <iostream>
#include <vector>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN];
int n,nrz[DN];
long long sus[DN],jos[DN];

int cmmdc(int a, int b) {
    for(int c;b;c=a%b,a=b,b=c);
    return a;
}

void dfs(int s,int f) {
    sus[s]=nrz[f]*sus[f]*(-1);
    jos[s]=nrz[s]*jos[f];
    if(sus[s]) {
        int cm=cmmdc(sus[s],jos[s]);
        if(cm<0) cm*=(-1);
        sus[s]/=cm;jos[s]/=cm;
    }else sus[s]=0,jos[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f) dfs(*i,s);
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>nrz[i];
        int nr;
        for(cin>>nr;nr!=0;cin>>nr) gr[i].push_back(nr);
    }
    int s,v;
    cin>>s;
    cin>>sus[s];
    jos[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) dfs(*i,s);
    for(int i=1; i<=n; ++i) {
        if(jos[i]) cout<<sus[i]<<'/'<<jos[i]<<'\n';
        else cout<<"0/1\n";
    }
    return 0;
}
