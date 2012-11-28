#include <iostream>
#include <string>
using namespace std;

string z;
int lst,rez,nrd,nri,sz;

int main()
{
    cin>>z;
    for(int i=0; i<z.size(); ++i)
        if('('==z[i]) ++nrd;
        else ++nri;
    if(nrd!=nri) {
        cout<<0;
        return 0;
    }

    for(int i=0; i<z.size(); ++i)
        if('('==z[i]) ++sz;
        else {
            if(sz) --sz;
            else lst=i+1;
        }
    sz=0;
    for(int i=lst; i<z.size(); ++i) {
        if('('==z[i]) ++sz;
        else --sz;
        if(0==sz) ++rez;
    }
    for(int i=0; i<=lst; ++i) {
        if('('==z[i]) ++sz;
        else --sz;
        if(0==sz) ++rez;
    }
    cout<<rez;
    return 0;
}
