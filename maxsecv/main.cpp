#include <fstream>
using namespace std;

int n,ec,ep,m1,m2,cons;

int main()
{
    ifstream f("maxsecv.in");
    ofstream g("maxsecv.out");
    f>>n>>ep;
    if(ep) ++cons;
    for(int i=1; i<n; ++i) {
        f>>ec;
        if(ec) ++cons;
        else {
            if(m1<=cons) {
                m2=m1;
                m1=cons;
            }else if(m2<cons) m2=cons;
            cons=0;
        }
    }
    if(m1<=cons) {
        m2=m1;
        m1=cons;
    }else if(m2<cons) m2=cons;
    g<<m1+m2;
    return 0;
}
