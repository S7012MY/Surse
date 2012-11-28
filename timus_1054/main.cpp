#include <iostream>
using namespace std;

int n;

void hanoi(int n,int from, int to, int temp) {
    if(n>0) {
        hanoi(n-1,from,temp,to);
        cout<<n<<' '<<from<<' '<<to<<'\n';
        hanoi(n-1,temp,to,from);
    }
}

int main()
{
    cin>>n;
    hanoi(3,1,2,3);
    return 0;
}
