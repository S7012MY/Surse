#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,v[10]={0,1,2,3,4,5,6,7,8,9},goal[10],s,f;
int si[10],sf[10];

queue<int> c;
map<int,int> pre;
map<int,char> pre2;
vector<char> sol;

int conv(int v[]) {
    int ret=0;
    for(int i=1; i<9; ++i) ret=ret*10+v[i];
    return ret;
}

void trans(int nr,int m[]) {
    for(int i=1; i<9; ++i) {
        m[9-i]=nr%10;
        nr/=10;
    }
    //for(int i=1; i<9; ++i) cout<<m[i]<<' ';
}

void t1(int si[],int sf[]) {
    for(int i=1; i<9; ++i) sf[9-i]=si[i];
    //for(int i=1; i<9; ++i) cout<<sf[i]<<' ';
}

void t2(int si[],int sf[]) {
    sf[1]=si[4];sf[2]=si[1]; sf[3]=si[2]; sf[4]=si[3];
    sf[8]=si[5]; sf[7]=si[8]; sf[6]=si[7]; sf[5]=si[6];
}

void t3(int si[], int sf[]) {
    sf[1]=si[1]; sf[4]=si[4]; sf[5]=si[5]; sf[8]=si[8];
    sf[2]=si[7]; sf[3]=si[2]; sf[6]=si[3]; sf[7]=si[6];
}

int main()
{
    ifstream fi("rubik.in");
    ofstream g("rubik.out");
    for(int i=1; i<9; ++i) fi>>goal[i];
    s=conv(v),f=conv(goal);
    pre[s]=0;
    for(c.push(s);c.size();c.pop()) {
        int fr=c.front();
        if(fr==f) {
            for(;pre[f];f=pre[f]) sol.push_back(pre2[f]);
        }
        trans(fr,si);

        t1(si,sf);
        int r=conv(sf);
        if(pre.find(r)==pre.end()) {
            pre[r]=fr;
            pre2[r]='A';
            c.push(r);
        }

        t2(si,sf);
        r=conv(sf);
        if(pre.find(r)==pre.end()) {
            pre[r]=fr;
            pre2[r]='B';
            c.push(r);
        }

        t3(si,sf);
        r=conv(sf);
        if(pre.find(r)==pre.end()) {
            pre[r]=fr;
            pre2[r]='C';
            c.push(r);
        }
    }
    reverse(sol.begin(),sol.end());
    g<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) g<<sol[i]<<'\n';
    return 0;
}
