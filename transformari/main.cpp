#include <fstream>
#define M 100000000
using namespace std;

int t(int n, int k) {
    if(1==k) return n-1;
    if(0==k) return M;
    return n/k+t(k,n%k);
}

int main()
{
    ifstream f("transformari.in");
    ofstream g("transformari.out");
    int n,bst=M;
    f>>n;
    for(int i=2; i<n; ++i) bst=min(bst,t(n,i));
    g<<bst;
    return 0;
}
