#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int n,vl[10],unde[10]={0,1,2,3,4,5};
string inp;

int main() {
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>inp;
        if(inp.size()==12) {
            cout<<vl[unde[inp[8]-'a']]<<'\n';
        }
        else {
            if(inp[1]==':') {
                unde[inp[0]-'a']=unde[inp[3]-'a'];
            }
            int und=unde[inp[0]-'a'];
            int i;
            for(i=0; inp[i]!='=';++i);
            ++i;
            if(isalpha(inp[i])) vl[und]=vl[unde[inp[i]-'a']];
            else vl[und]=inp[i]-'0';
        }
        //cout<<vl[0]<<' '<<vl[1]<<' '<<vl[2]<<' '<<vl[3]<<'\n';
    }
}
