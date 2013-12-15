#include <iostream>
#include <set>
using namespace std;

int n;
set<int> s;

int main()
{
    for(int i=0; i<4;++i) {
        cin>>n;s.insert(n);
    }
    cout<<4-s.size();
    return 0;
}
