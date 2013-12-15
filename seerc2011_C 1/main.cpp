#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

string a,b;
int t,pot[1000][100],rez[1000005],sr;

int main()
{
    for(cin>>t;t;--t) {
        int gok=0;
        cin>>a>>b;
        int sz=-1;
        for(int i=0; i<a.size(); ++i)
            if(isalpha(a[i])) pot[++sz][a[i]-'A']=1;
            else if(a[i]=='[') {
                ++i;
                ++sz;
                for(;a[i]!=']';pot[sz][a[i]-'A']=1,++i);
            }
            else if(a[i]=='{') {
                ++i;
                ++sz;
                for(char c='A'; c<='z'; ++c) pot[sz][c-'A']=1;
                for(;a[i]!='}';pot[sz][a[i]-'A']=0,++i);
            }else {
                ++sz;
                for(char c='A'; c<='z'; ++c) pot[sz][c-'A']=1;
            }
        for(int j=0; j+sz-1<b.size(); ++j) {
            int ok=1;
            for(int i=0; i<=sz; ++i) if(!pot[i][b[j+i]-'A']) {
                ok=0;
                break;
            }
            if(sz+j>=b.size()) ok==0;
            if(ok) rez[++sr]=j+1;
        }
        if(!sr) cout<<"no match";
        else {
            for(int i=1; i<sr; ++i) cout<<rez[i]<<' ';
            cout<<rez[sr]<<'\n';
        }
        sr=0;
        memset(pot,0,sizeof(pot));
    }
    return 0;
}
