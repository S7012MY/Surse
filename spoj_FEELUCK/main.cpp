#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string>::iterator is;

int main()
{
    vector<string> s;
    int t;
    cin>>t;
    for(int tt=1;tt<=t;++tt) {
        string inp;
        s.clear();
        int r,br=0;
        for(int i=1; i<=10; ++i) {
            cin>>inp>>r;
            if(br<r) {
                br=r;
                s.clear();
                s.push_back(inp);
            }else if(br==r) s.push_back(inp);
        }
        cout<<"Case #"<<tt<<":\n";
        for(is i=s.begin();i!=s.end(); ++i) cout<<(*i)<<'\n';
    }
    return 0;
}
