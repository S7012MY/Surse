#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#define x first
#define y second
#define mp make_pair
#define DN 1000005
using namespace std;

typedef pair<char, int> per;
int cx[DN],cy[DN],sz;
long long rez,dp[DN];
stack<per> s;
char c;
string ss;

int main()
{
    ifstream f("paranteze2.in");
    ofstream g("paranteze2.out");
    f>>ss;
    for(int i=0; i<ss.size(); ++i) {
        c=ss[i];
        if(c=='(') s.push(mp(c,i));
        else {
            if(s.size()){
                per tp=s.top();
                if(tp.x=='(') {
                    cx[++sz]=tp.y;
                    cy[sz]=i;
                    s.pop();
                }else s.push(mp(c,i));
            }else s.push(mp(c,i));
        }
    }
    for(int i=1; i<=sz; ++i) dp[cy[i]]=dp[cx[i]-1]+1LL;
    for(int i=0; i<DN; ++i) rez+=dp[i];
    g<<rez;
    return 0;
}
