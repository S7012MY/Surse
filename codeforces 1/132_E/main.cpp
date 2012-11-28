#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long l,d,cnt;

int nrdiv(int n) {
    int ret=0;
    for(int i=1; i<n; ++i) if(0==n%i) ++ret;
    return ret;
}

int main()
{
    cin>>l>>d;
    int bit=0;
    //for(bit=0;;++bit) if((1<<bit)<=l && (1<<(bit+1)>l)) break;
    for(;bit<64; ++bit) {
        //cout<<bit<<'\n';
       // long long dpb1=(1LL<<(bit+1));
        //if(dpb1-1<=d && (1LL<<bit)>=l) cnt+=(1<<nrdiv(bit+1));
       // else {
            //cout<<"aici\n";
            for(int i=1; i<=bit; ++i) if((bit+1)%i==0) {
                string s="";
                if(i==1) for(int i=0; i<=bit; ++i) s+='1';
                else {
                    for(int j=0; j<=bit; ++j)
                        if((j+1)%i==1) s+='1';
                        else s+='0';
                }
               // cout<<i<<' '<<s<<' ';
                reverse(s.begin(),s.end());
                long long nr=0;
                for(int i=0; i<s.size(); ++i) if('1'==s[i]) nr+=(1LL<<i);
                if(nr>=l && nr<=d) {
                    ++cnt;
                    cout<<nr<<' ';
                }
            }
        //}
    }
    cout<<cnt;
    return 0;
}
