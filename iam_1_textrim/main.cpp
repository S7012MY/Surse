#include <fstream>
#include <string>
#include <cctype>
using namespace std;

long long l[30],ls,w;
string tx,rez;

int main()
{
    ifstream f("texttrim.in");
    ofstream g("texttrim.out");
    f>>ls;
    long long lc=0;
    for(char a='a'; a<='z'; ++a) f>>l[a-'a'];
    f.get();
    getline(f,tx);
    int sz=tx.size()-1,ok=1;
    for(;' '!=tx[sz] && !isalpha(tx[sz]) && sz>=0;--sz);
    f>>w;
    for(int i=0; i<=sz; ++i) {
        if(tx[i]==' ') lc+=ls;
        else lc+=l[tx[i]-'a'];
        if(lc>w-3LL&&ok) {
            rez+="...";
            ok=0;
        }else if(ok) rez+=tx[i];
    }
    if(lc<=w) for(int i=0; i<=sz; ++i) g<<tx[i];
    else g<<rez;
    return 0;
}
