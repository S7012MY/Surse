#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

/**
 *
 * Author : Petru Trîmbițaș
 *
 * This program implements the basic arithmetic operations: addition, subtraction, multiplication by one digit and division
 * by one digit in any base between 2 and 16. It can be extended to use any base smaller than 2^63-1;
 * It also converts the number from a source base to a destination base using the suitable method.
 *
 * Implementation details:
 * Internally the digits of a number are stored in reverse order, on position 0 will be the last digit of the number, on position 1
 * will be the next digit before the last one and so on.
 *
 * Example: 123 + 987
 * 321 +
 * 789
 * ---
 * 0111
 *  +++
 * The same method is applied for subtraction. For division and multiplication we perform the operations as we do on paper.
 * For conversions I use the methods presented at the course.
 *
 */

const int MAX_DIGITS=105;

inline int charToInt(char c) {
  if(isdigit(c)) return c-'0';
  if(isupper(c)) return 10+c-'A';
  if(islower(c)) return 10+c-'a';
  cerr<<"Error converting "<<c<<" to int\n";
  return 0;
}

inline char intToChar(int a) {
  if(a<10) return char(a+'0');
  if(a<16) return char(a-10+'A');
  cerr<<"Error converting "<<a<<" to char\n";
  return '0';
}

inline int groupLen(int a,int b) {
  //used for fast conversion from base a to b
  if(a>b) swap(a,b);
  int lg=1,p=a;
  for(;p<b;p*=a,++lg);
  return lg;

}

inline bool isP2(int x) {
  return (x&(x-1))==0;
}

inline bool isPowerOf(int a,int b) {
  //returns true if b=a^x
  int x;
  for(x=1; x<b; x*=a);
  if(x==b) return 1;
  return 0;
}

class number {
  private:
  int digits[MAX_DIGITS],base,length;
  public:
  number(string s,int base) {
    memset(digits,0,sizeof(digits));
    this->base=base;
    length=s.size();
    for(int i=0; i<length; ++i) digits[i]=charToInt(s[length-i-1]);
  }

  void print() {
    for(int i=length-1; i>=0; --i) cout<<intToChar(digits[i]);
    cout<<" ("<<base<<")";
  }

  bool isZero() {
    return length==1 && digits[0]==0;
  }

  void setZero() {
    length=1;
    memset(digits,0,sizeof(digits));
  }

  void rapidConversion(int tbase) {
    //tbase=base^x or base=tbase^x
    int rez[MAX_DIGITS];
    memset(rez,0,sizeof(rez));
    if(tbase<base) {
      int group=groupLen(base,tbase),poz=0;
      for(int i=0; i<length; ++i) {
        for(int j=0; j<group; ++j) {
          rez[poz++]=digits[i]%tbase;
          digits[i]/=tbase;
        }
      }
      length=poz;
      for(;length>1 && rez[length-1]==0;--length);
    }else {
      int group=groupLen(base,tbase),put=1;
      for(int i=0; i<length; ++i) {
        rez[i/group]+=(digits[i]*put);
        put*=base;
        if((i+1)%group==0) put=1;
      }
      length=length/group+(length%group>0);
    }
    memcpy(digits,rez,sizeof(rez));
  }

  void convert(int tbase) {
    if(isPowerOf(base,tbase) || isPowerOf(tbase,base)) {
      rapidConversion(tbase);
    }else {
      if(base<tbase) {
        //substitution method
        number rez("0",tbase),power("1",tbase);
        for(int i=0; i<length; ++i) {
          number aux=power;
          aux*=digits[i];
          rez+=aux;
          power*=base;
        }
        (*this)=rez;
      }else {
        //succesive divisions
        number rez=(*this);
        setZero();length=0;
        while(rez.isZero()==false) {
          digits[length++]=rez%tbase;
        }
      }
    }
    base=tbase;
  }

