#include <iostream>
#define DN 55
using namespace std;

int na,ma,nb,mb,bst=-1,bx,by;
char m1[DN][DN],m2[DN][DN];

int main()
{
    cin>>na>>ma;
    for(int i=1; i<=na; ++i) cin>>m1[i]+1;
    cin>>nb>>mb;
    for(int i=1; i<=nb; ++i) cin>>m2[i]+1;
    for(int x=-200; x<=200; ++x) for(int y=-200; y<=200; ++y) {
        int sum=0;
        for(int i=1; i<=na && i+x<=nb; ++i) for(int j=1; j<=ma && j+y<=mb; ++j)
            if(i+x>0 && j+y>0)
                sum+=((m1[i][j]-'0')*(m2[i+x][j+y]-'0'));
        if(sum>bst) {
            bx=x; by=y;
            bst=sum;
        }
    }
   //cerr<<bst<<'\n';
    cout<<bx<<' '<<by;
    return 0;
}
