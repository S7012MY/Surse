#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#define DN 100005
using namespace std;

string z=" ";
vector<string> cuv;
char a[DN],b[DN];
int pi[DN],n,m;
vector<pair<int, int> > pot;

void p() {
    for(int i=0; i<=z.size(); ++i) pi[i]=0;
    for(int i=2,q=0; i<z.size(); ++i) {
        for(;q!=0 && z[i]!=z[q+1];q=pi[q]);
        if(z[i]==z[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    fgets(a+1,DN,stdin);
    fgets(b,DN,stdin);
    n=strlen(a+1); m=strlen(b);
    for(int i=0; i<m; ++i) {
        if(isalpha(b[i])) z+=b[i];
        else {
            if(z.size()>1) {
                cuv.push_back(z);
                z.clear();z+=' ';
            }
        }
    }
    int lst=0;
    for(int in=0; in<cuv.size(); ++in) {
        z=cuv[in];p();
        int sz=z.size()-1;
        for(int i=lst+1,q=0; i<=n; ++i) {
            for(;q!=0 && a[i]!=z[q+1];q=pi[q]);
            if(a[i]==z[q+1]) ++q;
            if(q==sz) {
                int ptr=i-sz+1;
                //printf("Potrivire la %d %d\n",ptr,i);
                if(ptr>lst) {
                    pot.push_back(make_pair(ptr,i));
                    lst=i+1;
                    break;
                }
            }
            if(i==n) {
                printf("I HAVE FAILED!!!");
                return 0;
            }
        }
    }
    int ic=0;
    for(int i=1; i<n; ++i) {
        if(i>pot[ic].second && ic+1<pot.size()) ++ic;
        if(' '==a[i] || (pot[ic].first<=i && i<=pot[ic].second)) printf("%c",a[i]);
        else printf("_");
    }
    return 0;
}
//0733190469
//str pitesti rest la china 14
