#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define DN 8000
using namespace std;

//impart random copiii
//si pe urma ii grupez a. i. sa nu fie antipatii
typedef vector<int>::iterator it;
int n,unde[DN],cont[2];
vector<int> gr[DN];

int main()
{
    srand(time(NULL));
    cin>>n;
    for(int i=0; i<n; ++i) {
        int dim,f;
        cin>>dim;
        for(int j=0; j<dim; ++j) {
            cin>>f;
            gr[i].push_back(f-1);
        }
        unde[i]=rand()&1;
        ++cont[unde[i]];
    }
    int pasi=0;
    for(int i=1; ;i=(i+1)%n) {
        int nra=0;
        for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(unde[i]==unde[*j]) ++nra;
        if(nra>1) {
            --cont[unde[i]];
            unde[i]=1^unde[i];
            pasi=0;
            ++cont[unde[i]];
        }
        ++pasi;
        if(pasi==n) {
            if(cont[0]<cont[1]) {
                cout<<cont[0]<<'\n';
                for(int i=0; i<n; ++i) if(unde[i]==0) cout<<i+1<<' ';
            }else if(cont[0]>cont[1]) {
                cout<<cont[1]<<'\n';
                for(int i=0; i<n; ++i) if(unde[i]==1) cout<<i+1<<' ';
            }else {
                cout<<cont[unde[1]]<<'\n';
                for(int i=0; i<n; ++i) if(unde[i]==unde[0]) cout<<i+1<<' ';
            }
            return 0;
        }
    }
    return 0;
}
