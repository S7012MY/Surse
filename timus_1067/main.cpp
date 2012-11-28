#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;
set<string> s;

int main()
{
    cin>>n;
    string in;
    for(int i=0; i<n; ++i) {
        cin>>in;
        size_t pb=0;
        for(;pb!=string::npos;) {
            pb=in.find('\\');
            in[pb]=1;
            s.insert(in.substr(0,pb));
        }
    }
    int nrs;
    for(set<string>::iterator it=s.begin(); it!=s.end(); ++it) {
        nrs=0;
        in=*it;
        for(int k=0; k<in.size(); ++k) if(in[k]==1) {
            in[k]='/';
            ++nrs;
        }
        int k=in.find_last_of('/',in.size());
        if(k==string::npos) cout<<in<<'\n';
        else {
            for(int k=0; k<nrs; ++k) cout<<' ';
            cout<<in.substr(k+1,string::npos)<<'\n';
        }
    }
    return 0;
}
