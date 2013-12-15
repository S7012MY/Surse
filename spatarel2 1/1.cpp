#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	for(int i=1; i<2222222; ++i) next_permutation(a,a+10);
	for(int i=0; i<10; ++i) cout<<a[i]<<' ';
	return 0;
}