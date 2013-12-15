#include<fstream>
#include<iostream>
using namespace std;

ifstream f("inversiuni.in");

int N;
int secv[10009];

bool read()
{	if(!(f>>N)) return 0;
	for(int i = 1; i <= N; i++) f>>secv[i];
	return 1;
}

int count()
{	int ans = 0;
	int i, j;
	
	for(i = 1; i <= N; i++)
		for(j = i + 1; j <= N; j++)
			if(secv[i] > secv[j]) ans++;
	
	return ans;
}

int main()
{	int i, j,nrc;
	ifstream g("inversiuni.out");
	while(read()) {
		g>>nrc;
		if(nrc!=count()) {
			cout<<"gresit";
			while(1);
		}else cout<<"OK!";
	}
	
	f.close();
	g.close();
	return 0;
}
