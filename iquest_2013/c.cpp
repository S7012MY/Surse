//#include <iostream>
//#include <string>
//#include <set>
//#include <cctype>
//#define DN  25005
//using namespace std;
//
// set<int> v;
//
//int output(string exp,string &out) {
//    char stk[DN];
//    int lgex=exp.size(),lgo=0,lgs=0;
//
//    for (int i=0; i < lgex; ++ i) {
//        if(exp[i]=='(') stk[lgs ++]=exp[i];
//        if(exp[i]==')') {
//                while (stk[lgs - 1] != '(')
//                    out+=stk[-- lgs];
//                lgs --;
//        }
//        if(exp[i]=='!')
//                stk[lgs ++]='~';
//        if(exp[i]=='&') {
//                while ((lgs > 0) && (stk[lgs - 1] == '~'))
//                    out+=stk[-- lgs];
//                stk[lgs ++]=exp[i];
//        }
//        if(exp[i]=='^') {
//                while ((lgs > 0) && (stk[lgs - 1] == '~' || stk[lgs - 1] == '&'))
//                    out+=stk[-- lgs];
//                stk[lgs ++]=exp[i];
//        }
//        if(exp[i]=='|') {
//                while ((lgs > 0) && (stk[lgs - 1] == '~' || stk[lgs - 1] == '&') || (stk[lgs - 1] == '^'))
//                    out+=stk[-- lgs];
//                stk[lgs ++]=exp[i];
//        }
//       if(isupper(exp[i])) {
//                out+=exp[i];
//                v.insert(exp[i]);
//       }
//    }
//    while (lgs > 0)
//        out+=stk[-- lgs];
//    return out.size();
//}
//
//int ans[DN];
//
//int evaluate(string out, int lgo, int valori[]) {
//    int ans_len=0;
//
//    for (int i=0; i < lgo; ++ i) {
//        switch (out[i]) {
//            case '~':
//                ans[ans_len - 1] ^= 1;
//                break ;
//            case '&':
//                ans[ans_len - 2]=ans[ans_len - 2] & ans[ans_len - 1];
//                ans_len --;
//                break ;
//            case '^':
//                ans[ans_len - 2]=ans[ans_len - 2] ^ ans[ans_len - 1];
//                ans_len --;
//                break ;
//            case '|':
//                ans[ans_len - 2]=ans[ans_len - 2] | ans[ans_len - 1];
//                ans_len --;
//                break ;
//            default:
//                ans[ans_len ++]=valori[out[i] - 'A'];
//               // for(int i=0; i<ans_len; ++i) cout<<ans[i]<<' ';
//        }
//    }
//   /// cout<<'\n';
//    return ans[0];
//}
//
//string exp,out;
//int valori[206];
//
//int main() {
//  getline(cin,exp);
//  int lg=output(exp,out);
//  //cout<<out<<' ';
//  int d=v.size();
//  for(int i=0; i<(1<<d); ++i) {
//    for(int j=0; j<d; ++j) {
//      if(i&(1<<j)) valori[j]=1;
//      else valori[j]=0;
//    }
//    if(evaluate(out,lg,valori)) {
//      cout<<"(";
//      for(int j=0; j<d-1; ++j) cout<<valori[j]<<',';
//      cout<<valori[d-1]<<")";
//      if(i!=(1<<d)-1) cout<<" ";
//    }
//  }
//}
