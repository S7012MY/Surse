#include <iostream>
#define DN 100005
using namespace std;

int n,st[DN],sz,fol[DN];

int main()
{
    cin>>n;
    fol[n+1]=1;
    int lst=0;
    for(int i=1; i<=n; ++i) {
        int x;
        cin>>x;
        fol[x]=1;
        if(x>lst) {
            if(!fol[x-1]) st[++sz]=x-1;
            lst=x;
        }
        else {
            if(st[sz]!=x) {
                cout<<"Cheater";
                return 0;
            }else --sz;
            if(!fol[x-1]) st[++sz]=x-1;
        }
    }
    cout<<"Not a proof";
    return 0;
}
