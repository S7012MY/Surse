#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

vector<string> aux;
  int ind[5005],gnr[5005];
  char s1[50005],s2[50005];

  bool cmp(const int i, const int j) {
    if(0==aux[i].compare(aux[j])) return gnr[i]<gnr[j];
    else return aux[i].compare(aux[j])<0;
  }

  int conv(string s, int p) {
    int rez=0;
    int i;
    for(i=p; i+1<(int)s.size(); ++i) {
      if(s[i]=='I') {
        if(s[i+1]=='V') rez+=4,++i;
        else if(s[i+1]=='X') rez+=9,++i;
        else if(s[i+1]=='L') rez+=49,++i;
        else ++rez;
      }else if(s[i]=='V') {
        if(s[i+1]=='L') rez+=45,++i;
        else rez+=5;
      }else if(s[i]=='X') {
        if(s[i+1]=='L') rez+=40,++i;
        else rez+=10;
      }else rez+=50;
    }
    if(i<s.size()) {
      if(s[i]=='I') ++rez;
      else if(s[i]=='V') rez+=5;
      else if(s[i]=='X') rez+=10;
      else rez+=50;
    }
    return rez;
  }
vector <string> rez;

  vector <string> getSortedList(vector <string> &kings) {
    //cout<<conv("IX",0);

    int n=kings.size();
    rez.resize(n);
    aux.resize(n);
    for(int i=0; i<n; ++i) {
      ind[i]=i;
      int j=0;
      for(;j<kings[i].size() && isalpha(kings[i][j]);aux[i]+=kings[i][j],++j);
      int nr=conv(kings[i],j+1);
      gnr[i]=nr;
      //cout<<aux[i]<<' '<<gnr[i]<<'\n';
    }
    sort(ind,ind+n,cmp);

    for(int i=0; i<n; ++i) rez[i]=kings[ind[i]];
    return rez;
  }
string s,sc;
vector<string> in,ou;
int ng;

int main() {
    ifstream f("kingsort.in");
    ofstream g("kingsort.out");
    getline(f,s);
    //cout<<s<<'\n';
    for(int i=0; i<s.size(); ++i) {
        if('"'==s[i]) {
            ++ng;
            if(!(ng&1)) {
                in.push_back(sc);
                sc.clear();
            }
        }else if(ng&1) sc+=s[i];
    }
        //cout<<"aici"; cout.flush();
   // for(int i=0; i<in.size(); ++i) cout<<in[i]<<' ';
   ou=getSortedList(in);
   g<<'{';
   if(ou.size()>=1) for(int i=0; i<ou.size()-1; ++i) g<<'"'<<ou[i]<<'"'<<", ";
   if(ou.size()>=1) g<<'"'<<ou[ou.size()-1]<<'"'<<'}';
}
