#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t;
string inp;
stack<char> s,out;

int prior(char op) {
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    else if(op=='^') return 3;
    else return 0;
}

int main()
{
    for(cin>>t;t;--t) {
        cin>>inp;
        for(int i=0; i<inp.size(); ++i)
            if(isalpha(inp[i])) out.push(inp[i]);
            else if(prior(inp[i])) {
                if(s.size() && prior(s.top())<prior(inp[i]))
                    for(;s.size() && prior(s.top()) && prior(s.top())<prior(inp[i]); out.push(s.top()),s.pop());
                s.push(inp[i]);
            }else if(inp[i]=='(')
                     s.push('(');
            else {
                for(;s.top()!='(';out.push(s.top()),s.pop());
                s.pop();
            }
        for(;s.size();out.push(s.top()),s.pop());
        for(;out.size();s.push(out.top()),out.pop());
        for(;s.size();cout<<s.top(),s.pop());
        cout<<'\n';
    }
    return 0;
}
