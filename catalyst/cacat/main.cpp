#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define x first
#define y second
#define LL long long
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;

multimap<string, char> mp;
set<string> dict;
multimap<string,string> syl;
vector<string> syls;
set<string> dictp[100];

ifstream f("input.txt");
ofstream g("output.txt");
ofstream deb("tst.txt");

void readTdata() {
    ifstream tdata("trainingdata");
    int numLit;
    tdata>>numLit;
    char lit;
    string mopoz;
    mopoz="AAAA";
    for(int i=1; i<=numLit; ++i) {
        tdata>>lit>>mopoz[0]>>mopoz[1]>>mopoz[2]>>mopoz[3];
        mp.insert(make_pair(mopoz,lit));
    }
}

void readDict() {
    ifstream f("dictionary");
    string g;
    for(;!f.eof();) {
        getline(f,g);
        string pre;
        for(int i=0; i<=55 && i<g.size(); ++i) {
            pre+=g[i];
            dictp[i+1].insert(pre);
            dictp[i+1].insert("");
        }
        dict.insert(g);
    }
}

void readSyl() {
    ifstream f("sylabes");
    string a,eg,b;
    for(;!f.eof();) {
        if(f.good()) {
            f>>a>>eg>>b;
            //syl.insert(make_pair(a,b));
            syl.insert(make_pair(b,a));
            syls.push_back(a);
        }
        f.get();
    }
    syls.pop_back();
}

set<char> mopoztoChars(string mopoz) {
    set<char> sol;
    multimap<string,char>::iterator it;
    it=mp.find(mopoz);
    for(;it!=mp.end() && it->first.compare(mopoz)==0;++it) sol.insert(it->second);

    return sol;
}

set<char> lits[5005];
set<string> detWord;

void back(int p,string word,int numLit,string pref) {
        //deb<<p<<' '<<word<<' '<<numLit<<'\n';
    //if(p!=13) cout<<p<<'\n';
    if(p>numLit+1) return;
    if(p==numLit+1) {
        if(dict.find(word)!=dict.end()) detWord.insert(word);

        for(int lg=1; lg<3; ++lg) {
            string nxword="",suf="",wback="";
            for(int i=0; i<word.size(); ++i)
                if(word.size()-lg<=i) suf+=word[i];
                else nxword+=word[i];
            for(multimap<string,string>::iterator im=syl.find(suf); im!=syl.end() && im->x.compare(suf)==0; ++im) {
                wback.clear();
                wback=nxword;
                wback.append(im->y);
               // deb<<nxword<<' '<<suf<<' '<<wback<<'\n';
                if(dict.find(wback)!=dict.end()) detWord.insert(wback);
            }
        }
        return;
    }
    if(p>1) pref+=word[pref.size()];
    //pref="";
    //for(int i=0; i-2<word.size(); ++i) pref+=word[i];
   // deb<<pref<<' ';
    word+=' ';
    int ok=1;
    for(set<char>::iterator ie=lits[p].begin(); ie!=lits[p].end(); ++ie) {
        word[word.size()-1]=*ie;
        for(int lg=1; lg<3; ++lg) {
            string nxword="",suf,wback;
            for(int i=0; i<word.size(); ++i)
                if(word.size()-lg<=i) suf+=word[i];
                else nxword+=word[i];
            for(multimap<string,string>::iterator im=syl.find(suf); im!=syl.end() && im->x.compare(suf)==0; ++im) {
                wback.clear();
                wback=nxword;
                wback.append(im->y);
                //deb<<nxword<<' '<<suf<<' '<<wback<<'\n';
                back(p+1,wback,numLit,pref);
            }
        }
        size_t poz;
        for(int i=0; i<syls.size(); ++i) {
            poz=word.rfind(syls[i]);
            if(poz!=string::npos && int(poz)+syls[i].size()==word.size()) {
                ok=0;
                break;
            }
        }
        if(ok && (dictp[pref.size()].find(pref)!=dictp[pref.size()].end() || pref.compare("")==0))
            back(p+1,word,numLit,pref);
        ok=1;
    }
}

void getWord() {
    int numLit;
    f>>numLit;
    string mopoz;
    mopoz="AAAA";
    for(int i=1; i<=numLit; ++i) {
        f>>mopoz[0]>>mopoz[1]>>mopoz[2]>>mopoz[3];
        lits[i]=mopoztoChars(mopoz);
    }
    string s="";
    back(1,s,numLit,"");
    for(int i=1; i<=numLit; ++i) lits[i].clear();
}

void getWords() {
    int tst;
    for(f>>tst; tst; --tst) {
        getWord();
        g<<detWord.size()<<' ';
        for(set<string>::iterator ie=detWord.begin(); ie!=detWord.end(); ++ie) g<<*ie<<' ';
        detWord.clear();
    }
}

double findSyl(string s) {
    int cnt=0;
    size_t found=-1;
    int amsil=0;
    for(int i=0 ;i<syls.size(); ++i) if(s.find(syls[i])!=string::npos) amsil=1;
    for(set<string>::iterator i=dict.begin(); i!=dict.end(); ++i) {
        for(;(*i).find(s,found+1)!=string::npos;) {
            int ok=1;
            found=(*i).find(s,found+1);
            for(int j=0; j<syls.size(); ++j) {
                size_t fs=(*i).find(syls[j],found+1);
                if(fs!=string::npos && fs<=found+s.s    ize()-1 && fs>found) ok=0;
                fs=(*i).find(syls[j],found-syls.size()+1);
                if(fs!=string::npos && fs+syls.size()>found && fs<found) ok=0;
            }
            if(ok)++cnt;
        }
        found=-1;
    }
    return cnt;
}

string a[10],b[10];
double bun[10],found[10];

void getNumSyls() {
    int tst;
    //cout<<findSyl("ar")<<'\n';
    //cout<<findSyl("cian")+findSyl("s")<<'\n';
    double napar;
    string psil;
    f>>tst;
    double diff=9999999,nbun;
    for(int j=1; j<=tst; ++j) {
        f>>a[j]>>b[j];
        psil=a[j];
        psil.append(b[j]);
        found[j]=findSyl(psil);
        /*psil=b[j];
        psil.append(a[j]);
        found[j]+=findSyl(psil);*/
        //cout<<found[j]<<' ';
    }
    for(int j=1; j<=tst; ++j) {
        f>>bun[j];
        //cout<<bun[j]<<' ';
    }
    for(double num=0; num<=40000000; ++num) {
        //cout<<num<<' '; cout.flush();
        double maxd=0;
        for(int j=1; j<=tst; ++j) {

            double nr=found[j]/num;
            nr=fabs(nr-bun[j]);
            if(maxd<nr) maxd=nr;
        }
        if(maxd<diff) {
            diff=maxd;
            nbun=num;
        }
    }
    for(int j=1; j<=tst; ++j) {
        double nr=found[j]/nbun;
        cout<<fixed<<setprecision(9)<<nr<<' ';
    }
    //cout<<nbun;
    //for(int i=0; i<syls.size(); ++i) cout<<syls[i]<<' ';

}

int main() {
    readTdata();
    readDict();
    readSyl();
    //getWords();
    getNumSyls();
}
