#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#define x first
#define y second
using namespace std;

string s;
stack<pair<char,int> > ops;
bool valid[1000005];
int lg;

int main()
{
    ifstream f("paranteze.in");
    ofstream g("paranteze.out");
    f>>lg;
    f>>s;
    int lgm=0,lgc=0;
    for(int i=0; i<s.size(); ++i) {
        if('('==s[i] || '['==s[i] || '{'==s[i]) ops.push(make_pair(s[i],i));
        else if(')'==s[i]) {
            if(ops.top().x!='(') ops.push(make_pair(s[i],i));
            else {
                valid[i]=valid[ops.top().y]=1;
                ops.pop();
            }
        }else if(']'==s[i]) {
            if(ops.top().x!='[') ops.push(make_pair(s[i],i));
            else {
                valid[i]=valid[ops.top().y]=1;
                ops.pop();
            }
        }else if('}'==s[i]) {
            if(ops.top().x!='{') ops.push(make_pair(s[i],i));
            else {
                valid[i]=valid[ops.top().y]=1;
                ops.pop();
            }
        }
    }
    lgc=lgm=0;
    for(int i=0; i<s.size(); ++i)
        if(valid[i]) ++lgc;
        else {
            lgm=max(lgm,lgc);
            lgc=0;
        }
    g<<lgm;
    cout<<lgm;
    return 0;
}
