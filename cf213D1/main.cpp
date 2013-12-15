#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define DN 4005
using namespace std;

int a,sp[DN];
string s;
unordered_map<int,int> fr;
long long rez;
unordered_set<int> z;

int main()
{
    cin>>a>>s;
    int n=s.size();
    for(int i=0; i<s.size(); ++i) sp[i+1]=sp[i]+(s[i]-'0');
    for(int i=1; i<=n; ++i) for(int j=i; j<=n; ++j) {
      int sum=sp[j]-sp[i-1];
      if(fr.find(sum)==fr.end()) fr[sum]=1;
      else ++fr[sum];
    }
    if(a==0) {
      for(int i=1; i<=n; ++i) for(int j=i; j<=n; ++j) {
        int sum=sp[j]-sp[i-1];
        if(z.find(sum)!=z.end()) continue;
        z.insert(sum);
        rez+=(fr[0]*1LL*fr[sum]);
        rez+=(fr[sum]*1LL*fr[0]);
      }
      cout<<rez;
      return 0;
    }
    for(int i=1; i<=n; ++i) for(int j=i; j<=n; ++j) {
      int sum=sp[j]-sp[i-1];
      if(sum==0) continue;
      if(z.find(sum)!=z.end()) continue;
      z.insert(sum);
      if(a%sum==0) {
       // cout<<sum<<' '<<fr[sum]<<' '<<fr[a/sum]<<'\n';
        rez+=(fr[sum]*1LL*fr[a/sum]);
      }
    }
    cout<<rez;
    return 0;
}
