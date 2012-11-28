#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int sum(char a) {
    if(isalpha(a)) return a-'A'+10;
    return a-'0';
}

int main()
{
    string inp;
    getline(cin,inp);
    int s=0,md=0;
    for(int i=0; i<inp.size(); ++i) if(isalnum(inp[i])) {
        s+=sum(inp[i]);
        md=max(md,sum(inp[i]));
    }
    if(36>=s+1)cout<<s+1;
    else cout<<"No solution.";
}
