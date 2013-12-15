#include <iostream>
#include <string>
using namespace std;

string s;
int fz=-1;

int main()
{
  cin>>s;
    for(int i=0; i<s.size(); ++i) if(s[i]=='0' && fz==-1) fz=i;
    int lm=s.size();
    if(fz==-1) --lm;
    for(int i=0; i<lm; ++i) if(i!=fz) cout<<s[i];
    return 0;
}
