#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <cstring>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
vector<per> gr[105];
vector<int> sol;
queue<int> c;
bitset<105> viz;
//       a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
int a[]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0},n;
string s,cuv,di[50005];
int dist[105],nxt[105],cc[105];

string trans(string s) {
    string ret;
    for(int i=0; i<s.size(); ++i) ret+=a[s[i]-'a']+'0';
    return ret;
}

int main()
{
    //ifstream f("a.in");
    for(cin>>s;s.compare("-1");cin>>s) {
        for(int i=0; i<=s.size(); ++i) nxt[i]=i;
        cin>>n;
        for(int i=1; i<=n;++i) {
            cin>>cuv;
            di[i]=cuv;
            cuv=trans(cuv);
            int fp=0;
            size_t found;
            for(;;) {
                found=s.find(cuv,fp);
                if(found==string::npos) break;
                gr[found].push_back(make_pair(found+cuv.size(),i));
                //cout<<found<<' '<<found+cuv.size()<<'\n';
                fp=found+1;
            }
        }
        //cout<<'\n';
        for(c.push(0);c.size(); c.pop()) {
            for(it i=gr[c.front()].begin(); i!=gr[c.front()].end(); ++i) if(0==viz[i->x]) {
                //cout<<c.front()<<' '<<i->x<<' '<<i->y<<'\n';
                nxt[i->x]=c.front();
                cc[i->x]=i->y;
                viz[i->x]=1;
                c.push(i->x);
                dist[i->x]=dist[c.front()]+1;
            }
            viz[c.front()]=1;
        }
        if(0==dist[s.size()]) cout<<"No solution.";
        else {
            for(int c=s.size();nxt[c]!=c;c=nxt[c]) sol.push_back(cc[c]);
            for(int i=sol.size()-1; 0<=i; --i) cout<<di[sol[i]]<<' ';
        }
        cout<<'\n';
        memset(dist,0,sizeof(dist));
        for(int i=0;i<=s.size(); ++i) gr[i].clear();
        viz&=0;
    }
    return 0;
}
