#include <iostream>
using namespace std;

int x;

int main()
{
    cin>>x;
    for(int i=1; i<=10000; ++i)
        if((i*i)/2==x) {
            cout<<i;
            return 0;
        }else if((i*i)/2>x) {
            int num=(i*i)/2;
            for(;num>x;num-=2);
            if(num==x || (i&1 && num+1==x)) {
                cout<<i;
                return 0;
            }
        }
    return 0;
}
