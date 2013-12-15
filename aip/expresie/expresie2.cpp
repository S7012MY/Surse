// expresie - varainta 2 			© stelian ciurea
// 100 cu prelucrari succesive de siruri aflate intre paranteze
#include <fstream>
#include <iostream>
#include <string>
#define nmax 100001
using namespace std;

string s,s1;
int i, poz;
char lit;
ifstream f("expresie.in");
ofstream g("expresie.out");
int apare[150];

string initial(string s)
{
	string s1;
	int i, len = s.size();
	for (i=0;i<len;i++)
		if (s[i]>='a' && s[i]<='z')
		{
			s1 = s1 + s[i] + "+1";
			apare[s[i]] = 0;
		}
		else
			s1 = s1+s[i];
	return s1;
}

string transform(string s) //transofrma o expresie fara paranteze cu / si * intr-una de tip produs 
{
	short int ct[150];
	int i,j,len,semn=1,numar=0,semnnum;
	string s1;
	char lit,buf[10];
	
	for (i='a';i<='z';i++)
		ct[i]=0;
	
	len = s.size();
	for(i=0;i<len;i++)
	{
		if (s[i]=='-')
			semnnum=-1;
		if (s[i]=='+')
			semnnum=+1;
		if (s[i]=='/')
		{
			ct[lit] += semn*semnnum*numar;
			semn = -1;
			numar=0;
		}
		if (s[i]=='*')
		{
			ct[lit] += semn*semnnum*numar;
			semn = +1;
			numar=0;
		}
		if (s[i]<='z' && s[i] >='a')
		{
			ct[lit] += semn*semnnum*numar;
			numar=0;
			lit = s[i];
		}
		if (s[i]>='0'&&s[i]<='9')
			numar = 10*numar + (s[i]-48);
	}
	ct[lit] += semn*semnnum*numar;
	for (lit='a';lit<='z';lit++)
		if (ct[lit]!=0)
		{
		s1 = s1 + lit;
		ltoa(ct[lit],buf,10);
		if (ct[lit] >= 0)
			s1 = s1 + '+' + buf;
		else
			s1=s1+buf;
		}
	return s1;
}
		

int main()
{

	for (i=0;i<150;i++)
		apare[i] = -1000000000;
	//s = "a*(b/(c/d))";
	f >> s;
	s = initial(s);
	//cout << s << endl;
	while ((poz = s.find(')')) >=0)
	{
		for(i=poz-1;i>=0;i--)
			if (s[i]=='(' )
				break;
		s1 = s.substr(i+1,poz-1-(i+1)+1);
		//cout << s1 << endl;
		s1 = transform(s1);
		//cout << s1 << endl;
		s.erase(i,poz-i+1);
		//cout << s << endl;
		s.insert(i,s1);
		//cout << s << endl;
		//system("PAUSE");
		//cout << endl;
	}
	
	s = transform(s);
	
	//cout << s << endl;
	
	int len = s.size();
	int numar = 0;
	int semn;
	for (i=0;i<len;i++)
	{
		if (s[i]>='a' && s[i] <='z')
		{
			apare[lit] = semn*numar;
			numar=0;
			lit = s[i];
		}
		if (s[i]=='+')
			semn = +1;
		if (s[i]=='-')
			semn=-1;
		if (s[i]>='0' && s[i] <='9')
			numar = 10*numar + (s[i]-48);
	}
	apare[lit] = semn*numar;
	
	for (lit='a';lit<='z';lit++)
		if (apare[lit]>-1000000000)
		{
			cout << lit << ' ' << apare[lit] << endl;
			g << lit << ' ' << apare[lit] << endl;
		}
	return 0;
}
