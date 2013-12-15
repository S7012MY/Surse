//#include <iostream>
//#include <cstring>
//#include <cstring>
//#include <algorithm>
//#define DN 105
//using namespace std;
//
//char a[DN],b[DN],v[DN];
//int la,lb,lv,bst[DN][DN][DN],rez,bk=-1;
//string sol;
//
//int main() {
//  cin>>(a+1)>>(b+1)>>(v+1);
//  la=strlen(a+1); lb=strlen(b+1); lv=strlen(v+1);
//  for(int i=1; i<=la; ++i) for(int j=1; j<=lb; ++j) for(int k=1; k<=lv; ++k)
//    if(a[i]==b[j]) {
//      if(a[i]==v[k]) {
//        bst[i][j][k]=max(bst[i][j][k],bst[i-1][j-1][k-1]+1);
//        bst[i][j][1]=max(bst[i][j][1],bst[i-1][j-1][0]+1);
//      }
//      else bst[i][j][0]=max(bst[i][j][0],bst[i-1][j-1][k-1]+1);
//    }else {
//      bst[i][j][k]=max(bst[i-1][j][k],bst[i][j-1][k]);
//      bst[i][j][0]=max(bst[i-1][j][0],bst[i][j-1][0]);
//    }
//  for(int k=0; k<lv; ++k) if(bst[la][lb][k]>rez) {
//    rez=bst[la][lb][k];
//    bk=k;
//  }
//  if(!rez) {
//    cout<<rez;
//    return 0;
//  }
//  for(;sol.size()<rez;) {
//    if(a[la]==b[lb]) {
//      sol+=a[la];
//      --la; --lb;
//      if(bk) --bk;
//    }else {
//      if(!la || bst[la-1][lb][bk]<bst[la][lb-1][bk]) --lb;
//      else --la;
//    }
//  }
//  reverse(sol.begin(),sol.end());
//  cout<<sol;
//}
