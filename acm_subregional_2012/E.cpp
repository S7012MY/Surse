/*#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char c[100005];
int d=-1,sz;
vector<int> v;

int solve() {
  int r=0,sum=0;
  sort(v.begin(),v.end());
  for(int i=0; i<v.size(); ++i) {
    sum+=v[i];
    if(sum<d) r+=(d-sum);
  }
  return r;
}

int main()
{
  int nr=0,ok=1;
  //freopen("inp.in","r",stdin);
  for(int i=5;;++i) {
    if(i>=sz) {
      if(ok){
        fread(c,100005,100005,stdin);
       // printf("%s\n----\n",c);
        sz=strlen(c);
        c[sz]='\n';
        sz=strlen(c);
        if(sz==0) break;
        i=0;
      }else {
        break;
      }
    }
    if(nr==0 && c[i]=='\n' && d!=-1) {
      printf("Ben can earn %d points!\n",solve());
      d=-1;
      nr=0;
      v.clear();
    }else if(c[i]=='\n') {
      if(d==-1) d=nr;
      else v.push_back(nr);
      nr=0;
    }else if(isdigit(c[i])) {
      nr=nr*10+c[i]-'0';
    }
    if(feof(stdin)) ok=0;
   // if(d==-1 && i>=sz) break;
  }
}
*/
