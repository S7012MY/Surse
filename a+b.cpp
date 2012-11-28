#include <fstream>
using namespace std;

int a,b;

int main(){
	ifstream f("adunare.in");
	ofstream g("adunare.out");
	scanf("%d %d",&a,&b);
	printf("%d",a+b);
	return 0;
}
