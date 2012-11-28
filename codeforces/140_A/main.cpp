#include <iostream>
#define x first
#define y second
using namespace std;

int n;

typedef pair<double,double> per;

per a,b,c;

int  id(const per &a,const per &b, const per &c) {
	//| b.x b.y 1 |
	//| c.x c.y 1 |
	//| a.x a.y 1 |
	double sum=b.x*c.y+c.x*a.y+a.x*b.y;
	double dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	if ((sum+dif)<0.0) return 0;
	else if(sum+dif==0) return 1;
	return 2;
}

int main()
{
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    if(id(a,b,c)==0) cout<<"RIGHT";
    else if(id(a,b,c)<2) cout<<"TOWARDS";
    else cout<<"LEFT";
    return 0;
}
