#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,sum=0;
    string s;
    cin>>n>>s;
    if(n<4 || (s[n-1]!=s[n-2] || s[n-3]!=s[n-1])) {
        cout<<sum;
        return 0;
    }
    cout<<sum+1;
    return 0;
}
