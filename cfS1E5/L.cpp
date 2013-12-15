//#include <cstdio>
//#include <string>
//#include <map>
//#include <iostream>
//using namespace std;
//
//
//
//int main() {
//  int n,m,t;
//  scanf("%d\n",&t);
//  while(t--) {
//    string a,b,r;
//    map<string,int> votes;
//    map<string,string> party;
//    scanf("%d\n",&n);
//    for(int i=0; i<n; ++i) {
//      char a[100],b[100];
//      gets(a); gets(b);
//     // cerr<<a<<' '<<b<<'\n';
//      party[a]=b;
//    }
//    scanf("%d\n",&m);
//    //cerr<<m<<' ';
//    for(int i=0; i<m; ++i) {
//     // cerr<<"aici";
//      char a[100];
//      gets(a);
//      ++votes[a];
//    }
//    votes[r]=0;
//    int eg=1;
//    for(map<string,string>::iterator im=party.begin(); im!=party.end(); ++im) {
//      if(votes.find(im->first)!=votes.end() && votes[im->first]>votes[r]) {
//        eg=0;
//        r=im->first;
//      }
//      else if(votes.find(im->first)!=votes.end() && votes[im->first]==votes[r] && r.compare(im->first)) eg=1;
//    }
//    if(!eg) cout<<party[r]<<'\n';
//    else cout<<"tie\n";
//    cout<<"\n";
//  }
//}
