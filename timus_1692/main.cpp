#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> s[50];
int n,k;

int main()
{
    cin>>n;
    int dlt=1+8*n,ind=1;
    int x1=floor((1.0+sqrt((double)dlt))/2.0);
    int x2=floor((1.0-sqrt((double)dlt))/2.0);
    k=max(x1,x2);
    cout<<k<<'\n';
    for(int i=1; i<k; ++i) for(int j=i+1; j<=k; ++j) s[i].push_back(ind),s[j].push_back(ind),++ind;
    for(int i=1; i<=k; ++i) {
        cout<<k-1<<' ';
        for(int j=0; j<k-1; ++j) cout<<s[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
