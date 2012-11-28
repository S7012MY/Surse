#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

set<string> d;

string t,cv,ct;
int g,ok;

int main()
{
    for(;;) {
        cin>>t;
        if(t.compare("#")==0) break;
        d.insert(t);
    }
    cin.get();
    for(;!cin.eof();) {
    	getline(cin,t);
    	for(int i=0; i<t.size(); ++i) {
    	    ok=1;
    	    if(isalpha(t[i])) cv+=t[i];
    	    else {
    	        if(d.find(cv)!=d.end());// cout<<cv;
    	        else {
    	            ct=cv;
                    for(int i=0; i<ct.size() && ok; ++i) {
                        for(char c='a'; c<='z'; ++c) {
                            ct[i]=c;
                            if(d.find(ct)!=d.end()) {
                                if(ct.compare(cv)!=0) ++g;
                                cout<<ct;
                                ok=0;
                                continue;
                            }
                        }
                        ct[i]=cv[i];
                    }
    	        }
    	        if(ok) cout<<cv;
    	        cv.clear();
    	        cout<<t[i];
    	    }
    	}
    	cout<<'\n';
    }
    cout<<g;
    return 0;
}
