#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stack>
#define PLU (1<<30)+1
#define MIN (1<<30)+2
#define ORI (1<<30)+3
#define IMP (1<<30)+4
using namespace std;

string exp,s,f[26],p[26];
int vl[26],rez[255];

stack<char> st;

int prior(char s) {
    if(s=='+'||s=='-')return 1;
    if(s=='*')return 2;
    return 0;
}

void faPol(int unde,string s) {
    p[unde].clear();
    int i,n;
    n=s.size();
    for(i=0;i<n;++i){
        if(isalpha(s[i]) || isdigit(s[i]))p[unde]+=s[i];
        else if(s[i]=='(')st.push('(');
        else if(s[i]==')'){
            for(;st.top()!='(';st.pop()){
                p[unde]+=st.top();
            }
            st.pop();
        }
        else {
            for(;st.size()&&prior(s[i])<=prior(st.top());st.pop()){
                p[unde]+=st.top();
            }
            st.push(s[i]);
        }
    }
    for(;st.size();st.pop()){
        p[unde]+=st.top();
    }
}

int evalp(int unde,int vl[]) {
    int sz=0;
    string s=p[unde];
    for(int i=0; i<s.size();++i) {
        if(isalpha(s[i])) rez[++sz]=vl[s[i]-'a'];
        else if(isdigit(s[i])) rez[++sz]=s[i]-'0';
        else if('+'==s[i]) rez[sz-1]+=rez[sz],--sz;
        else if('-'==s[i]) rez[sz-1]-=rez[sz],--sz;
        else if('*'==s[i]) rez[sz-1]*=rez[sz],--sz;
    }
    return rez[1];
}

int evalf(int &unde) {
    char l=exp[unde]-'A';
    ++unde;
    int val[26],sz=0;
    for(int i=0; i<26; ++i) val[i]=0;
    for(;;++unde)
        if(isupper(exp[unde])) {
            val[sz]=evalf(unde);
            ++sz;
            --unde;
        }
        else if(islower(exp[unde])) {
            val[sz]=vl[exp[unde]-'a'];
            ++sz;
        }
        else if(isdigit(exp[unde])) {
            val[sz]=exp[unde]-'0';
            ++sz;
        }
        else if(')'==exp[unde]) {
            ++unde;
            break;
        }
    return evalp(l,val);
}

int main()
{
    ifstream fi("apel.in");
    ofstream g("apel.out");
    getline(fi,exp);
    for(;getline(fi,s);) {
        if(islower(s[0])) {
            int rez=0;
            for(int i=0; i<s.size(); ++i) if(isdigit(s[i])) rez=rez*10+s[i]-'0';
            vl[s[0]-'a']=rez;
        }else if(isupper(s[0])){
            int ok=0;
            for(int i=0; i<s.size(); ++i) {
                if(ok) f[s[0]-'A']+=s[i];
                if('='==s[i]) ok=1;
            }
            faPol(s[0]-'A',f[s[0]-'A']);
        }
    }
    int unde=0;
    g<<evalf(unde);
    return 0;
}
