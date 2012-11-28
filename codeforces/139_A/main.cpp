#include <iostream>
using namespace std;

int n,top,a,b,down,fol[10];

int main()
{
    cin>>n>>top;
    top=7-top;
    for(int i=1; i<=n; ++i) {
        cin>>a>>b;
        fol[1]=fol[2]=fol[3]=fol[4]=fol[5]=fol[6]=0;
        fol[a]=fol[b]=fol[7-a]=fol[7-b]=1;
        int ok=0;
        for(int j=1; j<=6; ++j) if(!fol[j] && j!=top) ++ok;
        if(ok>1) {
            cout<<"NO";
            return 0;
        }
        top=7-top;
    }
    cout<<"YES";
    return 0;
}