  void operator +=(number b) {
    int t,i;
    length=max(length,b.length);
    for(i=t=0; i<length; ++i) {
      digits[i]+=b.digits[i]+t;
      t=digits[i]/base;
      digits[i]%=base;
    }
    if(t) digits[length++]=t;
  }

  void operator -=(number b) {
    int i,t;
    for(i=t=0;i<length; ++i) {
      digits[i]-=(b.digits[i]+t);
      if(digits[i]<0) t=1;
      else t=0;
      if(t) digits[i]+=base;
    }
    for(;!digits[length-1];--length);
  }

  void operator *=(int x) {
    int i,t;
    for(i=t=0; i<length; ++i) {
      digits[i]=digits[i]*x+t;
      t=digits[i]/base;
      digits[i]%=base;
    }
    for(;t;digits[length++]=t%base,t/=base);
  }

  void operator /=(int x) {
    int r=0;
    for(int i=length-1;i>=0; --i) {
      r=base*r+digits[i];
      digits[i]=r/x;
      r%=x;
    }
    for(;!digits[length-1] && length>1; --length);
  }

  int operator %(int x) {
    int r=0;
    for(int i=length-1;i>=0; --i) {
      r=base*r+digits[i];
      digits[i]=r/x;
      r%=x;
    }
    for(;!digits[length-1] && length>1; --length);
    return r;
  }
};

int main()
{
  while(true) {
    cout<<"\nList of operations:\n";
    cout<<"(1) Add two numbers.\n";
    cout<<"(2) Subtract two numbers.\n";
    cout<<"(3) Multiplication by one digit.\n";
    cout<<"(4) Division by one digit.\n";
    cout<<"(5) Base conversion.\n";
    cout<<"(0) Exit.\n";
    int op; cin>>op;
    if(op==1) {
      cout<<"Enter the base of the numbers:\n";
      int base; cin>>base;
      if(base>16) {
        cout<<"Base must be smaller than 16.\n";
        continue;
      }
      cout<<"Enter the two numbers separated by spaces:\n";
      string a,b; cin>>a>>b;
      number x(a,base),y(b,base);
      x+=y;
      x.print();
      cout<<'\n';
    } else if(op==2) {
      cout<<"Enter the base of the numbers:\n";
      int base; cin>>base;
      if(base>16) {
        cout<<"Base must be smaller than 16.\n";
        continue;
      }
      cout<<"Enter the two numbers separated by spaces:\n";
      string a,b; cin>>a>>b;
      number x(a,base),y(b,base);
      x-=y;
      x.print();
      cout<<'\n';
    } else if (op==3) {
      cout<<"Enter the base of the numbers:\n";
      int base; cin>>base;
      if(base>16) {
        cout<<"Base must be smaller than 16.\n";
        continue;
      }
      cout<<"Enter the number and the digit separated by spaces:\n";
      string a; int d; cin>>a>>d;
      if(d>=base) {
        cout<<"Digit must be smaller than the base.\n";
        continue;
      }
      number x(a,base);
      x*=d;
      x.print();
      cout<<'\n';
    } else if(op==4){
      cout<<"Enter the base of the numbers:\n";
      int base; cin>>base;
      if(base>16) {
        cout<<"Base must be smaller than 16.\n";
        continue;
      }
      cout<<"Enter the number and the digit separated by spaces:\n";
      string a; int d; cin>>a>>d;
      if(d>=base) {
        cout<<"Digit must be smaller than the base.\n";
        continue;
      }
      number x(a,base);
      x/=d;
      x.print();
      cout<<'\n';
    }else if(op==5) {
      cout<<"It uses the optimal method for base conversions.\n";
      cout<<"Enter the number and the base in which the number is represented.\n";
      string a;int base; cin>>a>>base;
      number x(a,base);
      cout<<"Enter the target base";
      int tbase;cin>>tbase;
      x.convert(tbase);
      x.print();
      cout<<'\n';
    }
    else break;
  }
  return 0;
}
