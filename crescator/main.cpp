#include <fstream>
using namespace std;

int n,bst,lgc,cnt,nc,np=-1;

int main()
{
    ifstream f("crescator.in");
    ofstream g("crescator.out");
    for(f>>n;n--;) {
        f>>nc;
        if(nc>np) ++lgc;
        else {
            bst=max(bst,lgc);
            cnt+=((lgc+1)*lgc)>>1;
            lgc=1;
        }
        np=nc;
    }
    cnt+=((lgc+1)*lgc)>>1;
    bst=max(bst,lgc);
    g<<cnt<<' '<<bst;
    return 0;
}
