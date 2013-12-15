#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#define DN 1130005
using namespace std;

int n,sz,msk;
char sol[DN];
vector<int> gr[DN];
stack<int> st;

int lst=-1;

inline void euler() {
    int s,i;
    START:
    for(;gr[s].size();) {
        i=gr[s].back();
        gr[s].pop_back();
        st.push(s);
        s=i;
        goto START;
        RETURN:
        ;
    }
    if(lst!=-1)
        sol[++sz]=(lst&1)+'0';
    lst=s;
    if(st.empty())
        return;
    s=st.top();
    st.pop();
    goto RETURN;
}

int main()
{
    ifstream f("biti.in");
    ofstream g("biti.out");
    f>>n;
    if(n==1) {
        g<<"2\n01";
        return 0;
    }
    --n;
    msk=(1<<n)-1;
    for(int i=0; i<=msk; ++i) {
        int nn=((i<<1)&msk);
        gr[i].push_back(nn+1);
        gr[i].push_back(nn);
    }
    euler();
    for(int i=1; i<=n; ++i) sol[++sz]='0';
    reverse(sol+1,sol+sz+1);
    g<<sz<<'\n'<<sol+1;
    return 0;
}
