#include <iostream>
#include <vector>
#include <string>
#define DN 1000005
using namespace std;

string s;
int n,viz[DN];
vector<int> a;

long long abs(long long x) {
  if(x>0) return x;
  return -x;
}

void expand(int a,int b) {
  for(;a>=0 && b<s.size() && s[a]==s[b];--a,++b) {
    viz[a]=viz[b]=1;
    for(;a && s[a-1]==s[a];--a,viz[a]=1);
    for(;b<s.size()-1 && s[b+1]==s[b];++b,viz[b]=1);
  }
}

int main()
{
 // long long a,b;
   // cin>>a>>b;
    //if(a==1 && b==1) cout<<1;
    //else cout<<max(a,b)-abs(b-a)+1;
    cin>>s;
    for(int i=1; i<s.size(); ++i) if(s[i]==s[i-1] && !viz[i]) expand(i-1,i);
    for(int i=0; i<s.size(); ++i) if(!viz[i] && s[i]=='-') {
      cout<<"No";return 0;
    }
    cout<<"Yes";
    return 0;
}
