#include <iostream>
#define zeros(x) (((x)^((x)-1))&(x))
#define DN 100005
using namespace std;

int seq[6][DN]
int n,v[DN],aib[6][13][DN];

void update(int a,int b,int vl,int s) {

}

int main()
{
    cin>>n;
    for(int j=1; j<6; ++j) for(int i=1; i<=n; ++i) {
        seq[j][i]=i%(2*j);
        if(!seq[j][i]) {
            seq[j][i]=2;
            continue;
        }
        if(seq[j][i]>(j+1)) seq[j][i]=(2*(j+1))-seq[j][i];
    }
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        for(int j=1; j<6; ++j) for(int inc=0; inc<=10; ++inc)
            update(j,inc,v[i],seq[j][inc+1]);
    return 0;
}
